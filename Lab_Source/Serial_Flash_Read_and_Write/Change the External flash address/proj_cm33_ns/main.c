/*******************************************************************************
 * File Name        : main.c
 *
 * Description      : This source file contains the main routine for non-secure
 *                    application in the CM33 CPU
 *
 * Related Document : See README.md
 *
 *******************************************************************************
 * Copyright 2023-2025, Cypress Semiconductor Corporation (an Infineon company) or
 * an affiliate of Cypress Semiconductor Corporation.  All rights reserved.
 *
 * This software, including source code, documentation and related
 * materials ("Software") is owned by Cypress Semiconductor Corporation
 * or one of its affiliates ("Cypress") and is protected by and subject to
 * worldwide patent protection (United States and foreign),
 * United States copyright laws and international treaty provisions.
 * Therefore, you may use this Software only as provided in the license
 * agreement accompanying the software package from which you
 * obtained this Software ("EULA").
 * If no EULA applies, Cypress hereby grants you a personal, non-exclusive,
 * non-transferable license to copy, modify, and compile the Software
 * source code solely for use in connection with Cypress's
 * integrated circuit products.  Any reproduction, modification, translation,
 * compilation, or representation of this Software except as specified
 * above is prohibited without the express written permission of Cypress.
 *
 * Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. Cypress
 * reserves the right to make changes to the Software without notice. Cypress
 * does not assume any liability arising out of the application or use of the
 * Software or any product or circuit described in the Software. Cypress does
 * not authorize its products for use in any products where a malfunction or
 * failure of the Cypress product may reasonably be expected to result in
 * significant property damage, injury or death ("High Risk Product"). By
 * including Cypress's product in a High Risk Product, the manufacturer
 * of such system or application assumes all risk of such use and in doing
 * so agrees to indemnify Cypress against all liability.
 ******************************************************************************/

/*******************************************************************************
 * Header Files
 ******************************************************************************/
#include "cybsp.h"
#include "retarget_io_init.h"
#include "cycfg_qspi_memslot.h"
#include "mtb_serial_memory.h"
#include <inttypes.h>
#include <string.h>

/*******************************************************************************
 * Macros
 ******************************************************************************/
/* The timeout value in microsecond used to wait for the CM55 core to be booted.
 * Use value 0U for infinite wait till the core is booted successfully.
 */
#define CM55_BOOT_WAIT_TIME_USEC            (10U)

/* App boot address for CM55 project */
#define CM55_APP_BOOT_ADDR                  (CYMEM_CM33_0_m55_nvm_START + \
                                                CYBSP_MCUBOOT_HEADER_SIZE)

/* LED blink delay */
#define LED_TOGGLE_DELAY_MSEC               (1000U)

/* Memory Read/Write size */
#define PACKET_SIZE                         (64U)

/* Used when array of data is printed on the console */
#define NUM_BYTES_PER_LINE                  (16U)

/* Slot number of the memory to use */
#define MEM_SLOT_NUM                        (0U)      
#define MEM_SLOT_DIVIDER                    (2U)
#define MEM_SLOT_MULTIPLIER                 (2U)

/* 100 MHz interface clock frequency */
#define QSPI_BUS_FREQUENCY_HZ               (100000000Ul)

/* Flash data after erase */
#define FLASH_DATA_AFTER_ERASE              (0xFFU)

/* 1 ms timeout for all blocking functions */
#define TIMEOUT_1_MS                        (1000U)   

#define SUCCESS_STATUS                      (0U)
#define ARR_PRINT_LINE_CHECK                (0U)
#define ARR_PRINT_LINE_DIVIDER              (1U)

/*******************************************************************************
 * Global Variables
 ******************************************************************************/
/* Objects for serial memory middleware */
static mtb_serial_memory_t serial_memory_obj;
static cy_stc_smif_mem_context_t smif_mem_context;
static cy_stc_smif_mem_info_t smif_mem_info;

/*******************************************************************************
 * Function Definitions
 ******************************************************************************/
/*******************************************************************************
 * Function Name: check_status
 *******************************************************************************
 *
 * Summary:
 *  Prints the message, indicates the non-zero status by turning the LED on, and
 *  asserts the non-zero status.
 *
 * Parameters:
 *  message - message to print if status is non-zero.
 *  status - status for evaluation.
 *
 * Return:
 *  void
 *
 ******************************************************************************/
static void check_status(char *message, uint32_t status)
{
    if (SUCCESS_STATUS != status)
    {
        printf("\r\n=====================================================\r\n");
        printf("\nFAIL: %s\r\n", message);
        printf("Error Code: 0x%08"PRIX32"\n", status);
        printf("\r\n=====================================================\r\n");

        /* On failure, turn the LED ON */
        Cy_GPIO_Set(CYBSP_USER_LED1_PORT, CYBSP_USER_LED1_PIN);
        /* Wait forever here when the error occurs. */
        while(true);
    }
}

/*******************************************************************************
 * Function Name: print_array
 *******************************************************************************
 *
 * Summary:
 *  Prints the content of the buffer to the UART console.
 *
 * Parameters:
 *  message - message to print before array output.
 *  buf - buffer to print on the console.
 *  size - size of the buffer.
 *
 * Return:
 *  void
 *
 ******************************************************************************/
static void print_array(char *message, uint8_t *buf, uint32_t size)
{
    printf("\r\n%s (%"PRIu32" bytes):\r\n", message, size);
    printf("-------------------------\r\n");

    for (uint32_t index = 0; index < size; index++)
    {
        printf("0x%02X ", buf[index]);

        if (ARR_PRINT_LINE_CHECK == 
            ((index + ARR_PRINT_LINE_DIVIDER) % NUM_BYTES_PER_LINE))
        {
            printf("\r\n");
        }
    }
}

/*******************************************************************************
 * Function Name: main
 *******************************************************************************
 *
 * Summary:
 * This is the main function of the CM33 non-secure application.
 *
 * It initializes retarget-io to prints on debug port, enables CM55 core and
 * carries out SMIF read-write related operations.
 *
 * Parameters:
 *  none
 *
 * Return:
 *  int
 *
 ******************************************************************************/
int main(void)
{
    cy_rslt_t result;
    uint8_t tx_buf[PACKET_SIZE];
    uint8_t rx_buf[PACKET_SIZE];
    uint32_t ext_mem_address;
    size_t sectorSize;

    /* Initialize the device and board peripherals */
    result = cybsp_init();

    /* Board init failed. Stop program execution */
    if (CY_RSLT_SUCCESS != result)
    {
        handle_app_error();
    }

    /* Enable global interrupts */
    __enable_irq();

    /* Initialize retarget-io middleware */
    init_retarget_io();

    /* \x1b[2J\x1b[;H - ANSI ESC sequence for clear screen */
    printf("\x1b[2J\x1b[;H");

    printf("************** ");
    printf("PSOC Edge MCU: Serial Flash Read and Write Test");
    printf("**************\r\n");

    /* Set-up serial memory. */
    result = mtb_serial_memory_setup(&serial_memory_obj, 
                                MTB_SERIAL_MEMORY_CHIP_SELECT_1, 
                                CYBSP_SMIF_CORE_0_XSPI_FLASH_hal_config.base,
                                CYBSP_SMIF_CORE_0_XSPI_FLASH_hal_config.clock,
                                &smif_mem_context, 
                                &smif_mem_info,
                                &smif0BlockConfig);

	check_status("Serial memory setup failed", result);
	
	/* Use custom address for flash operations */
	ext_mem_address = 0xB00000;
	
	sectorSize = mtb_serial_memory_get_erase_size(&serial_memory_obj, 
	                                                ext_mem_address);
    printf("\r\nTotal Flash Size: %u bytes\r\n",
            mtb_serial_memory_get_size(&serial_memory_obj));

    /* Erase before write */
    printf("\r\n1. Erasing %u bytes from offset address 0x%"PRIx32"\r\n", 
            sectorSize, ext_mem_address);

    result = mtb_serial_memory_erase(&serial_memory_obj, 
                                    ext_mem_address, 
                                    sectorSize);

    check_status("Erasing memory failed", result);

    /* Read after Erase to confirm that all data is 0xFF */
    printf("\r\n2. Reading after Erase & verifying that each byte is 0xFF\r\n");
    
    result = mtb_serial_memory_read(&serial_memory_obj, 
                                    ext_mem_address, 
                                    PACKET_SIZE, 
                                    rx_buf);

    check_status("Reading memory failed", result);
    
    print_array("Received Data", rx_buf, PACKET_SIZE);
    
    memset(tx_buf, FLASH_DATA_AFTER_ERASE, PACKET_SIZE);
    
    check_status("Flash contains data other than 0xFF after erase",
                    memcmp(tx_buf, rx_buf, PACKET_SIZE));

    /* Prepare the TX buffer */
    for (uint32_t index = 0; index < PACKET_SIZE; index++)
    {
        tx_buf[index] = (uint8_t)index;
    }

    /* Write the content of the TX buffer to the memory */
    printf("\r\n3. Writing data to offset address 0x%"PRIx32"\r\n", 
                                                    ext_mem_address);
    
    result = mtb_serial_memory_write(&serial_memory_obj, 
                                    ext_mem_address, 
                                    PACKET_SIZE, 
                                    tx_buf);

    check_status("Writing to memory failed", result);
    
    print_array("Written Data", tx_buf, PACKET_SIZE);

    /* Read back after Write for verification */
    printf("\r\n4. Reading back for verification\r\n");
    
    result = mtb_serial_memory_read(&serial_memory_obj, 
                                    ext_mem_address, 
                                    PACKET_SIZE, 
                                    rx_buf);
    
    check_status("Reading memory failed", result);
    
    print_array("Received Data", rx_buf, PACKET_SIZE);

    /* Check if the transmitted and received arrays are equal */
    check_status("Read data does not match with written data. Read/Write "
            "operation failed.", memcmp(tx_buf, rx_buf, PACKET_SIZE));

    printf("\r\n=========================================================\r\n");
    printf("\r\nSUCCESS: Read data matches with written data!\r\n");
    printf("\r\n=========================================================\r\n");

    /* Enable CM55. */
    /* CM55_APP_BOOT_ADDR must be updated if CM55 memory layout is changed.*/
    Cy_SysEnableCM55(MXCM55, CM55_APP_BOOT_ADDR, CM55_BOOT_WAIT_TIME_USEC);

    for (;;)
    {
        Cy_GPIO_Inv(CYBSP_USER_LED1_PORT, CYBSP_USER_LED1_PIN);
        Cy_SysLib_Delay(LED_TOGGLE_DELAY_MSEC);
    }
}

/* [] END OF FILE */

---
title: "Chapter 1: Introduction"
---

# Chapter 1: Introduction

### About this document

## Scope and purpose

This document is the training manual for the technical introduction to PSOC™ Edge E84 features. This manual helps in getting started with different applications leveraging key features for PSOC™ Edge, using ModusToolbox™ software.

The training is divided into multiple chapters covering topics like audio, graphics, machine learning, among others.

Chapter 1 discusses the prerequisites for the training.

## Intended audience

The document is intended for design engineers, technicians, and developers of electronic systems.


PSOC™ Edge E84 series of Arm® Cortex®-M MCUs feature high-performance, low-power, secured MCUs with advanced machine learning (ML) acceleration for next generation AI/ML applications.

The PSOC™ Edge E84 MCUs feature an Arm® Cortex®-M55 core with Helium™ DSP support, combined with the Ethos™-U55 NPU. They also include a low-power Cortex®-M33 core paired with Infineon’s ultra-low-power NNLite hardware accelerator, along with advanced HMI capabilities such as graphics.

This training is intended to provide a brief introduction to some of the key features of PSOC™ Edge through easy-to-use but illustrative hands-on labs.

The training is available in different chapters for easy navigation:

- [Chapter 1: Introduction and prerequisites](pse84-technical-intro-features-training-manual-ch1-intro.md)
- [Chapter 2: Audio](pse84-technical-intro-features-training-manual-ch2-audio.md)
- [Chapter 3: Sensor hub](pse84-technical-intro-features-training-manual-ch3-sensorhub.md)
- [Chapter 4: Graphics](pse84-technical-intro-features-training-manual-ch4-graphics.md)
- [Chapter 5: SMIF (external memories)](pse84-technical-intro-features-training-manual-ch5-smif.md)
- [Chapter 6: Low power](pse84-technical-intro-features-training-manual-ch6-lowpower.md)
- [Chapter 7: Machine learning](pse84-technical-intro-features-training-manual-ch7-machinelearning.md)

Each chapter includes a training manual with detailed step-by-step instructions, and source code with solutions.

## Prerequisites

Install all required software and hardware listed in the [Required development tools](pse84-technical-intro-features-training-manual-ch1-intro.md#required-development-tools) section.

**Note** that this class will not cover the basics of ModusToolbox™ and PSOC™ Edge. Before beginning the training, it is recommended to complete an introductory course or a getting started guide to familiarize yourself with ModusToolbox™ and the PSOC™ Edge architecture.

- For an introduction to PSOC™, including a getting started guide to ModusToolbox™, visit [PSOC™ Developer Journey](https://www.infineon.com/product-information/psocdeveloper/discover)
- For PSOC™ Edge trainings, from beginner tutorials to advanced trainings, visit [PSOC™ Edge E84 training collection](https://infineon-academy.csod.com/samldefault.aspx?ouid=1&returnURL=%252fDeepLink%252fProcessRedirect.aspx%253fmodule%253dphnxdriver%2526routename%253dAdmin%252fPlayerPageRedirectHandler%2526Route%253d%25252flms-learner-playlist%25252fPlaylistDetails%2526Parameters%253dplaylistId%25253d8f04565f-88f4-4ca7-83b3-22e501656fbd)
- To start a first application for PSOC™ Edge with ModusToolbox™, visit [Getting started with PSOC™ Edge E8 MCU on ModusToolbox™ software](https://www.infineon.com/row/public/documents/30/42/infineon-an235935-getting-started-with-psoc-edge-e8-modustoolbox-applicationnotes-en.pdf)

## Required development tools

- ModusToolbox™ software v3.9 or later
	- Recommended installation via [ModusToolbox™ Setup tool](https://softwaretools.infineon.com/tools/com.ifx.tb.tool.modustoolboxsetup)
- Visual Studio Code with the **Infineon ModusToolbox™ for VS Code** extension v1.10.0 or later
	- Install Visual Studio Code, then install the extension from the VS Code Marketplace. The extension can also install the ModusToolbox™ software for you if it is not already present
- Edge Protect Security Suite v2.2.0 or later
	- Installed by [ModusToolbox™ Setup tool](https://softwaretools.infineon.com/tools/com.ifx.tb.tool.modustoolboxsetup) as a dependency to ModusToolbox™
- ModusToolbox™ Programming Tools v1.9.0 or later
	- Installed by [ModusToolbox™ Setup tool](https://softwaretools.infineon.com/tools/com.ifx.tb.tool.modustoolboxsetup) as a dependency to ModusToolbox™
- Board support package (BSP)
	- KIT\_PSE84\_EVAL\_EPC2: v1.4.0 or later (available with ModusToolbox™)
- Serial terminal emulator
	- Use Tera Term, PuTTY, or a similar terminal emulator
- PSOC™ Edge E84 evaluation kit ([KIT\_PSE84\_EVAL](https://www.infineon.com/evaluation-board/KIT-PSE84-EVAL))

**The following tools are utilized for audio labs:**

- [LLVM for Arm®](https://github.com/ARM-software/LLVM-embedded-toolchain-for-Arm/releases/) v19.1.5 or later if recommended by ModusToolbox™
- Create an account for [DEEPCRAFT™ Voice Assistant](https://deepcraft-voice-assistant.infineon.com/)
- Optional: [DEEPCRAFT™ Audio Enhancement Tech Pack](https://softwaretools.infineon.com/tools/com.ifx.tb.tool.deepcraftaudioenhancementtechpack) v1.3.0 or later
	- Recommended installation via [ModusToolbox™ Setup tool](https://softwaretools.infineon.com/tools/com.ifx.tb.tool.modustoolboxsetup)

**The following tools are utilized for graphics labs:**

- Optional, [EEZ-Studio](https://www.envox.eu/studio/studio-introduction/) v0.29.0 or later
- Optional: [Python 3](https://www.python.org/downloads/) with “pypng” and “lz4” modules:
```bash
python -m pip install pypng==0.20220715.0
python -m pip install lz4
```
- Optional, [Pngquant](https://pngquant.org/) v2.17.0 or later

**The following tools are utilized for machine learning labs:**

- [DEEPCRAFT™ Studio](https://www.infineon.com/design-resources/embedded-software/deepcraft-edge-ai-solutions/deepcraft-studio) v5.14.5788 or later
- Create an [Imagimob account](https://account.imagimob.com/signup) to train models

### Revision history

| Document revision | Date       | Description of changes                                |
| ----------------- | ---------- | ----------------------------------------------------- |
| \*A               | 2026-09-26 | Updated to latest tools and using Visual Studio Code. |
| **                | 2025-01-15 | Initial release.                                      |

### Disclaimer
All referenced product or service names and trademarks are the property of their respective owners.

The Bluetooth&reg; word mark and logos are registered trademarks owned by Bluetooth SIG, Inc., and any use of such marks by Infineon is under license.

PSOC&trade;, formerly known as PSOC&trade;, is a trademark of Infineon Technologies. Any references to PSOC&trade; in this document or others shall be deemed to refer to PSOC&trade;.

---------------------------------------------------------

© Cypress Semiconductor Corporation, 2023-2026. This document is the property of Cypress Semiconductor Corporation, an Infineon Technologies company, and its affiliates ("Cypress").  This document, including any software or firmware included or referenced in this document ("Software"), is owned by Cypress under the intellectual property laws and treaties of the United States and other countries worldwide.  Cypress reserves all rights under such laws and treaties and does not, except as specifically stated in this paragraph, grant any license under its patents, copyrights, trademarks, or other intellectual property rights.  If the Software is not accompanied by a license agreement and you do not otherwise have a written agreement with Cypress governing the use of the Software, then Cypress hereby grants you a personal, non-exclusive, nontransferable license (without the right to sublicense) (1) under its copyright rights in the Software (a) for Software provided in source code form, to modify and reproduce the Software solely for use with Cypress hardware products, only internally within your organization, and (b) to distribute the Software in binary code form externally to end users (either directly or indirectly through resellers and distributors), solely for use on Cypress hardware product units, and (2) under those claims of Cypress's patents that are infringed by the Software (as provided by Cypress, unmodified) to make, use, distribute, and import the Software solely for use with Cypress hardware products.  Any other use, reproduction, modification, translation, or compilation of the Software is prohibited.
<br>
TO THE EXTENT PERMITTED BY APPLICABLE LAW, CYPRESS MAKES NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, WITH REGARD TO THIS DOCUMENT OR ANY SOFTWARE OR ACCOMPANYING HARDWARE, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  No computing device can be absolutely secure.  Therefore, despite security measures implemented in Cypress hardware or software products, Cypress shall have no liability arising out of any security breach, such as unauthorized access to or use of a Cypress product. CYPRESS DOES NOT REPRESENT, WARRANT, OR GUARANTEE THAT CYPRESS PRODUCTS, OR SYSTEMS CREATED USING CYPRESS PRODUCTS, WILL BE FREE FROM CORRUPTION, ATTACK, VIRUSES, INTERFERENCE, HACKING, DATA LOSS OR THEFT, OR OTHER SECURITY INTRUSION (collectively, "Security Breach").  Cypress disclaims any liability relating to any Security Breach, and you shall and hereby do release Cypress from any claim, damage, or other liability arising from any Security Breach.  In addition, the products described in these materials may contain design defects or errors known as errata which may cause the product to deviate from published specifications. To the extent permitted by applicable law, Cypress reserves the right to make changes to this document without further notice. Cypress does not assume any liability arising out of the application or use of any product or circuit described in this document. Any information provided in this document, including any sample design information or programming code, is provided only for reference purposes.  It is the responsibility of the user of this document to properly design, program, and test the functionality and safety of any application made of this information and any resulting product.  "High-Risk Device" means any device or system whose failure could cause personal injury, death, or property damage.  Examples of High-Risk Devices are weapons, nuclear installations, surgical implants, and other medical devices.  "Critical Component" means any component of a High-Risk Device whose failure to perform can be reasonably expected to cause, directly or indirectly, the failure of the High-Risk Device, or to affect its safety or effectiveness.  Cypress is not liable, in whole or in part, and you shall and hereby do release Cypress from any claim, damage, or other liability arising from any use of a Cypress product as a Critical Component in a High-Risk Device. You shall indemnify and hold Cypress, including its affiliates, and its directors, officers, employees, agents, distributors, and assigns harmless from and against all claims, costs, damages, and expenses, arising out of any claim, including claims for product liability, personal injury or death, or property damage arising from any use of a Cypress product as a Critical Component in a High-Risk Device. Cypress products are not intended or authorized for use as a Critical Component in any High-Risk Device except to the limited extent that (i) Cypress's published data sheet for the product explicitly states Cypress has qualified the product for use in a specific High-Risk Device, or (ii) Cypress has given you advance written authorization to use the product as a Critical Component in the specific High-Risk Device and you have signed a separate indemnification agreement.
<br>
Cypress, the Cypress logo, and combinations thereof, ModusToolbox, PSOC, CAPSENSE, EZ-USB, F-RAM, and TRAVEO are trademarks or registered trademarks of Cypress or a subsidiary of Cypress in the United States or in other countries. For a more complete list of Cypress trademarks, visit www.infineon.com. Other names and brands may be claimed as property of their respective owners.

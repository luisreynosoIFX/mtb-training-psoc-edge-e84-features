# PSOC™ Edge Training - Technical Introduction to PSOC™ Edge E84 Features

This training provides an introduction to key features of the PSOC™ Edge E84 microcontrollers,
including audio, graphics, sensor hub, memories, low power modes, and machine learning.
The training includes hands-on labs and challenges for each one of these topics,
providing a great starting point to getting familiar with PSOC™ Edge.

## Device family
- [PSOC™ Edge](https://www.infineon.com/products/microcontroller/32-bit-psoc-arm-cortex/32-bit-psoc-edge-arm)

## How to use this training?
1. Download the training [content](#content)
2. Watch the video or review the presentation at your own pace
3. Follow the step-by-step instructions in the training manual during the hands-on sections
4. Use the provided source files if needed to verify the solution

## Training level
- E2: Intermediate

## Prerequisites
### Recommended trainings
- This training does not cover basic concepts of ModusToolbox™ and PSOC™ Edge.
- For an introduction to PSOC™ MCUs, including getting-started guides for ModusToolbox™, go to the [PSOC™ Developer Journey](https://www.infineon.com/PSOCdeveloper).
- For PSOC™ Edge trainings, from beginner tutorials to advanced trainings, visit the [PSOC™ Edge E84 Training Collection](https://infineon-academy.csod.com/ui/lms-learner-playlist/PlaylistDetails?playlistId=8f04565f-88f4-4ca7-83b3-22e501656fbd).

### Tools (see training manual for versions and installation instructions)
- [ModusToolbox™ with Visual Studio Code](https://softwaretools.infineon.com/tools/com.ifx.tb.tool.modustoolboxsetup)
- [Edge Protect Security Suite](https://softwaretools.infineon.com/tools/com.ifx.tb.tool.modustoolboxsetup)
- [ModusToolbox™ Programming tools](https://softwaretools.infineon.com/tools/com.ifx.tb.tool.modustoolboxsetup)
- Terminal emulator

## Hardware
- [KIT_PSE84_EVAL](https://www.infineon.com/evaluation-board/KIT-PSE84-EVAL)

## Duration
- 4-8 hours, including video and hands-on labs with challenges

## Agenda
1. Getting started
2. Audio: 2 labs
3. Sensor hub: 1 lab
4. Graphics: 2 labs
5. SMIF: 2 labs
6. Low power modes: 2 labs
7. Machine learning: 1 lab including data collection, training, and model deployment

## Expected outcome
- Get hands-on experience with some of the key features and advantages of PSOC™ Edge E84.
- Get familiar with PSOC™ Edge E84 hardware and software ecosystem.
- Dive deeper with challenges included for all labs.

## Content
- [Training video at Infineon Academy](https://infineon-academy.csod.com/samldefault.aspx?ouid=1&returnURL=%252fDeepLink%252fProcessRedirect.aspx%253fmodule%253dlodetails%2526lo%253df42ca461-7b77-4eed-b019-8d82f41097e0)
- [Presentation](./Presentation/PSE84_Technical_introduction_features.pdf)
- [Chapter 1: Introduction](./pse84-technical-intro-features-training-manual-ch1-intro.md)
- [Chapter 2: Audio](./pse84-technical-intro-features-training-manual-ch2-audio.md)
- [Chapter 3: Sensor Hub](./pse84-technical-intro-features-training-manual-ch3-sensorhub.md)
- [Chapter 4: Graphics](./pse84-technical-intro-features-training-manual-ch4-graphics.md)
- [Chapter 5: Memories (SMIF)](./pse84-technical-intro-features-training-manual-ch5-smif.md)
- [Chapter 6: Low Power](./pse84-technical-intro-features-training-manual-ch6-lowpower.md)
- [Chapter 7: Machine Learning](./pse84-technical-intro-features-training-manual-ch7-machinelearning.md)
- [Appendix A: Creating a PSOC™ Edge application in ModusToolbox™](./pse84-technical-intro-features-training-manual-appendix-a.md)
- [Appendix B: KIT_PSE84_EVAL details](./pse84-technical-intro-features-training-manual-appendix-b.md)

## References and resources
- [PSOC™ Edge MCUs](https://www.infineon.com/products/microcontroller/32-bit-psoc-arm-cortex/32-bit-psoc-edge-arm)
- [Introduction to PSOC™ MCUs and ModusToolbox™](https://www.infineon.com/PSOCdeveloper)
- [PSOC™ Edge E84 training collection](https://infineon-academy.csod.com/ui/lms-learner-playlist/PlaylistDetails?playlistId=8f04565f-88f4-4ca7-83b3-22e501656fbd)

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

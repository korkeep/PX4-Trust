/**
  @page Step2-ST_Customer_level_n+1  Proprietary code read-out protection on microcontrollers of the STM32F7 series Readme file
  
  @verbatim
  ******************** (C) COPYRIGHT 2017 STMicroelectronics *******************
  * @file    Step2-ST_Customer_level_n+1/readme.txt 
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    28-January-2017
  * @brief   Description of the PCROP example STEP2.
  ******************************************************************************
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  @endverbatim

@par Example Description

   In this Step2 project the MCU is already preloaded with FIR-Filter PRCOP-ed IP-Code (done in Step1-ST_Customer_level_n project).
   To call the IP-Code FIR_lowpass_filter() function:
   - The fir_filter.h header file is included in main.c file
   - Symbol definition file (fir_filter.txt for MDK-ARM™ and fir_filter.o for EWARM and SW4STM32) containing PCROP-ed functions' symbols 
     and addresses is included in this project. Noting that symbol definition file have to be generated in Step1-ST_Customer_level_n 
	 in order to replace the existing one in this project.
	  
  

@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The application needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.


@par Directory contents 

  - Step2-ST_Customer_level_n+1/Src/main.c                      Main program
  - Step2-ST_Customer_level_n+1/Src/system_stm32f7xx.c          STM32F7xx system clock configuration file
  - Step2-ST_Customer_level_n/+1Src/stm32f7xx_it.c              Interrupt handlers 
  - Step2-ST_Customer_level_n+1/Src/stm32f7xx_hal_msp.c         HAL MSP module
  - Step2-ST_Customer_level_n+1/Src/math_helper.c               Calculation of SNR 
  - Step2-ST_Customer_level_n+1/Src/arm_fir_data.c              Contains FIR_Filter's Input signal and Reference output signal computed with MATLAB
  - Step2-ST_Customer_level_n+1/Inc/main.h                      Main program header file  
  - Step2-ST_Customer_level_n+1/Inc/stm32f7xx_hal_conf.h        HAL Configuration file
  - Step2-ST_Customer_level_n+1/Inc/stm32f7xx_it.h              Interrupt handlers header file
  - Step2-ST_Customer_level_n+1/Inc/math_helper.h               math_helper header file
  
  Related IP-Code files provided from ST Customer level n :
  - Step2-ST_Customer_level_n+1/MDK-ARM/fir_filter.txt          Symbol definition file for MDK-ARM™ project containing PCROP-ed functions' symbols and addresses
  - Step2-ST_Customer_level_n+1/EWARM/fir_filter.o              Symbol definition file for EWARM project containing PCROP-ed functions' symbols and addresses
  - Step2-ST_Customer_level_n+1/SW4STM32/fir_filter.o           Symbol definition file for SW4STM32 project containing PCROP-ed functions' symbols and addresses  
  - Step1-ST_Customer_level_n+1/Inc/fir_filter.h                FIR-Filter PCROP-ed IP-Code header file	
  
  
  
 
@par Hardware and Software environment  

  - This example runs on STM32F722ZE devices.
  - This example has been tested with STMicroelectronics STM32F722ZE-Nucleo RevB
    boards and can be easily tailored to any other supported device and development board.
  - This example has been tested with the following toolchains :
      - RealView Microcontroller Development Kit (MDK-ARM™) toolchain V5.21a 
      - IAR Embedded Workbench for ARM (EWARM) toolchain
      - System Workbench for STM32 (SW4STM32) toolchain


@par How to use it ? 

Before running this project the following conditions must be met:
- The same toolchain and compiler version must be used for both projects in STEP1 and STEP2: if EWARM was used in Step1-ST_Customer_level_n project 
  then it must be used for Step2-ST_Customer_level_n+1 too. 
- The Step1-ST_Customer_level_n project have to be run in order to have FIR-Filter IP-Code programmed and PCROP-ed in this project. 
  Once done, PCROP-ed IP-Code functions defined in fir_filter.h can be called in this project.
- The provided symbol definition file must be replaced by the newly generated in STEP1 as indicated below:
  For MDK-ARM™ toolchain: replace fir_filter.txt in Step2-ST_Customer_level_n+1\MDK-ARM by the file generated in Step1-ST_Customer_level_n\MDK-ARM\PCROP-IP-Code-XO
  For EWARM toolchain: replace fir_filter.o in Step2-ST_Customer_level_n+1\EWARM by the file generated in Step1-ST_Customer_level_n\EWARM
  For SW4STM32 toolchain: replace fir_filter.o in Step2-ST_Customer_level_n+1\SW4STM32 by the file generated in Step1-ST_Customer_level_n\SW4STM32\PCROP-IP-Code-XO\Debug. 

In order to make the program work, you must do the following :

Note:   
Due to EWARM V7.80.4 and older versions limitation the following steps should done before rebuilding the project :  
1- Run the patch EWARM_STM32F72x_STM32F73x_patch.exe located under Utilities\PC_Software folder as administrator 
2- Copy/past your EWARM install folder path in the dialogbox(ex: C:\Program Files (x86)\IAR Systems\Embedded Workbench 7.5) 
3- click "Extract" button and replace all the files by clicking "Yes to All" button
4- Close and reopen the EWARM IDE. 

The FIR-Filter IP-Code must be already programmed and PCROP-ed before running this example.
	1. Open project located in Step2-ST_Customer_level_n+1 directory and choose the same toolchain used in STEP1.
	2. Rebuild all files.
	3. Run the example following the sequence below
		a) Power on the board and load the code (here only user code is loaded)
		b) Press the user button key to execute the PCROP-ed IP code called in main.c file,
		the green LED should toggle continuously.



 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */

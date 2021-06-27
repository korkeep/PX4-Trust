/**
  @page Step1-ST_Customer_level_n  Proprietary code read-out protection on microcontrollers of the STM32F7 series Readme file
  
  @verbatim
  ******************** (C) COPYRIGHT 2017 STMicroelectronics *******************
  * @file    Step1-ST_Customer_level_n/readme.txt 
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    28-January-2017
  * @brief   Description of the PCROP example STEP1.
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

  This project (STEP1 of the example) describes how to generate an execute-only IP-Code (using compiler options), place and protect it 
  (protection using PCROP) in a preferred sector in internal flash memory.
  The FIR Filter algorithm from CMSIS library is chosen as an example of IP-Code to be protected.
  Enabling PCROP is managed by software in PCROP_Enable() function.
  The IP-Code function FIR_lowpass_filter() is called in main.c file.
  Note that symbol definition file have to be generated in PCROP-IP-Code-XO project configuration described below, it has to be used in
  Step2-ST_Customer_level_n+1 project.
  Two project configurations are provided with this project:
  1. PCROP-IP-Code-XO (must be used before STEP2): the compiler is configured to generate an execute-only IP-Code avoiding any data read from 
  it (avoiding literal pools).
  2. PCROP-IP-Code (for test only): no special compiler option used, just for testing purposes to show that avoiding data in code (as literal pools and branch tables) 
  is mandatory for PCROP-ed codes.
  
   
  
@note The IP-Code is placed in sector 2 which will be PCROP-ed.
      Activating PCROP on sector 2 is managed by PCROP_Enable() function described in main file. 
      STM32 ST-Link Utility can be used to activate PCROP as well, in that case comment the define USE_PCROP_FUNCTION.
	
@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The application needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.


@par Directory contents 

  - Step1-ST_Customer_level_n/Src/main.c                 Main program
  - Step1-ST_Customer_level_n/Src/system_stm32f7xx.c     STM32F7xx system clock configuration file
  - Step1-ST_Customer_level_n/Src/stm32f7xx_it.c         Interrupt handlers 
  - Step1-ST_Customer_level_n/Src/stm32f7xx_hal_msp.c    HAL MSP module
  - Step1-ST_Customer_level_n/Src/math_helper.c          Calculation of SNR 
  - Step1-ST_Customer_level_n/Src/arm_fir_data.c         Contains FIR_Filter's Input signal and Reference output signal computed with MATLAB
  - Step1-ST_Customer_level_n/Inc/main.h                 Main program header file  
  - Step1-ST_Customer_level_n/Inc/stm32f7xx_hal_conf.h   HAL Configuration file
  - Step1-ST_Customer_level_n/Inc/stm32f7xx_it.h         Interrupt handlers header file
  - Step1-ST_Customer_level_n/Inc/fir_filter.h           FIR-Filter PCROP-ed IP-Code header file
  - Step1-ST_Customer_level_n/Inc/math_helper.h          math_helper header file

FIR Filter files representing the IP-Code to be PCROP-ed
  - Step1-ST_Customer_level_n/Src/fir_filter.c           File containing global FIR Low Pass Filter function   
  - Step1-ST_Customer_level_n/Src/arm_fir_f32.c          File containing FIR Filter basic function from CMSIS lib
  - Step1-ST_Customer_level_n/Src/arm_fir_init_f32.c     File containing FIR Filter Initialization function from CMSIS lib
  
  
  

@par Hardware and Software environment  

  - This example runs on STM32F722ZE devices.
  - This example has been tested with STMicroelectronics STM32F722ZE-Nucleo RevB
    boards and can be easily tailored to any other supported device and development board.
  - This example has been tested with the following toolchains :
      - RealView Microcontroller Development Kit (MDK-ARM™) toolchain V5.21a
      - IAR Embedded Workbench for ARM (EWARM) toolchain 
      - System Workbench for STM32 (SW4STM32) toolchain

@par Generating symbol definition file 
	Generating symbol definition file is mandatory for STEP2 and the provided file must be replaced by the newly generated. 
	To generate symbol definition file required for STEP2, select PCROP-IP-Code-XO and click on Rebuild all button then symbol definition file is created. 
        - For MDK-ARM™ toolchain: fir_filter.txt symbol definition file is created in Step1-ST_Customer_level_n\MDK-ARM\PCROP-IP-Code-XO
          It must be modified by deleting all lines and keeping only FIR-Filter IP-Code functions (please follow the provided fir_filter.txt file
          in Step2-ST_Customer_level_n+1\MDK-ARM). Once modified, copy it to Step2-ST_Customer_level_n+1\MDK-ARM and replace the existing file.
        - For EWARM toolchain: fir_filter.o symbol definition file is created in Step1-ST_Customer_level_n\EWARM.
          No modification is required on this file and it has to be used in STEP2 project by copying it to Step2-ST_Customer_level_n+1\EWARM
          and replacing the existing file.
        - For SW4STM32 toolchain: fir_filter.o symbol definition file is created in Step1-ST_Customer_level_n\SW4STM32\PCROP-IP-Code-XO\Debug.
          No modification is required on this file and it has to be used in STEP2 project by copying it to Step2-ST_Customer_level_n+1\SW4STM32
          and replacing the existing file.    

		  
@par How to use it ? 

Before running this project the following conditions must be met:
- The same toolchain and compiler version must be used for both projects in STEP1 and STEP2: for instance if MDK-ARM™ V5.14 is used 
  in Step1-ST_Customer_level_n project then it must be used for Step2-ST_Customer_level_n+1 too.
- Check if any Read out protection, write protection or PCROP protection is enabled, if yes disable this protection 
  using STM32 STLink Utility. For more details on using STM32 STLink Utility please refer to User manual UM0892 available at www.st.com. 

In order to make the program work, you must do the following :

Notes: 
Due to SW4MT32 limitation the following steps should done before rebuilding the project :
1-Right click on FIR-Filter folder and then Resource Configurations-> Reset to Default   
2-check [debug] for FIR-Filter option and click on OK  
3-right click on FIR-Filter folder and then go to Properties->C\C++ Build->Settings->Miscellaneous
4-Check the option "No data reads in code memory" and click OK  
    
Due to EWARM V7.80.4 and older versions limitation the following steps should done before rebuilding the project :  
1- Run the patch EWARM_STM32F72x_STM32F73x_patch.exe located under Utilities\PC_Software folder as administrator 
2- Copy/past your EWARM install folder path in the dialogbox(ex: C:\Program Files (x86)\IAR Systems\Embedded Workbench 7.5) 
3- click "Extract" button and replace all the files by clicking "Yes to All" button
4- Close and reopen the EWARM IDE. 

PCROP-IP-Code-XO: in this configuration the compiler is configured to generate an execute only IP-Code avoiding any data read from it. 
	1. Open project located in Step1-ST_Customer_level_n directory and choose your preferred toolchain 
	2. Select the PCROP-IP-Code-XO project configuration
	3. Rebuild all files. 
	4. Run the example following the sequence below:
		a) Power on the board then load the code, BLUE LED should toggle continuously, if not press RESET button;
		b) Press the user button key to activate PCROP protection, then BLUE LED is off, GREEN LED is ON and sector 2 is PCROP-ed.
		If PCROP activation failed then BLUE LED is ON.
		c) Press the user button key to execute the PCROP-ed IP-code called in main.c file,
		the GREEN LED should toggle continuously.
    
PCROP-IP-Code: no special configuration and the compiler is generating IP-Code without avoiding data read (literal pools)
	1. In the same project located in Step1-ST_Customer_level_n directory select PCROP-IP-Code project configuration
	2. Rebuild all files.
	3. Run the example following the sequence below
		a) Power on the board then load the code, BLUE LED should toggle continuously, if not press RESET button;
		b) Press the user button key to activate PCROP protection, then BLUE LED is off, GREEN LED is
		ON and sector 2 is PCROP-ed. If PCROP activation failed then BLUE LED is ON.
		c)press the user button key to run the FIR low pass filter function: a Read Error Operation Interrupt is generated,
		a system Reset is initiated then system restarts and the BLUE LED toggles continuously.


 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */

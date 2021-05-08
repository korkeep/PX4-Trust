/**
  @page Step1-ST_Customer_level_n  Proprietary code read-out protection on microcontrollers of the STM32F4 series Readme file
  
  @verbatim
  ******************** (C) COPYRIGHT 2015 STMicroelectronics *******************
  * @file    Step1-ST_Customer_level_n/readme.txt 
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    28-May-2015
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
  - Step1-ST_Customer_level_n/Src/system_stm32f4xx.c     STM32F4xx system clock configuration file
  - Step1-ST_Customer_level_n/Src/stm32f4xx_it.c         Interrupt handlers 
  - Step1-ST_Customer_level_n/Src/stm32f4xx_hal_msp.c    HAL MSP module
  - Step1-ST_Customer_level_n/Src/math_helper.c          Calculation of SNR 
  - Step1-ST_Customer_level_n/Src/arm_fir_data.c         Contains FIR_Filter's Input signal and Reference output signal computed with MATLAB
  - Step1-ST_Customer_level_n/Inc/main.h                 Main program header file  
  - Step1-ST_Customer_level_n/Inc/stm32f4xx_hal_conf.h   HAL Configuration file
  - Step1-ST_Customer_level_n/Inc/stm32f4xx_it.h         Interrupt handlers header file
  - Step1-ST_Customer_level_n/Inc/fir_filter.h           FIR-Filter PCROP-ed IP-Code header file
  - Step1-ST_Customer_level_n/Inc/math_helper.h          math_helper header file

FIR Filter files representing the IP-Code to be PCROP-ed
  - Step1-ST_Customer_level_n/Src/fir_filter.c           File containing global FIR Low Pass Filter function   
  - Step1-ST_Customer_level_n/Src/arm_fir_f32.c          File containing FIR Filter basic function from CMSIS lib
  - Step1-ST_Customer_level_n/Src/arm_fir_init_f32.c     File containing FIR Filter Initialization function from CMSIS lib
  
  
  

@par Hardware and Software environment  

  - This example runs on STM32F429xx devices.
  - This example has been tested with STMicroelectronics STM32F429I-Discovery RevB
    boards and can be easily tailored to any other supported device and development board.
  - This example has been tested with the following toolchains :
      - RealView Microcontroller Development Kit (MDK-ARM™) toolchain V5.14 
      - IAR Embedded Workbench for ARM (EWARM) toolchain V7.30.3.8062

@par Generating symbol definition file 
	Generating symbol definition file is mandatory for STEP2 and the provided file must be replaced by the newly generated. 
	To generate symbol definition file required for STEP2, select PCROP-IP-Code-XO and click on Rebuild all button then symbol definition file is created. 
        - For MDK-ARM™ toolchain: fir_filter.txt symbol definition file is created in Step1-ST_Customer_level_n\MDK-ARM\PCROP-IP-Code-XO
          It must be modified by deleting all lines and keeping only FIR-Filter IP-Code functions (please follow the provided fir_filter.txt file
          in Step2-ST_Customer_level_n+1\MDK-ARM). Once modified, copy it to Step2-ST_Customer_level_n+1\MDK-ARM and replace the existing file.
        - For EWARM toolchain: fir_filter.o symbol definition file is created in Step1-ST_Customer_level_n\EWARM.
          No modification is required on this file and it has to be used in STEP2 project by copying it to Step2-ST_Customer_level_n+1\EWARM
          and replacing the existing file.
		  
@par How to use it ? 

Before running this project the following conditions must be met:
- The same toolchain and compiler version must be used for both projects in STEP1 and STEP2: for instance if MDK-ARM™ V5.14 is used 
  in Step1-ST_Customer_level_n project then it must be used for Step2-ST_Customer_level_n+1 too.
- Check if any Read out protection, write protection or PCROP protection is enabled, if yes disable this protection 
  using STM32 STLink Utility. For more details on using STM32 STLink Utility please refer to User manual UM0892 available at www.st.com. 

In order to make the program work, you must do the following :

PCROP-IP-Code-XO: in this configuration the compiler is configured to generate an execute only IP-Code avoiding any data read from it. 
	1. Open project located in Step1-ST_Customer_level_n directory and choose your preferred toolchain 
	2. Select the PCROP-IP-Code-XO project configuration
	3. Rebuild all files. 
	4. Run the example following the sequence below:
		a) Power on the board then load the code, RED LED should toggle continuously, if not press RESET button;
		b) Press the user button key to activate PCROP protection, then RED LED is off, GREEN LED is ON and sector 2 is PCROP-ed.
		If PCROP activation failed then RED LED is ON.
		c) Press the user button key to execute the PCROP-ed IP-code called in main.c file,
		the GREEN LED should toggle continuously.

PCROP-IP-Code: no special configuration and the compiler is generating IP-Code without avoiding data read (literal pools)
	1. In the same project located in Step1-ST_Customer_level_n directory select PCROP-IP-Code project configuration
	2. Rebuild all files.
	3. Run the example following the sequence below
		a) Power on the board then load the code, RED LED should toggle continuously, if not press RESET button;
		b) Press the user button key to activate PCROP protection, then RED LED is off, GREEN LED is
		ON and sector 2 is PCROP-ed. If PCROP activation failed then RED LED is ON.
		c)press the user button key to run the FIR low pass filter function: a Read Error Operation Interrupt is generated,
		a system Reset is initiated then system restarts and the RED LED toggles continuously.


 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */

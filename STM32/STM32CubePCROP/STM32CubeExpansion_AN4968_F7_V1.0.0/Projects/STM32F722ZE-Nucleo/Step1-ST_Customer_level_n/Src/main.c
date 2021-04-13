/**
  ******************************************************************************
  * @file    Step1-ST_Customer_level_n/Src/main.c 
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    28-January-2017
  * @brief   This example provides a description of how to use PCROP protection 
  *	     		 feature on STM32F72xxx and STM32F73xxx.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2017 STMicroelectronics</center></h2>
  *
  * Redistribution and u	se in source and binary forms, with or without modification,
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
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Comment this line if you will not use PCROP_Enable() function */
#define USE_PCROP_FUNCTION
#define PCROP_CONST_DATA_WRP_ON
#if defined (USE_PCROP_FUNCTION)
#define FLASH_PCROP_SECTORS   OB_PCROP_SECTOR_2 /* sector 2 */
#define FLASH_WRP_SECTORS     OB_WRP_SECTOR_3 /* sector 3 */
#endif /* USE PCROP FUNCTION */

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
static float32_t aTestOutput[TEST_LENGTH_SAMPLES];
__IO uint8_t ubKeyPressed = RESET; 
#if defined (USE_PCROP_FUNCTION)
__IO uint32_t SectorsPCROPStatus = 0x00000000;
__IO uint32_t SectorsWPRStatus = 0x00000000;
#endif /* USE PCROP FUNCTION */

/* Private function prototypes -----------------------------------------------*/
static void SystemClock_Config(void);
static void CPU_CACHE_Enable(void);
#if defined (USE_PCROP_FUNCTION)
uint32_t PCROP_Enable(void);
#endif /* USE PCROP FUNCTION */
void EnableFlash_IT(void);
void EnableBusFault_IT(void);


/**
  * @brief  Main program
  * @param  None
  * @retval None
  */
int main(void)
{
    arm_status status = ARM_MATH_SUCCESS;
    float32_t  *input_f32 = 0;
    float32_t  *output_f32 = 0;
    float32_t snr = 0;

  /* Initialize input and output buffer pointers */
  input_f32 = &testInput_f32_1kHz_15kHz[0];
  output_f32 = &aTestOutput[0];
  
  /* Enable the CPU Cache */
  CPU_CACHE_Enable();

  /* STM32F7xx HAL library initialization:
       - Configure the Flash prefetch
       - Systick timer is configured by default as source of time base, but user 
         can eventually implement his proper time base source (a general purpose 
         timer for example or other time source), keeping in mind that Time base 
         duration should be kept 1ms since PPP_TIMEOUT_VALUEs are defined and 
         handled in milliseconds basis.
       - Set NVIC Group Priority to 4
       - Low Level Initialization
     */
  HAL_Init();
  /* Configure the system clock to 180 MHz */
  SystemClock_Config();
  /* Configure User Button */
  BSP_PB_Init(BUTTON_USER, BUTTON_MODE_EXTI);
  /* Configure LED2 */
  BSP_LED_Init(LED2);   
  /* Configure LED1 */
  BSP_LED_Init(LED1);
	


 /* Enable Bus Fault Error Interrupt */ 
  EnableBusFault_IT();
    
  /* Configure Flash to generate an interrupt when a Read/Write from/to flash operation error */
  EnableFlash_IT();
 
  /* Wait for KEY button to be pushed */
  while(ubKeyPressed == RESET)
  {
  BSP_LED_Toggle(LED2);
  HAL_Delay(100);
  }
  ubKeyPressed = RESET;
  /* Turn Off LED2 */
  BSP_LED_Off(LED2);  

  
#if defined (USE_PCROP_FUNCTION)
  /* Enable PCROP Protection on sector 2 where FIR Filter IP-Code is placed */
  if  (PCROP_Enable() == HAL_OK)
  {
  /* Turn On GREEN LED1 if PCROP activated successfully */
  BSP_LED_On(LED1);
  }
  else
  {
  /* Turn On BLUE LED2 if PCROP activation failed */
  BSP_LED_On(LED2);
  /* Infinite loop */
  while(1);
  }
  /* Wait for KEY button to be pushed */
  while(ubKeyPressed == RESET);	
#endif /* USE PCROP FUNCTION */

  /* Call the FIR Low Pass Filter function */
  FIR_lowpass_filter(input_f32, output_f32, TEST_LENGTH_SAMPLES);
  /* Compare the generated output against the reference output computed
  in MATLAB. */
  snr = arm_snr_f32(&refOutput[0], &aTestOutput[0], TEST_LENGTH_SAMPLES);
  if (snr < SNR_THRESHOLD_F32)
  {
  status = ARM_MATH_TEST_FAILURE;
  }
  else
  {
  status = ARM_MATH_SUCCESS;
  }	 
  /* Infinite loop */
  while (1)
  {
  if (status == ARM_MATH_TEST_FAILURE)
  {	
  /* Toggle LED2 */
  BSP_LED_Toggle(LED2);
  HAL_Delay(500);
  }
  else
  {
  /* Toggle LED1 */
  BSP_LED_Toggle(LED1);
  HAL_Delay(500);
  }
  } 
}

/**
  * @brief  System Clock Configuration
  *         The system Clock is configured as follow : 
  *            System Clock source            = PLL (HSE)
  *            SYSCLK(Hz)                     = 216000000
  *            HCLK(Hz)                       = 216000000
  *            AHB Prescaler                  = 1
  *            APB1 Prescaler                 = 4
  *            APB2 Prescaler                 = 2
  *            HSE Frequency(Hz)              = 25000000
  *            PLL_M                          = 25
  *            PLL_N                          = 432
  *            PLL_P                          = 2
  *            PLL_Q                          = 9
  *            VDD(V)                         = 3.3
  *            Main regulator output voltage  = Scale1 mode
  *            Flash Latency(WS)              = 7
  * @param  None
  * @retval None
  */
static void SystemClock_Config(void)
{
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_OscInitTypeDef RCC_OscInitStruct;
  
  /* Enable HSE Oscillator and activate PLL with HSE as source */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 25;
  RCC_OscInitStruct.PLL.PLLN = 432;  
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 9;
  if(HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    while(1) {};
  }
  
  /* Activate the OverDrive to reach the 216 Mhz Frequency */
  if(HAL_PWREx_EnableOverDrive() != HAL_OK)
  {
    while(1) {};
  }
  
  
  /* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2 
     clocks dividers */
  RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;  
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;  
  if(HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK)
  {
    while(1) {};
  }
}


#if defined (USE_PCROP_FUNCTION)

/**
  * @brief  Enable PCROP
  * @param  None
  * @retval None
  */
uint32_t PCROP_Enable(void)
{
  FLASH_OBProgramInitTypeDef pAdvOBInit; 
  
  /* Get FLASH_PCROP_SECTORS protection status */
  HAL_FLASHEx_OBGetConfig(&pAdvOBInit);
  SectorsPCROPStatus = pAdvOBInit.PCROPSector & FLASH_PCROP_SECTORS;
  SectorsWPRStatus = pAdvOBInit.WRPSector & FLASH_WRP_SECTORS;  
		
  /* Check if sector 2 has been already PCROP-ed */
  if ((SectorsPCROPStatus == FLASH_PCROP_SECTORS)&&(SectorsWPRStatus == FLASH_WRP_SECTORS))
  { 
  return(HAL_OK);
  }
  else
  {
  /* Allow Access to option bytes sector */ 
  HAL_FLASH_OB_Unlock();
  /* Allow Access to Flash control registers and user Flash */
  HAL_FLASH_Unlock();

      /* Enable FLASH_PCROP_SECTORS PCROP protection on sector 2, set PCROP_RDP  */
      pAdvOBInit.OptionType = OPTIONBYTE_PCROP | OPTIONBYTE_PCROP_RDP;
      pAdvOBInit.PCROPSector  = FLASH_PCROP_SECTORS;
      pAdvOBInit.PCROPRdp  = OB_PCROP_RDP_ENABLE;

#ifdef PCROP_CONST_DATA_WRP_ON
  /* Update OB for Write Protection */
      pAdvOBInit.OptionType |=  OPTIONBYTE_WRP ;
      pAdvOBInit.WRPState   = OB_WRPSTATE_ENABLE;
      pAdvOBInit.WRPSector  = FLASH_WRP_SECTORS;
#endif /* USE WRITE PROTECTION FOR CONSTANTS DATA */     
      
      HAL_FLASHEx_OBProgram(&pAdvOBInit);
			
  /* Start the Option Bytes programming process */  
  if (HAL_FLASH_OB_Launch() != HAL_OK)
  {
  /* Error occurred while options bytes programming */
  return(HAL_ERROR);
  }
  /* Prevent Access to option bytes sector */ 
  HAL_FLASH_OB_Lock();
  /* Disable the Flash option control register access (recommended to protect 
  the option Bytes against possible unwanted operations) */
  HAL_FLASH_Lock();
      
  /* PCROP Protection successfully Enabled */
  return(HAL_OK);
  }
}
#endif /* USE PCROP FUNCTION */

/**
  * @brief  Flash Operation Error Interrupt Enable  
  * @param  None
  * @retval None
  */
void EnableFlash_IT(void)
{
  /* Allow Access to option bytes sector */ 
  HAL_FLASH_OB_Unlock();
  /* Allow Access to Flash control registers and user Falsh */
  HAL_FLASH_Unlock();
  /* Set Read Error Interrupt Enable bit */
  FLASH->CR |= FLASH_CR_RDERRIE;
  /* Prevent Access to option bytes sector */  
  HAL_FLASH_OB_Lock();   
  /* Disable the Flash option control register access (recommended to protect 
  the option Bytes against possible unwanted operations) */
  HAL_FLASH_Lock();	
  /* Enable and set FLASH operation error Interrupt priority */
  HAL_NVIC_SetPriority((IRQn_Type)(FLASH_IRQn), 0x0E, 0x00);
  HAL_NVIC_EnableIRQ((IRQn_Type)(FLASH_IRQn));
}

/**
  * @brief  Bus Fault Error Interrupt Enable  
  * @param  None
  * @retval None
  */
void EnableBusFault_IT(void)
{
  /* Enable and set Bus Fault error Interrupt priority */
	HAL_NVIC_SetPriority((IRQn_Type)BusFault_IRQn, 0x0F ,0x01);
  SCB->SHCSR = SCB_SHCSR_BUSFAULTENA_Msk;
}
/**
  * @brief  EXTI line detection callbacks.
  * @param  GPIO_Pin: Specifies the pins connected to EXTI line
  * @retval None
  */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  ubKeyPressed = SET;
}
/**
  * @brief  FLASH operation error interrupt callback
  * @param  ReturnValue: The value saved in this parameter depends on the ongoing procedure
  *                 Mass Erase: Bank number which has been requested to erase
  *                 Sectors Erase: Sector number which returned an error
  *                 Program: Address which was selected for data program
  * @retval None
  */
void HAL_FLASH_OperationErrorCallback(uint32_t ReturnValue)
{
  /* Initiates a system reset request to reset the MCU */
  HAL_NVIC_SystemReset();
  
}

/**
  * @brief  CPU L1-Cache enable.
  * @param  None
  * @retval None
  */
static void CPU_CACHE_Enable(void)
{
  /* Enable I-Cache */
  SCB_EnableICache();

  /* Enable D-Cache */
  SCB_EnableDCache();
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}

#endif

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

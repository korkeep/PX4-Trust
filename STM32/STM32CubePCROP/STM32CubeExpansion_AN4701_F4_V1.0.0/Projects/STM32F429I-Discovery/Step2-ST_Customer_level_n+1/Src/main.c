/**
  ******************************************************************************
  * @file    Step2-ST_Customer_level_n+1/Src/main.c 
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    28-May-2015
  * @brief   This example provides a description of how to use PCROP protection 
  *	     		 feature on STM32F4xx.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2015 STMicroelectronics</center></h2>
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
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "math_helper.h"
#include "fir_filter.h"


/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define SNR_THRESHOLD_F32    140.0f
#define TEST_LENGTH_SAMPLES  320
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
extern float32_t testInput_f32_1kHz_15kHz[TEST_LENGTH_SAMPLES];
extern float32_t refOutput[TEST_LENGTH_SAMPLES];
static float32_t testOutput[TEST_LENGTH_SAMPLES];
__IO uint8_t ubKeyPressed = RESET;  

/* Private function prototypes -----------------------------------------------*/
static void SystemClock_Config(void);

/* Private functions ---------------------------------------------------------*/
void EnableFlash_IT(void);

/**
  * @brief  Main program
  * @param  None
  * @retval None
  */
int main(void)
{
  arm_status status;
  float32_t  *inputF32, *outputF32, snr;
  /* Initialize input and output buffer pointers */
  inputF32 = &testInput_f32_1kHz_15kHz[0];
  outputF32 = &testOutput[0];
	
  /* STM32F4xx HAL library initialization:
       - Configure the Flash prefetch, instruction and Data caches
       - Configure the Systick to generate an interrupt each 1 msec
       - Set NVIC Group Priority to 4
     */
  HAL_Init();
  /* Configure the system clock to 180 MHz */
  SystemClock_Config();
  /* Configure Push Button */
  BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_EXTI);
  /* Configure LED3 */
  BSP_LED_Init(LED3);   
  /* Configure LED4 */
  BSP_LED_Init(LED4);
  /* Configure Flash to generate an interrupt when a Read/Write from/to flash operation error */
  EnableFlash_IT();
	  
  /* Wait for KEY button to be pushed */
  while(ubKeyPressed == RESET)
  {
  BSP_LED_Toggle(LED4);
  HAL_Delay(100);
  }
  ubKeyPressed = RESET;
  /* Turn Off LED4 */
  BSP_LED_Off(LED4);
	
  /* Call the PCROP-ed FIR Low Pass Filter function */
  FIR_lowpass_filter(inputF32, outputF32, TEST_LENGTH_SAMPLES);
  /* Compare the generated output against the reference output computed
  in MATLAB. */
  snr = arm_snr_f32(&refOutput[0], &testOutput[0], TEST_LENGTH_SAMPLES);
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
  /* Toggle LED4 */
  BSP_LED_Toggle(LED4);
  HAL_Delay(500);
  }
  else
  {
  /* Toggle LED3 */
  BSP_LED_Toggle(LED3);
  HAL_Delay(500);
  }
  } 
}

/**
  * @brief  System Clock Configuration
  *         The system Clock is configured as follow : 
  *            System Clock source            = PLL (HSE)
  *            SYSCLK(Hz)                     = 180000000
  *            HCLK(Hz)                       = 180000000
  *            AHB Prescaler                  = 1
  *            APB1 Prescaler                 = 4
  *            APB2 Prescaler                 = 2
  *            HSE Frequency(Hz)              = 8000000
  *            PLL_M                          = 8
  *            PLL_N                          = 360
  *            PLL_P                          = 2
  *            PLL_Q                          = 7
  *            VDD(V)                         = 3.3
  *            Main regulator output voltage  = Scale1 mode
  *            Flash Latency(WS)              = 5
  * @param  None
  * @retval None
  */
static void SystemClock_Config(void)
{
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_OscInitTypeDef RCC_OscInitStruct;

  /* Enable Power Control clock */
  __HAL_RCC_PWR_CLK_ENABLE();

  /* The voltage scaling allows optimizing the power consumption when the device is 
     clocked below the maximum system frequency, to update the voltage scaling value 
     regarding system frequency refer to product datasheet.  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /* Enable HSE Oscillator and activate PLL with HSE as source */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 360;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  HAL_RCC_OscConfig(&RCC_OscInitStruct);
  
  /* Activate the Over-Drive mode */
  HAL_PWREx_EnableOverDrive();
  
  /* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2 
     clocks dividers */
  RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;  
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;  
  HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5);
}
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
  /* Set ERRor Interrupt Enable bit */
  FLASH->CR = FLASH_IT_ERR;
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
  * @brief  EXTI line detection callbacks.
  * @param  GPIO_Pin: Specifies the pins connected EXTI line
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

/**
  * @}
  */ 

/**
  * @}
  */ 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

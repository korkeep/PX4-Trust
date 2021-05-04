
/**
  ******************************************************************************
  * @file    ./Src/main.c
  * @author  MCD Application Team
  * @version V0.2.0RC2
  * @date    10-September-2015
  * @brief   Main program body
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
/* Activate PCROP configuration if defined*/
#define PCROP_ON

#ifdef PCROP_ON
/* Activate proprietary data from unwanted write/erase*/
#define PCROP_CONST_DATA_WRP_ON
/* PCROP Area start and end address */
#define PCROP_AREA_START_ADDRESS ((uint32_t)0x08008000) /* included */
#define PCROP_AREA_END_ADDRESS   ((uint32_t) (0x0800C000-0x8)) /*last Pcroped double word @*/
/* PCROP area erase policy when RDP level decreased */
/* OB_PCROP_RDP_ERASE or OB_PCROP_RDP_NOT_ERASE */
#define PCROP_AREA_ERASED_POLICY OB_PCROP_RDP_ERASE

#endif /* PCROP_ON */

/* Use LCD if defined */
#define LCD_ON
#ifdef LCD_ON
#include "stm32l476g_discovery_glass_lcd.h"
#endif /* LCD_ON */

/* Application define */
#define SNR_THRESHOLD_F32    ((float) 140.0f)
#define TEST_LENGTH_SAMPLES  ((uint32_t) 320)

#define FLASH_IT_ERR  ((uint32_t)0x04000000)  /*!< Error Interrupt source */

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
extern float32_t testInput_f32_1kHz_15kHz[TEST_LENGTH_SAMPLES];
extern float32_t refOutput[TEST_LENGTH_SAMPLES];
static float32_t testOutput[TEST_LENGTH_SAMPLES];

#ifdef LCD_ON
/* Define messages to be displayed on LCD */
uint8_t *msg_welcome = (uint8_t *) "WELCOME PCROP STEP 1 ";

uint8_t *msg_pcrop_ok = (uint8_t *)"PR OK ";
uint8_t *msg_pcrop_err = (uint8_t *)"PR ERR";

uint8_t *msg_tst_ok = (uint8_t *)"TST OK";
uint8_t *msg_tst_nok = (uint8_t *)"TSTNOK";

uint8_t *msg_it = (uint8_t *)"IT MEM";

#endif /* LCD_ON */

/* Private function prototypes -----------------------------------------------*/
static void SystemClock_Config(void);
static void Tst_Report (float32_t snr);
static HAL_StatusTypeDef Enable_Flash_IT(void);

#ifdef PCROP_ON
static void PCROP_Config_Error(void);
static HAL_StatusTypeDef PCROP_Enable(void);
#endif

/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Called in case of HW initialization error
  * @param  None
  * @retval None
  */
void Error_Handler(void)
{
  while (1)
  {
    BSP_LED_Toggle(LED4);
    HAL_Delay(50);
  }
}
/**
  * @brief  Main program
  * @param  None
  * @retval None
  */
int main(void)
{
  float32_t  *inputF32, *outputF32, snr;
  /* Initialize input and output buffer pointers */
  inputF32 = &testInput_f32_1kHz_15kHz[0];
  outputF32 = &testOutput[0];

  /* STM32L4xx HAL library initialization:
       - Configure the Flash prefetch, Flash preread and Buffer caches
       - Systick timer is configured by default as source of time base, but user
         can eventually implement his proper time base source (a general purpose
         timer for example or other time source), keeping in mind that Time base
         duration should be kept 1ms since PPP_TIMEOUT_VALUEs are defined and
         handled in milliseconds basis.
       - Low Level Initialization
     */
  if (HAL_Init() != HAL_OK)
  {
    Error_Handler();
  }


  /* Configure the System clock to have a frequency of 4 MHz */
  SystemClock_Config();
  /* Enable IT on FLASH PCROP area read access*/
  /* This IT will  raise if PCROP code contains literal pools */
  if (Enable_Flash_IT() != HAL_OK)
  {
    Error_Handler();
  }


  /* HW Init: LED and LCD */
  BSP_LED_Init(LED4); /* NOK LED RED */
  BSP_LED_Init(LED5); /* OK LED GREEN */
  BSP_LED_Off(LED4);
  BSP_LED_Off(LED5);
#ifdef LCD_ON
  /* Initialize LCD and display welcome message */
  BSP_LCD_GLASS_Init();
  BSP_LCD_GLASS_ScrollSentence(msg_welcome, 1, 250);
#endif /* LCD_ON */


  /* Configure PCROP Area if not already done */
#ifdef PCROP_ON
  if (PCROP_Enable() == HAL_OK)
  {
    /* PCROP Configuration is SET */
#ifdef LCD_ON
    BSP_LCD_GLASS_DisplayString((uint8_t *)msg_pcrop_ok);
#endif /* LCD_ON */

    BSP_LED_On(LED4); /* Red LED means PCROP operation OK */
    HAL_Delay(2000);
  }
  else
  {
    PCROP_Config_Error();
  }
#endif /* PCROP_ON */

  /*Application code starts here */

  /* Filter input signal "inputF32", write output "outputF32" */
  FIR_lowpass_filter(inputF32, outputF32, TEST_LENGTH_SAMPLES);
  /* Compare the generated output against the reference output computed in MATLAB. */
  snr = arm_snr_f32(&refOutput[0], &testOutput[0], TEST_LENGTH_SAMPLES);

  /* Send snr value and check test status */
  Tst_Report(snr);

  return(0); /* Never reach this */
}

#ifdef PCROP_ON
/**
  * @brief  Enable PCROP and Write protection areas on specified code and data segments
  * @param  None
  * @retval HAL_StatusTypeDef
 *         - HAL_OK if PCROP is already enabled
 *         - HAL_ERROR if FLASH configuration failed
  */
HAL_StatusTypeDef PCROP_Enable(void)
{
  HAL_StatusTypeDef err;
  FLASH_OBProgramInitTypeDef pOBInit;

  /* Working on BANK1 for PCROP and first area of bank 1 for WRP */
  pOBInit.PCROPConfig = FLASH_BANK_1;
  pOBInit.WRPArea = OB_WRPAREA_BANK1_AREAA;

  /* Fetch all OB type configuration: WRP, RDP, USER and PCROP
   * This step is to check if protection are already set
  */
  HAL_FLASHEx_OBGetConfig(&pOBInit);

  /* Check if are is already protected */
  if (pOBInit.PCROPStartAddr < pOBInit.PCROPEndAddr)
  {
    return(HAL_OK);
  }

  /* Update OB for PCROP */
  pOBInit.OptionType = OPTIONBYTE_PCROP;
  pOBInit.PCROPConfig = FLASH_BANK_1 + PCROP_AREA_ERASED_POLICY;
  pOBInit.PCROPStartAddr = PCROP_AREA_START_ADDRESS; /* When write configuration, byte address is used.*/
  pOBInit.PCROPEndAddr = PCROP_AREA_END_ADDRESS;

#ifdef PCROP_CONST_DATA_WRP_ON
  /* Update OB for Write Protection */
  pOBInit.OptionType |= OPTIONBYTE_WRP;
  pOBInit.WRPStartOffset = 24; /* Included */
  pOBInit.WRPEndOffset = 24;
#endif

  /* Unlock FLASH and Option Byte before modify them */
  err = HAL_FLASH_Unlock();
  err |= HAL_FLASH_OB_Unlock();
  err |= HAL_FLASHEx_OBProgram(&pOBInit);

  /* If all is ok, next command trigs a system reset with updated OB */
  if (err == HAL_OK)
  {
    /* This function trig a system reset so that new
    * Option Bytes values are taken into account
    */
    HAL_FLASH_OB_Launch();
		return(HAL_OK); /* Never reach this */
  }
  else
  {
    return(HAL_ERROR);
  }
}

/**
  * @brief  Error handler called on FLASH protection configuration setting
  * @param  None
  * @retval None
 *         Continuous Green and Red  LED synchronous blinking
  */
static void PCROP_Config_Error(void)
{
  BSP_LCD_GLASS_Clear();
  BSP_LCD_GLASS_DisplayString((uint8_t *)msg_pcrop_err);

  BSP_LED_On(LED4);
  BSP_LED_On(LED5);
  while (1)
  {
    BSP_LED_Toggle(LED4);
    BSP_LED_Toggle(LED5);
    HAL_Delay(50);
  }
}
#endif /* PCROP_ON */

/**
  * @brief  Test result notification
  * @param  snr: snr value computed with filter outputs vs. expected output
  * @retval None
 *         Green LED blinking for tst ok
 *         Red LED blinking for tst not ok
  */
void Tst_Report (float32_t snr)
{
  arm_status status;

  /* Check SNR */
  if (snr < SNR_THRESHOLD_F32)
  {
    status = ARM_MATH_TEST_FAILURE;
  }
  else
  {
    status = ARM_MATH_SUCCESS;
  }
#ifdef LCD_ON
  /* Clear LCD and display the appropriate message */
  BSP_LCD_GLASS_Clear();
  if (status == ARM_MATH_TEST_FAILURE)
  {
    BSP_LCD_GLASS_DisplayString((uint8_t *)msg_tst_nok);
  }
  else
  {
    BSP_LCD_GLASS_DisplayString((uint8_t *)msg_tst_ok);
  }
#endif /* LCD_ON */

  /* Infinite loop */
  while (1)
  {
    if (status == ARM_MATH_TEST_FAILURE)
    {
      /* Toggle LED4 Red*/
      BSP_LED_Toggle(LED4);
      HAL_Delay(200);

    }
    else
    {
      /* Toggle LED5 Green*/
      BSP_LED_Toggle(LED5);
      HAL_Delay(200);
    }
  }
}
/**
  * @brief  System Clock Configuration
  *         The system Clock is configured as follows :
  *         System Clock source            = MSI
  *         SYSCLK(Hz)                     = 80000000
  *         HCLK(Hz)                       = 80000000
  *         AHB Prescaler                  = 1
  *         APB1 Prescaler                 = 1
  *         APB2 Prescaler                 = 1
  *         MSI Frequency(Hz)              = 4000000
  *         Flash Latency(WS)              = 4
  * @param  None
  * @retval None
  */
void SystemClock_Config(void)
{

  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_PeriphCLKInitTypeDef PeriphClkInit;

  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_MSI;
  RCC_OscInitStruct.MSIState = RCC_MSI_ON;
  RCC_OscInitStruct.MSICalibrationValue = 0;
  RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_6;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_MSI;
  RCC_OscInitStruct.PLL.PLLM = 1;
  RCC_OscInitStruct.PLL.PLLN = 40;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV7;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV4;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  HAL_RCC_OscConfig(&RCC_OscInitStruct);

  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
                                | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
  HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4);

  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_RNG;
  PeriphClkInit.RngClockSelection = RCC_RNGCLKSOURCE_PLL;
  HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit);

  __PWR_CLK_ENABLE();

  HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1);

  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq() / 1000);

  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

}

/**
  * @brief  Flash Operation Error Interrupt Enable
  * @param  None
  * @retval Error status
  */
HAL_StatusTypeDef Enable_Flash_IT(void)
{
  HAL_StatusTypeDef err;
  /* Allow Access to Flash control registers and user Falsh */
  err = HAL_FLASH_Unlock();
  /* Allow Access to option bytes sector */
  err |= HAL_FLASH_OB_Unlock();
  /* Set ERRor Interrupt Enable bit */
  FLASH->CR = FLASH_IT_ERR;
  /* Prevent Access to option bytes sector */
  err |= HAL_FLASH_OB_Lock();
  /* Disable the Flash option control register access (recommended to protect
  the option Bytes against possible unwanted operations) */
  err |= HAL_FLASH_Lock();

  /* Enable and set FLASH operation error Interrupt priority */
  HAL_NVIC_SetPriority((IRQn_Type)(FLASH_IRQn), 0x0E, 0x00);
  HAL_NVIC_EnableIRQ((IRQn_Type)(FLASH_IRQn));
  return(err);
}

/**
  * @brief  FLASH operation error interrupt callback
  * @param  ReturnValue: The value saved in this parameter depends on the ongoing procedure
  *         Mass Erase: Bank number which has been requested to erase
  *         Sectors Erase: Sector number which returned an error
  *         Program: Address which was selected for data program
  * @retval None
  */
void HAL_FLASH_OperationErrorCallback(uint32_t ReturnValue)
{
  /* Initiates a system reset request to reset the MCU */
#ifdef LCD_ON
  BSP_LCD_GLASS_Clear();
  BSP_LCD_GLASS_DisplayString((uint8_t *)msg_it);
#endif /* LCD_ON */
  BSP_LED_On(LED4);
  BSP_LED_On(LED5);
  while (1);
}


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

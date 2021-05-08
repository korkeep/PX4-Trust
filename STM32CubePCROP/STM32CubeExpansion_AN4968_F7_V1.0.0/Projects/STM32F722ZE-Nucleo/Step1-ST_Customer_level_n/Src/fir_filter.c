/**
  ******************************************************************************
  * @file    Step1-ST_Customer_level_n/Src/fir_filter.c 
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
#include "arm_math.h"
#include "fir_filter.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define BLOCK_SIZE            32
#define NUM_TAPS              29
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
 /* Declare State buffer of size (numTaps + blockSize - 1) */
 static float32_t firStateF32[BLOCK_SIZE + NUM_TAPS - 1];
 
 /* FIR Coefficients buffer generated using fir1() MATLAB function. */
#if defined ( __ICCARM__ ) /* IAR IDE */
const float32_t FirCoeffs32[NUM_TAPS] @ "fir_coef_section" = {	
#elif defined ( __CC_ARM ) /* KEIL IDE */
const float32_t FirCoeffs32[NUM_TAPS] __attribute__((section("fir_coef_section"))) = {
#elif defined ( __GNUC__ ) /* SW4STM32 IDE */
const float32_t FirCoeffs32[NUM_TAPS] __attribute__((section(".fir_coef_section"))) = {
#endif 
	
  -0.0018225230f, -0.0015879294f, +0.0000000000f, +0.0036977508f, +0.0080754303f, +0.0085302217f, -0.0000000000f, -0.0173976984f,
  -0.0341458607f, -0.0333591565f, +0.0000000000f, +0.0676308395f, +0.1522061835f, +0.2229246956f, +0.2504960933f, +0.2229246956f,
  +0.1522061835f, +0.0676308395f, +0.0000000000f, -0.0333591565f, -0.0341458607f, -0.0173976984f, -0.0000000000f, +0.0085302217f,
  +0.0080754303f, +0.0036977508f, +0.0000000000f, -0.0015879294f, -0.0018225230f
};


/**
  * @brief  FIR LPF Function
  * @param  Input buffer
  * @param  Output buffer
  * @param  Samples length
  * @retval None
  */
void FIR_lowpass_filter(float32_t * pSrc, float32_t * pDst, uint32_t testlengthsamples)
{
  uint32_t index = 0;
  uint32_t block_size = BLOCK_SIZE;
  uint32_t num_blocks = testlengthsamples/BLOCK_SIZE;
  arm_fir_instance_f32 S;

  
  /* Call FIR init function to initialize the instance structure. */
  arm_fir_init_f32(&S, NUM_TAPS, (float32_t *)&FirCoeffs32[0], &firStateF32[0], block_size);

	/* Call the FIR process function for every blockSize samples */
  for(index=0; index < num_blocks; index++)
  {
    arm_fir_f32(&S, pSrc + (index * block_size), pDst + (index * block_size), block_size);
  }
	
}

/************************************************************************************
 * nuttx-configs/px4trust_nucleo/include/board.h
 *
 *   Copyright (C) 2021 Kim Sungsu. All rights reserved.
 *   Authors: Kim Sungsu <korkeep@naver.com>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

#ifndef __BOARDS_ARM_STM32H7_NUCLEO_H743ZI_INCLUDE_BOARD_H
#define __BOARDS_ARM_STM32H7_NUCLEO_H743ZI_INCLUDE_BOARD_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#ifndef __ASSEMBLY__
# include <stdint.h>
#endif

#include "stm32_rcc.h"
#include "stm32_sdmmc.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* Clocking *****************************************************************/

/* The Nucleo-144  board provides the following clock sources:
 *
 *   MCO: 8 MHz from MCO output of ST-LINK is used as input clock (default)
 *   X2:  32.768 KHz crystal for LSE
 *   X3:  HSE crystal oscillator (not provided)
 *
 * So we have these clock source available within the STM32
 *
 *   HSI: 16 MHz RC factory-trimmed
 *   LSI: 32 KHz RC
 *   HSE: 8 MHz from MCO output of ST-LINK
 *   LSE: 32.768 kHz
 */

#define STM32_BOARD_XTAL        8000000ul /* ST-LINK MCO */

#define STM32_HSI_FREQUENCY     16000000ul
#define STM32_LSI_FREQUENCY     32000
#define STM32_HSE_FREQUENCY     STM32_BOARD_XTAL
#define STM32_LSE_FREQUENCY     32768

/* Main PLL Configuration.
 *
 * PLL source is HSE = 8,000,000
 *
 * To use HSE, configure the solder bridges on the board:
 *
 *  - SB148, SB8 and SB9 OFF
 *  - SB112 and SB149 ON
 *
 * When STM32_HSE_FREQUENCY / PLLM <= 2MHz VCOL must be selected.
 * VCOH otherwise.
 *
 * PLL_VCOx = (STM32_HSE_FREQUENCY / PLLM) * PLLN
 * Subject to:
 *
 *     1 <= PLLM <= 63
 *     4 <= PLLN <= 512
 *   150 MHz <= PLL_VCOL <= 420MHz
 *   192 MHz <= PLL_VCOH <= 836MHz
 *
 * SYSCLK  = PLL_VCO / PLLP
 * CPUCLK  = SYSCLK / D1CPRE
 * Subject to
 *
 *   PLLP1   = {2, 4, 6, 8, ..., 128}
 *   PLLP2,3 = {2, 3, 4, ..., 128}
 *   CPUCLK <= 400 MHz
 */

#define STM32_BOARD_USEHSE
#define STM32_HSEBYP_ENABLE

#define STM32_PLLCFG_PLLSRC      RCC_PLLCKSELR_PLLSRC_HSE

/* PLL1, wide 4 - 8 MHz input, enable DIVP, DIVQ, DIVR
 *
 *   PLL1_VCO = (8,000,000 / 2) * 200 = 800 MHz
 *
 *   PLL1P = PLL1_VCO/2  = 800 MHz / 2   = 400 MHz
 *   PLL1Q = PLL1_VCO/4  = 800 MHz / 4   = 200 MHz
 *   PLL1R = PLL1_VCO/8  = 800 MHz / 8   = 100 MHz
 */

#define STM32_PLLCFG_PLL1CFG     (RCC_PLLCFGR_PLL1VCOSEL_WIDE | \
                                  RCC_PLLCFGR_PLL1RGE_4_8_MHZ | \
                                  RCC_PLLCFGR_DIVP1EN | \
                                  RCC_PLLCFGR_DIVQ1EN | \
                                  RCC_PLLCFGR_DIVR1EN)
#define STM32_PLLCFG_PLL1M       RCC_PLLCKSELR_DIVM1(2)
#define STM32_PLLCFG_PLL1N       RCC_PLL1DIVR_N1(200)
#define STM32_PLLCFG_PLL1P       RCC_PLL1DIVR_P1(2)
#define STM32_PLLCFG_PLL1Q       RCC_PLL1DIVR_Q1(4)
#define STM32_PLLCFG_PLL1R       RCC_PLL1DIVR_R1(8)

#define STM32_VCO1_FREQUENCY     ((STM32_HSE_FREQUENCY / 2) * 200)
#define STM32_PLL1P_FREQUENCY    (STM32_VCO1_FREQUENCY / 2)
#define STM32_PLL1Q_FREQUENCY    (STM32_VCO1_FREQUENCY / 4)
#define STM32_PLL1R_FREQUENCY    (STM32_VCO1_FREQUENCY / 8)

/* PLL2 */

#define STM32_PLLCFG_PLL2CFG (RCC_PLLCFGR_PLL2VCOSEL_WIDE | \
                              RCC_PLLCFGR_PLL2RGE_4_8_MHZ | \
                              RCC_PLLCFGR_DIVP2EN)
#define STM32_PLLCFG_PLL2M       RCC_PLLCKSELR_DIVM2(2)
#define STM32_PLLCFG_PLL2N       RCC_PLL2DIVR_N2(200)
#define STM32_PLLCFG_PLL2P       RCC_PLL2DIVR_P2(40)
#define STM32_PLLCFG_PLL2Q       0
#define STM32_PLLCFG_PLL2R       0

#define STM32_VCO2_FREQUENCY     ((STM32_HSE_FREQUENCY / 2) * 200)
#define STM32_PLL2P_FREQUENCY    (STM32_VCO2_FREQUENCY / 2)
#define STM32_PLL2Q_FREQUENCY
#define STM32_PLL2R_FREQUENCY

/* PLL3 */

#define STM32_PLLCFG_PLL3CFG 0
#define STM32_PLLCFG_PLL3M   0
#define STM32_PLLCFG_PLL3N   0
#define STM32_PLLCFG_PLL3P   0
#define STM32_PLLCFG_PLL3Q   0
#define STM32_PLLCFG_PLL3R   0

#define STM32_VCO3_FREQUENCY
#define STM32_PLL3P_FREQUENCY
#define STM32_PLL3Q_FREQUENCY
#define STM32_PLL3R_FREQUENCY

/* SYSCLK = PLL1P = 400 MHz
 * CPUCLK = SYSCLK / 1 = 400 MHz
 */

#define STM32_RCC_D1CFGR_D1CPRE  (RCC_D1CFGR_D1CPRE_SYSCLK)
#define STM32_SYSCLK_FREQUENCY   (STM32_PLL1P_FREQUENCY)
#define STM32_CPUCLK_FREQUENCY   (STM32_SYSCLK_FREQUENCY / 1)

/* Configure Clock Assignments */

/* AHB clock (HCLK) is SYSCLK/2 (200 MHz max)
 * HCLK1 = HCLK2 = HCLK3 = HCLK4
 */

#define STM32_RCC_D1CFGR_HPRE   RCC_D1CFGR_HPRE_SYSCLKd2        /* HCLK  = SYSCLK / 2 */
#define STM32_ACLK_FREQUENCY    (STM32_CPUCLK_FREQUENCY / 2)    /* ACLK in D1, HCLK3 in D1 */
#define STM32_HCLK_FREQUENCY    (STM32_CPUCLK_FREQUENCY / 2)    /* HCLK in D2, HCLK4 in D3 */

/* APB1 clock (PCLK1) is HCLK/4 (54 MHz) */

#define STM32_RCC_D2CFGR_D2PPRE1  RCC_D2CFGR_D2PPRE1_HCLKd4       /* PCLK1 = HCLK / 4 */
#define STM32_PCLK1_FREQUENCY     (STM32_HCLK_FREQUENCY/4)

/* APB2 clock (PCLK2) is HCLK/4 (54 MHz) */

#define STM32_RCC_D2CFGR_D2PPRE2  RCC_D2CFGR_D2PPRE2_HCLKd4       /* PCLK2 = HCLK / 4 */
#define STM32_PCLK2_FREQUENCY     (STM32_HCLK_FREQUENCY/4)

/* APB3 clock (PCLK3) is HCLK/4 (54 MHz) */

#define STM32_RCC_D1CFGR_D1PPRE   RCC_D1CFGR_D1PPRE_HCLKd4        /* PCLK3 = HCLK / 4 */
#define STM32_PCLK3_FREQUENCY     (STM32_HCLK_FREQUENCY/4)

/* APB4 clock (PCLK4) is HCLK/4 (54 MHz) */

#define STM32_RCC_D3CFGR_D3PPRE   RCC_D3CFGR_D3PPRE_HCLKd4       /* PCLK4 = HCLK / 4 */
#define STM32_PCLK4_FREQUENCY     (STM32_HCLK_FREQUENCY/4)

/* Timer clock frequencies */

/* Timers driven from APB1 will be twice PCLK1 */

#define STM32_APB1_TIM2_CLKIN   (2*STM32_PCLK1_FREQUENCY)
#define STM32_APB1_TIM3_CLKIN   (2*STM32_PCLK1_FREQUENCY)
#define STM32_APB1_TIM4_CLKIN   (2*STM32_PCLK1_FREQUENCY)
#define STM32_APB1_TIM5_CLKIN   (2*STM32_PCLK1_FREQUENCY)
#define STM32_APB1_TIM6_CLKIN   (2*STM32_PCLK1_FREQUENCY)
#define STM32_APB1_TIM7_CLKIN   (2*STM32_PCLK1_FREQUENCY)
#define STM32_APB1_TIM12_CLKIN  (2*STM32_PCLK1_FREQUENCY)
#define STM32_APB1_TIM13_CLKIN  (2*STM32_PCLK1_FREQUENCY)
#define STM32_APB1_TIM14_CLKIN  (2*STM32_PCLK1_FREQUENCY)

/* Timers driven from APB2 will be twice PCLK2 */

#define STM32_APB2_TIM1_CLKIN   (2*STM32_PCLK2_FREQUENCY)
#define STM32_APB2_TIM8_CLKIN   (2*STM32_PCLK2_FREQUENCY)
#define STM32_APB2_TIM15_CLKIN  (2*STM32_PCLK2_FREQUENCY)
#define STM32_APB2_TIM16_CLKIN  (2*STM32_PCLK2_FREQUENCY)
#define STM32_APB2_TIM17_CLKIN  (2*STM32_PCLK2_FREQUENCY)

/* Kernel Clock Configuration
 *
 * Note: look at Table 54 in ST Manual
 */

/* I2C123 clock source - HSI */

#define STM32_RCC_D2CCIP2R_I2C123SRC RCC_D2CCIP2R_I2C123SEL_HSI

/* I2C4 clock source - HSI */

#define STM32_RCC_D3CCIPR_I2C4SRC    RCC_D3CCIPR_I2C4SEL_HSI

/* SPI123 clock source - PLL1Q */

#define STM32_RCC_D2CCIP1R_SPI123SRC RCC_D2CCIP1R_SPI123SEL_PLL1

/* SPI45 clock source - APB (PCLK2?) */

#define STM32_RCC_D2CCIP1R_SPI45SRC  RCC_D2CCIP1R_SPI45SEL_APB

/* SPI6 clock source - APB (PCLK4) */

#define STM32_RCC_D3CCIPR_SPI6SRC    RCC_D3CCIPR_SPI6SEL_PCLK4

/* USB 1 and 2 clock source - HSI48 */

#define STM32_RCC_D2CCIP2R_USBSRC    RCC_D2CCIP2R_USBSEL_HSI48

/* ADC 1 2 3 clock source - pll2_pclk */

#define STM32_RCC_D3CCIPR_ADCSEL     RCC_D3CCIPR_ADCSEL_PLL2

/* CAN FD clock source */

#define STM32_FDCANCLK               STM32_HSE_FREQUENCY

/* FLASH wait states
 *
 *  ------------ ---------- -----------
 *  Vcore        MAX ACLK   WAIT STATES
 *  ------------ ---------- -----------
 *  1.15-1.26 V     70 MHz    0
 *  (VOS1 level)   140 MHz    1
 *                 210 MHz    2
 *  1.05-1.15 V     55 MHz    0
 *  (VOS2 level)   110 MHz    1
 *                 165 MHz    2
 *                 220 MHz    3
 *  0.95-1.05 V     45 MHz    0
 *  (VOS3 level)    90 MHz    1
 *                 135 MHz    2
 *                 180 MHz    3
 *                 225 MHz    4
 *  ------------ ---------- -----------
 */

#define BOARD_FLASH_WAITSTATES 4

/* SDMMC definitions ********************************************************/

/* Init 400kHz, PLL1Q/(2*250) */

#define STM32_SDMMC_INIT_CLKDIV     (250 << STM32_SDMMC_CLKCR_CLKDIV_SHIFT)

/* Just set these to 25 MHz for now,
 * PLL1Q/(2*4), for default speed 12.5MB/s
 */

#define STM32_SDMMC_MMCXFR_CLKDIV   (4 << STM32_SDMMC_CLKCR_CLKDIV_SHIFT)
#define STM32_SDMMC_SDXFR_CLKDIV    (4 << STM32_SDMMC_CLKCR_CLKDIV_SHIFT)

#define STM32_SDMMC_CLKCR_EDGE      STM32_SDMMC_CLKCR_NEGEDGE

/* Ethernet definitions *****************************************************/

// #define GPIO_ETH_RMII_TXD0    GPIO_ETH_RMII_TXD0_2    /* PG13 */
// #define GPIO_ETH_RMII_TXD1    GPIO_ETH_RMII_TXD1_1    /* PB 13 */
// #define GPIO_ETH_RMII_TX_EN   GPIO_ETH_RMII_TX_EN_2

/* LED definitions **********************************************************/

/* The Nucleo-144 board has numerous LEDs but only three, LD1 a Green LED,
 * LD2 a Blue LED and LD3 a Red LED, that can be controlled by software.
 * The following definitions assume the default Solder Bridges are installed.
 *
 * If CONFIG_ARCH_LEDS is not defined, then the user can control the LEDs in
 * any way.
 * The following definitions are used to access individual LEDs.
 */

/* LED index values for use with board_userled() */

#define BOARD_LED1        0
#define BOARD_LED2        1
#define BOARD_LED3        2
#define BOARD_NLEDS       3

#define BOARD_LED_GREEN   BOARD_LED1
#define BOARD_LED_BLUE    BOARD_LED2
#define BOARD_LED_RED     BOARD_LED3

/* LED bits for use with board_userled_all() */

#define BOARD_LED1_BIT    (1 << BOARD_LED1)
#define BOARD_LED2_BIT    (1 << BOARD_LED2)
#define BOARD_LED3_BIT    (1 << BOARD_LED3)

/* If CONFIG_ARCH_LEDS is defined, the usage by the board port is defined in
 * include/board.h and src/stm32_leds.c.
 * The LEDs are used to encode OS-related events as follows:
 *
 *
 *   SYMBOL                     Meaning                      LED state
 *                                                        Red   Green Blue
 *   ----------------------  --------------------------  ------ ------ ---
 */

#define LED_STARTED        0 /* NuttX has been started   OFF    OFF   OFF  */
#define LED_HEAPALLOCATE   1 /* Heap has been allocated  OFF    OFF   ON   */
#define LED_IRQSENABLED    2 /* Interrupts enabled       OFF    ON    OFF  */
#define LED_STACKCREATED   3 /* Idle stack created       OFF    ON    ON   */
#define LED_INIRQ          4 /* In an interrupt          N/C    N/C   GLOW */
#define LED_SIGNAL         5 /* In a signal handler      N/C    GLOW  N/C  */
#define LED_ASSERTION      6 /* An assertion failed      GLOW   N/C   GLOW */
#define LED_PANIC          7 /* The system has crashed   Blink  OFF   N/C  */
#define LED_IDLE           8 /* MCU is is sleep mode     ON     OFF   OFF  */

/* Thus if the Green LED is statically on, NuttX has successfully booted and
 * is, apparently, running normally.  If the Red LED is flashing at
 * approximately 2Hz, then a fatal error has been detected and the system
 * has halted.
 */

/* Button definitions *******************************************************/

/* The NUCLEO board supports one button:  Pushbutton B1, labeled "User", is
 * connected to GPIO PI11.
 * A high value will be sensed when the button is depressed.
 */

#define BUTTON_USER        0
#define NUM_BUTTONS        1
#define BUTTON_USER_BIT    (1 << BUTTON_USER)

/* Alternate function pin selections ****************************************/

/* PX4 FMUv6u Peripheral: UART */
#define GPIO_USART1_RX   GPIO_USART1_RX_3       /* PB7  */
#define GPIO_USART1_TX   GPIO_USART1_TX_3       /* PB6  */

#define GPIO_USART2_RX   GPIO_USART2_RX_2       /* PD6  */
#define GPIO_USART2_TX   GPIO_USART2_TX_2       /* PD5  */
#define GPIO_USART2_RTS  GPIO_USART2_RTS_2      /* PD4  */
#define GPIO_USART2_CTS  GPIO_USART2_CTS_NSS_2  /* PD3  */

#define GPIO_USART3_RX   GPIO_USART3_RX_3       /* PD9  */
#define GPIO_USART3_TX   GPIO_USART3_TX_3       /* PD8  */

#define GPIO_UART4_RX    GPIO_UART4_RX_6        /* PH14 */
#define GPIO_UART4_TX    GPIO_UART4_TX_6        /* PH13 */

#define GPIO_UART5_RX    GPIO_UART5_RX_3        /* PD2  */
#define GPIO_UART5_TX    GPIO_UART5_TX_3        /* PC12 */

#define GPIO_USART6_RX   GPIO_USART6_RX_1       /* PC7  */
#define GPIO_USART6_TX   GPIO_USART6_TX_1       /* PC6  */

#define GPIO_UART7_RX    GPIO_UART7_RX_4        /* PF6  */
#define GPIO_UART7_TX    GPIO_UART7_TX_3        /* PE8  */
#define GPIO_UART7_RTS   GPIO_UART7_RTS_2       /* PF8  */
#define GPIO_UART7_CTS   GPIO_UART7_CTS_1       /* PE10 */

#define GPIO_UART8_RX    GPIO_UART8_RX_1        /* PE0  */
#define GPIO_UART8_TX    GPIO_UART8_TX_1        /* PE1  */

/* USART3 (Nucleo Virtual Console) */

// #define GPIO_USART3_RX     GPIO_USART3_RX_3  /* PD9 */
// #define GPIO_USART3_TX     GPIO_USART3_TX_3  /* PD8 */

// #define DMAMAP_USART3_RX DMAMAP_DMA12_USART3RX_0
// #define DMAMAP_USART3_TX DMAMAP_DMA12_USART3TX_1

/* USART6 (Arduino Serial Shield) */

// #define GPIO_USART6_RX     GPIO_USART6_RX_2  /* PG9 */
// #define GPIO_USART6_TX     GPIO_USART6_TX_2  /* PG14 */

// #define DMAMAP_USART6_RX DMAMAP_DMA12_USART6RX_1
// #define DMAMAP_USART6_TX DMAMAP_DMA12_USART6TX_0

/* PX4 FMUv6u Peripheral: CAN
 * CAN1 is routed to transceiver.
 * CAN2 is routed to transceiver.
 */
#define GPIO_CAN1_RX     GPIO_CAN1_RX_3     /* PD0  */
#define GPIO_CAN1_TX     GPIO_CAN1_TX_3     /* PD1  */

/* PX4 FMUv6u Peripheral: SPI
 * SPI1 is sensors1
 * SPI2 is sensors2
 * SPI3 is sensors3
 * SPI4 is Not Used
 * SPI5 is FRAM
 * SPI6 is EXTERNAL1
 */
#define ADJ_SLEW_RATE(p) (((p) & ~GPIO_SPEED_MASK) | (GPIO_SPEED_2MHz))

#define GPIO_SPI1_MISO   GPIO_SPI1_MISO_3               /* PG9  */
#define GPIO_SPI1_MOSI   GPIO_SPI1_MOSI_1               /* PA7  */
#define GPIO_SPI1_SCK    ADJ_SLEW_RATE(GPIO_SPI1_SCK_3) /* PG11 */

#define GPIO_SPI2_MISO   GPIO_SPI2_MISO_3               /* PI2  */
#define GPIO_SPI2_MOSI   GPIO_SPI2_MOSI_4               /* PI3  */
#define GPIO_SPI2_SCK    ADJ_SLEW_RATE(GPIO_SPI2_SCK_6) /* PI1  */

#define GPIO_SPI3_MISO   GPIO_SPI3_MISO_2               /* PC11 */
#define GPIO_SPI3_MOSI   GPIO_SPI3_MOSI_3               /* PB2  */
#define GPIO_SPI3_SCK    ADJ_SLEW_RATE(GPIO_SPI3_SCK_2) /* PC10 */

#define GPIO_SPI5_MISO   GPIO_SPI5_MISO_2               /* PH7  */
#define GPIO_SPI5_MOSI   GPIO_SPI5_MOSI_1               /* PF11 */
#define GPIO_SPI5_SCK    ADJ_SLEW_RATE(GPIO_SPI5_SCK_1) /* PF7  */

#define GPIO_SPI6_MISO   GPIO_SPI6_MISO_2               /* PA6  */
#define GPIO_SPI6_MOSI   GPIO_SPI6_MOSI_1               /* PG14 */
#define GPIO_SPI6_SCK    ADJ_SLEW_RATE(GPIO_SPI6_SCK_1) /* PG13 */

/* SPI3 */

// #define GPIO_SPI3_MISO GPIO_SPI3_MISO_1 /* PB4 */
// #define GPIO_SPI3_MOSI GPIO_SPI3_MOSI_4 /* PB5 */
// #define GPIO_SPI3_SCK  GPIO_SPI3_SCK_1  /* PB3 */
// #define GPIO_SPI3_NSS  GPIO_SPI3_NSS_2  /* PA4 */


/* PX4 FMUv6u Peripheral: I2C */
#define GPIO_I2C1_SCL GPIO_I2C1_SCL_2       /* PB8  */
#define GPIO_I2C1_SDA GPIO_I2C1_SDA_2       /* PB9  */

#define GPIO_I2C1_SCL_GPIO                  (GPIO_OUTPUT | GPIO_OPENDRAIN |GPIO_SPEED_50MHz | GPIO_OUTPUT_SET | GPIO_PORTB | GPIO_PIN8)
#define GPIO_I2C1_SDA_GPIO                  (GPIO_OUTPUT | GPIO_OPENDRAIN |GPIO_SPEED_50MHz | GPIO_OUTPUT_SET | GPIO_PORTB | GPIO_PIN9)

#define GPIO_I2C2_SCL GPIO_I2C2_SCL_2       /* PF1 */
#define GPIO_I2C2_SDA GPIO_I2C2_SDA_2       /* PF0 */

#define GPIO_I2C2_SCL_GPIO                  (GPIO_OUTPUT | GPIO_OPENDRAIN |GPIO_SPEED_50MHz | GPIO_OUTPUT_SET | GPIO_PORTF | GPIO_PIN1)
#define GPIO_I2C2_SDA_GPIO                  (GPIO_OUTPUT | GPIO_OPENDRAIN |GPIO_SPEED_50MHz | GPIO_OUTPUT_SET | GPIO_PORTF | GPIO_PIN0)

#define GPIO_I2C3_SCL GPIO_I2C3_SCL_1       /* PA8 */
#define GPIO_I2C3_SDA GPIO_I2C3_SDA_2       /* PH8 */

#define GPIO_I2C3_SCL_GPIO                  (GPIO_OUTPUT | GPIO_OPENDRAIN |GPIO_SPEED_50MHz | GPIO_OUTPUT_SET | GPIO_PORTA | GPIO_PIN8)
#define GPIO_I2C3_SDA_GPIO                  (GPIO_OUTPUT | GPIO_OPENDRAIN |GPIO_SPEED_50MHz | GPIO_OUTPUT_SET | GPIO_PORTH | GPIO_PIN8)

#define GPIO_I2C4_SCL GPIO_I2C4_SCL_2       /* PF14 */
#define GPIO_I2C4_SDA GPIO_I2C4_SDA_2       /* PF15 */

#define GPIO_I2C4_SCL_GPIO                  (GPIO_OUTPUT | GPIO_OPENDRAIN | GPIO_SPEED_50MHz | GPIO_OUTPUT_SET | GPIO_PORTF | GPIO_PIN14)
#define GPIO_I2C4_SDA_GPIO                  (GPIO_OUTPUT | GPIO_OPENDRAIN | GPIO_SPEED_50MHz | GPIO_OUTPUT_SET | GPIO_PORTF | GPIO_PIN15)

/* PX4 FMUv6u Peripheral: SDMMC2 
 *      VDD 3.3
 *      GND
 *      SDMMC2_CK                           PD6
 *      SDMMC2_CMD                          PD7
 *      SDMMC2_D0                           PB14
 *      SDMMC2_D1                           PB15
 *      SDMMC2_D2                           PG11
 *      SDMMC2_D3                           PB4
*/
#define GPIO_SDMMC2_CK   GPIO_SDMMC2_CK_2  /* PC1 */
#define GPIO_SDMMC2_CMD  GPIO_SDMMC2_CMD_1 /* PD7 */
#define GPIO_SDMMC2_D2   GPIO_SDMMC2_D2_2  /* PB3 */

/* I2C1 Use Nucleo I2C1 pins */

// #define GPIO_I2C1_SCL GPIO_I2C1_SCL_2 /* PB8 - D15 */
// #define GPIO_I2C1_SDA GPIO_I2C1_SDA_2 /* PB9 - D14 */

/* I2C2 Use Nucleo I2C2 pins */

// #define GPIO_I2C2_SCL  GPIO_I2C2_SCL_2  /* PF1 - D69 */
// #define GPIO_I2C2_SDA  GPIO_I2C2_SDA_2  /* PF0 - D68 */
// #define GPIO_I2C2_SMBA GPIO_I2C2_SMBA_2 /* PF2 - D70 */

/* TIM1 */

// #define GPIO_TIM1_CH1OUT  GPIO_TIM1_CH1OUT_2  /* PE9  - D6 */
// #define GPIO_TIM1_CH1NOUT GPIO_TIM1_CH1NOUT_3 /* PE8  - D42 */
// #define GPIO_TIM1_CH2OUT  GPIO_TIM1_CH2OUT_2  /* PE11 - D5 */
// #define GPIO_TIM1_CH2NOUT GPIO_TIM1_CH2NOUT_3 /* PE10 - D40 */
// #define GPIO_TIM1_CH3OUT  GPIO_TIM1_CH3OUT_2  /* PE13 - D3 */
// #define GPIO_TIM1_CH3NOUT GPIO_TIM1_CH3NOUT_3 /* PE12 - D39 */
// #define GPIO_TIM1_CH4OUT  GPIO_TIM1_CH4OUT_2  /* PE14 - D38 */

/* PX4 FMUv6u Peripheral: DMA */
// DMAMUX1
#define DMAMAP_SPI1_RX    DMAMAP_DMA12_SPI1RX_0 /* DMA1:37 */
#define DMAMAP_SPI1_TX    DMAMAP_DMA12_SPI1TX_0 /* DMA1:38 */
#define DMAMAP_SPI2_RX    DMAMAP_DMA12_SPI2RX_0 /* DMA1:39 */
#define DMAMAP_SPI2_TX    DMAMAP_DMA12_SPI2TX_0 /* DMA1:40 */

// DMAMUX2
#define DMAMAP_SPI3_RX    DMAMAP_DMA12_SPI3RX_1 /* DMA2:61 */
#define DMAMAP_SPI3_TX    DMAMAP_DMA12_SPI3TX_1 /* DMA2:62 */
#define DMAMAP_SPI6_RX    DMAMAP_BDMA_SPI6_RX /* BDMA:11 */
#define DMAMAP_SPI6_TX    DMAMAP_BDMA_SPI6_TX /* BDMA:12 */

/* DMA **********************************************************************/

// #define DMAMAP_SPI3_RX DMAMAP_DMA12_SPI3RX_0 /* DMA1 */
// #define DMAMAP_SPI3_TX DMAMAP_DMA12_SPI3TX_0 /* DMA1 */

/****************************************************************************
 * Public Data
 ****************************************************************************/

#ifndef __ASSEMBLY__

#undef EXTERN
#if defined(__cplusplus)
#define EXTERN extern "C"
extern "C"
{
#else
#define EXTERN extern
#endif

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/

#undef EXTERN
#if defined(__cplusplus)
}
#endif

#endif /* __ASSEMBLY__ */
#endif /* __BOARDS_ARM_STM32H7_NUCLEO_H743ZI_INCLUDE_BOARD_H */


/* PX4 FMUv6u Peripheral: Board provides GPIO or other Hardware for signaling to timing analyzer */

#if defined(CONFIG_BOARD_USE_PROBES)
# include "stm32_gpio.h"
# define PROBE_N(n) (1<<((n)-1))
# define PROBE_1    (GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_2MHz|GPIO_OUTPUT_CLEAR|GPIO_PORTI|GPIO_PIN0)   /* PI0 AUX1 */
# define PROBE_2    (GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_2MHz|GPIO_OUTPUT_CLEAR|GPIO_PORTH|GPIO_PIN12)  /* PH12 AUX2 */
# define PROBE_3    (GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_2MHz|GPIO_OUTPUT_CLEAR|GPIO_PORTH|GPIO_PIN11)  /* PH11 AUX3 */
# define PROBE_4    (GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_2MHz|GPIO_OUTPUT_CLEAR|GPIO_PORTH|GPIO_PIN10)  /* PH10 AUX4 */
# define PROBE_5    (GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_2MHz|GPIO_OUTPUT_CLEAR|GPIO_PORTD|GPIO_PIN13)  /* PD13 AUX5 */
# define PROBE_6    (GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_2MHz|GPIO_OUTPUT_CLEAR|GPIO_PORTD|GPIO_PIN14)  /* PD14 AUX6 */
# define PROBE_7    (GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_2MHz|GPIO_OUTPUT_CLEAR|GPIO_PORTH|GPIO_PIN6)   /* PH6  AUX7 */
# define PROBE_8    (GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_2MHz|GPIO_OUTPUT_CLEAR|GPIO_PORTH|GPIO_PIN9)   /* PH9  AUX8 */
# define PROBE_9    (GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_2MHz|GPIO_OUTPUT_CLEAR|GPIO_PORTE|GPIO_PIN11)  /* PE11  CAP1 */

# define PROBE_INIT(mask) \
	do { \
		if ((mask)& PROBE_N(1)) { stm32_configgpio(PROBE_1); } \
		if ((mask)& PROBE_N(2)) { stm32_configgpio(PROBE_2); } \
		if ((mask)& PROBE_N(3)) { stm32_configgpio(PROBE_3); } \
		if ((mask)& PROBE_N(4)) { stm32_configgpio(PROBE_4); } \
		if ((mask)& PROBE_N(5)) { stm32_configgpio(PROBE_5); } \
		if ((mask)& PROBE_N(6)) { stm32_configgpio(PROBE_6); } \
		if ((mask)& PROBE_N(7)) { stm32_configgpio(PROBE_7); } \
		if ((mask)& PROBE_N(8)) { stm32_configgpio(PROBE_8); } \
		if ((mask)& PROBE_N(9)) { stm32_configgpio(PROBE_9); } \
	} while(0)

# define PROBE(n,s)  do {stm32_gpiowrite(PROBE_##n,(s));}while(0)
# define PROBE_MARK(n) PROBE(n,false);PROBE(n,true)
#else
# define PROBE_INIT(mask)
# define PROBE(n,s)
# define PROBE_MARK(n)
#endif
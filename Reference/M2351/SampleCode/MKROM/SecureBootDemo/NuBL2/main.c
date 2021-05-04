/**************************************************************************//**
 * @file     main.c
 * @version  V3.00
 * @brief    Demonstrate how to generate a boot image(NuBL2) and can be authenticated by Secure Bootloader(NuBL1).
 *           After NuBL2 runs, NuBL2 will authenticate NuBL32 and NuBL33 then jump to execute in NuBL32.
 *
 * @copyright (C) 2018 Nuvoton Technology Corp. All rights reserved.
 ******************************************************************************/
#include <stdio.h>
#include <string.h>
#include "NuMicro.h"
#include "NuBL2.h"

#define SET_SECURE_BOOT     (0) // Set 1 to support modify CFG0[5] MBS 0 for booting from Secure Bootloader 
#define ENABLE_XOM0_REGION  (0) // Set 1 to configure VerifyNuBL3x.c code in XOM0 region, and cannot trace VerifyNuBL3x.c flow in ICE debug mode


static volatile FW_INFO_T  s_NuBL3xFwInfo; // Allocate a FWINFO buffer for storing NuBL32/NuBL33 FWINFO data

void EnableXOM0(void);
void SYS_Init(void);
void UART_Init(void);

/*---------------------------------------------------------------------------------------------------------*/
/*  Check Booting status and show F/W info data                                                            */
/*---------------------------------------------------------------------------------------------------------*/
static int32_t CheckBootingStatus(void)
{
    uint32_t     i;
    uint32_t    u32CFG0, au32OTP[8];
    uint32_t    *pu32Info, u32Size;
        
    /* Unlock protected registers */
    SYS_UnlockReg();

    /* Enable FMC ISP function */
    FMC_ENABLE_ISP();
    
    u32CFG0 = FMC_Read(FMC_USER_CONFIG_0);
    printf("Current CFG0: 0x%x.\n\n", u32CFG0);
    
    if((u32CFG0&BIT5) == BIT5)
    {              
        printf("Device is booting from %s. NOT booting from Secure Bootloader(NuBL1).\n\n", 
            FMC_GetBootSource()==0?"APROM":"LDROM");
        
#if (SET_SECURE_BOOT == 1) // enable to configure booting from Secure Bootloader
        {
            char ch;
            printf("Hit [S/s] to configure booting from Secure Bootloader(NuBL1).\n\n");
            ch = getchar();
            if((ch == 's') || (ch == 'S'))
            {
                FMC_ENABLE_CFG_UPDATE();
                FMC_Write(FMC_USER_CONFIG_0, (u32CFG0&~BIT5));
                
                /* Reset chip to enable booting from Secure Bootloader. */
                SYS_ResetChip();
                while(1) {};
            }
        }
#endif        

        return -1;
    }
    
    printf("[Device is successfully booting from Secure Bootloader(NuBL1) and device PID is 0x%08x]\n\n", FMC_ReadPID());
    
    /*
        Notes of NuBL2 ECC public key and its SHA-256 Key hash:
        * Public Key 1 = 755B3819F05A3E9F32D4D599062834AAC5220F75955378414A8F63716A152CE2
          Public Key 2 = 91C413F1915ED7B47473FD797647BA3D83E8224377909AF5B30C530EAAD79FD7
        * The Key hash = 145e73e48865222fa4d9741671c0c670ed45fe06b24cdb5dd507d7ab35ee9363
        * Stored in M2351 OTP0~3 for identification in secure boot are: 
                Index   Low word    High word
            --------------------------------------
                OTP0:   0xe4735e14, 0x2f226588
                OTP1:   0x1674d9a4, 0x70c6c071
                OTP2:   0x06fe45ed, 0x5ddb4cb2
                OTP3:   0xabd707d5, 0x6393ee35
    */
    
    /* Read NuBL2 ECC public key hash */
    FMC_Read_OTP(0, &au32OTP[0], &au32OTP[1]);
    FMC_Read_OTP(1, &au32OTP[2], &au32OTP[3]);
    FMC_Read_OTP(2, &au32OTP[4], &au32OTP[5]);
    FMC_Read_OTP(3, &au32OTP[6], &au32OTP[7]);
    printf("NuBL2 ECC public key hash are:\n");
    for(i=0; i<8; i++)
    {
        printf("    0x%08x\n", au32OTP[i]);
    }
    printf("\n");
    
    
    /* Show NuBL2 F/W info data */
    pu32Info = (uint32_t *)(uint32_t)g_InitialFWInfo;
    u32Size = sizeof(FW_INFO_T);
    
    printf("NuBL2 F/W info in 0x%08x.\nData are:\n", (uint32_t)pu32Info);
    for(i=0; i<(u32Size/4); i+=4)
    {
        printf("    0x%08x", pu32Info[i+0]);
        printf("    0x%08x", pu32Info[i+1]);
        printf("    0x%08x", pu32Info[i+2]);
        printf("    0x%08x", pu32Info[i+3]);
        printf("\n");
    }
    printf("\n");    

    return 0;
}

void EnableXOM0(void)
{
    int32_t i32Status;
    uint32_t u32Base = 0x10000;
    uint8_t u8Page = 4;

    /* Unlock protected registers */
    SYS_UnlockReg();

    /* Enable FMC ISP function and enable APROM active */
    FMC_ENABLE_ISP();
    FMC_ENABLE_AP_UPDATE();
    
    if((FMC->XOMSTS & 0x1) != 0x1)
    {
        printf("\nXOM0 base: 0x%x, page count: %d.\n\n", u32Base, u8Page);

        if(FMC_GetXOMState(XOMR0) == 0)
        {
            i32Status = FMC_ConfigXOM(XOMR0, u32Base, u8Page);
            if(i32Status == 0)
            {
                printf("Configure XOM0 Success.\n");
            }
            else
            {
                printf("Configure XOM0 FAIL.\n");
                while(1) {}
            }
        }
        else
        {
            printf("Get XOM0 status FAIL.\n\n");
            while(1) {}
        }

        printf("Reset chip to enable XOM region.\n\n");
        UART_WAIT_TX_EMPTY((UART_T *)DEBUG_PORT);

        /* Reset chip to enable XOM region. */
        SYS_ResetChip();
        while(1) {}
    }
    else
    {
        printf("XOM0 region is already actived.\n\n");
    }
}

void SYS_Init(void)
{
    /*---------------------------------------------------------------------------------------------------------*/
    /* Init System Clock                                                                                       */
    /*---------------------------------------------------------------------------------------------------------*/
    /* Enable HIRC clock */
    CLK_EnableXtalRC(CLK_PWRCTL_HIRCEN_Msk);

    /* Waiting for HIRC clock ready */
    CLK_WaitClockReady(CLK_STATUS_HIRCSTB_Msk);

    /* Switch HCLK clock source to HIRC */
    CLK_SetHCLK(CLK_CLKSEL0_HCLKSEL_HIRC, CLK_CLKDIV0_HCLK(1));

    /* Enable PLL */
    CLK->PLLCTL = CLK_PLLCTL_128MHz_HIRC;

    /* Waiting for PLL stable */
    CLK_WaitClockReady(CLK_STATUS_PLLSTB_Msk);

    /* Select HCLK clock source as PLL and HCLK source divider as 2 */
    CLK_SetHCLK(CLK_CLKSEL0_HCLKSEL_PLL, CLK_CLKDIV0_HCLK(2));

    /* Set SysTick source to HCLK/2*/
    CLK_SetSysTickClockSrc(CLK_CLKSEL0_STCLKSEL_HCLK_DIV2);

    /* Enable UART module clock */
    CLK_EnableModuleClock(UART0_MODULE);
    CLK_SetModuleClock(UART0_MODULE, CLK_CLKSEL1_UART0SEL_HIRC, CLK_CLKDIV0_UART0(1));

    /*---------------------------------------------------------------------------------------------------------*/
    /* Init I/O Multi-function                                                                                 */
    /*---------------------------------------------------------------------------------------------------------*/
    /* Set multi-function pins for UART0 RXD and TXD */
    SYS->GPB_MFPH = (SYS->GPB_MFPH & (~(UART0_RXD_PB12_Msk | UART0_TXD_PB13_Msk))) | UART0_RXD_PB12 | UART0_TXD_PB13;
}

void UART_Init(void)
{
    /*---------------------------------------------------------------------------------------------------------*/
    /* Init UART                                                                                               */
    /*---------------------------------------------------------------------------------------------------------*/
    /* Reset UART module */
    SYS_ResetModule(UART0_RST);

    /* Configure UART and set UART Baudrate */
    UART_Open((UART_T *)DEBUG_PORT, 115200);
}

/*---------------------------------------------------------------------------------------------------------*/
/*  MAIN function                                                                                          */
/*---------------------------------------------------------------------------------------------------------*/
int main(void)
{
    uint32_t u32NuBL32Base;
    
    /* Unlock protected registers */
    SYS_UnlockReg();

    /* Init System, peripheral clock and multi-function I/O */
    SYS_Init();

    /* Init UART for printf */
    UART_Init();

    printf("\n\nCPU @ %d Hz (Non-secure flash base: 0x%x)\n", SystemCoreClock, BL_GetNSBoundary());
    printf("+------------------------------------------+\n");
    printf("|    SecureBootDemo - NuBL2 Sample Code    |\n");
    printf("+------------------------------------------+\n\n");
    
    /* Show booting status */
    CheckBootingStatus();
    
#if (ENABLE_XOM0_REGION == 1)

    /* Enable XOM0, and all the functions in VerifyNuBL3x.c cannot trace in ICE debug mode  */
    EnableXOM0();
#endif    
    
    /* Verify NuBL32 identity and F/W integrity */
    memcpy((void *)(uint32_t)&s_NuBL3xFwInfo, (void *)NUBL32_FW_INFO_BASE, sizeof(FW_INFO_T));
    if(VerifyNuBL3x((uint32_t *)(uint32_t)&s_NuBL3xFwInfo, NUBL32_FW_INFO_BASE) == -1)
    {
        printf("\n\nNuBL2 verifies NuBL32 FAIL.\n");
        while(1) {}
    }
    else
    {
        u32NuBL32Base = s_NuBL3xFwInfo.mData.au32FwRegion[0].u32Start;
        printf("\nNuBL2 identify NuBL32 public key and verify NuBL32 F/W integrity PASS.\n");
    }
    
    
    /* Verify NuBL33 identity and F/W integrity */
    memcpy((void *)(uint32_t)&s_NuBL3xFwInfo, (void *)NUBL33_FW_INFO_BASE, sizeof(FW_INFO_T));
    if(VerifyNuBL3x((uint32_t *)(uint32_t)&s_NuBL3xFwInfo, NUBL33_FW_INFO_BASE) == -1)
    {
        printf("\n\nNuBL2 verifies NuBL33 FAIL.\n");
        while(1) {}
    }
    else
    {
        printf("\nNuBL2 identify NuBL33 public key and verify NuBL33 F/W integrity PASS.\n");
    }
    
    
    /* Jump to execute NuBL32 F/W */
    printf("\nJump to execute NuBL32...\n");
    UART_WAIT_TX_EMPTY((UART_T *)DEBUG_PORT);
    
    /* Disable all interrupt */
    __set_PRIMASK(1);
    
    FMC_ENABLE_ISP();
    FMC_SetVectorPageAddr(u32NuBL32Base);

    /* Reset CPU only to reset to new vector page */
    SYS->IPRST0 |= SYS_IPRST0_CPURST_Msk;

    while(1) {}
}

/*** (C) COPYRIGHT 2018 Nuvoton Technology Corp. ***/

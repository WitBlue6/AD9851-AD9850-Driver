/*
 * Copyright (c) 2023, Texas Instruments Incorporated - http://www.ti.com
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *  ============ ti_msp_dl_config.h =============
 *  Configured MSPM0 DriverLib module declarations
 *
 *  DO NOT EDIT - This file is generated for the MSPM0G350X
 *  by the SysConfig tool.
 */
#ifndef ti_msp_dl_config_h
#define ti_msp_dl_config_h

#define CONFIG_MSPM0G350X

#if defined(__ti_version__) || defined(__TI_COMPILER_VERSION__)
#define SYSCONFIG_WEAK __attribute__((weak))
#elif defined(__IAR_SYSTEMS_ICC__)
#define SYSCONFIG_WEAK __weak
#elif defined(__GNUC__)
#define SYSCONFIG_WEAK __attribute__((weak))
#endif

#include <ti/devices/msp/msp.h>
#include <ti/driverlib/driverlib.h>
#include <ti/driverlib/m0p/dl_core.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  ======== SYSCFG_DL_init ========
 *  Perform all required MSP DL initialization
 *
 *  This function should be called once at a point before any use of
 *  MSP DL.
 */


/* clang-format off */

#define POWER_STARTUP_DELAY                                                (16)


#define CPUCLK_FREQ                                                     32000000




/* Port definition for Pin Group RST */
#define RST_PORT                                                         (GPIOA)

/* Defines for PIN_RST: GPIOA.26 with pinCMx 59 on package pin 30 */
#define RST_PIN_RST_PIN                                         (DL_GPIO_PIN_26)
#define RST_PIN_RST_IOMUX                                        (IOMUX_PINCM59)
/* Defines for D0: GPIOA.15 with pinCMx 37 on package pin 8 */
#define DATA_D0_PORT                                                     (GPIOA)
#define DATA_D0_PIN                                             (DL_GPIO_PIN_15)
#define DATA_D0_IOMUX                                            (IOMUX_PINCM37)
/* Defines for D1: GPIOA.16 with pinCMx 38 on package pin 9 */
#define DATA_D1_PORT                                                     (GPIOA)
#define DATA_D1_PIN                                             (DL_GPIO_PIN_16)
#define DATA_D1_IOMUX                                            (IOMUX_PINCM38)
/* Defines for D2: GPIOA.17 with pinCMx 39 on package pin 10 */
#define DATA_D2_PORT                                                     (GPIOA)
#define DATA_D2_PIN                                             (DL_GPIO_PIN_17)
#define DATA_D2_IOMUX                                            (IOMUX_PINCM39)
/* Defines for D3: GPIOA.24 with pinCMx 54 on package pin 25 */
#define DATA_D3_PORT                                                     (GPIOA)
#define DATA_D3_PIN                                             (DL_GPIO_PIN_24)
#define DATA_D3_IOMUX                                            (IOMUX_PINCM54)
/* Defines for D4: GPIOA.18 with pinCMx 40 on package pin 11 */
#define DATA_D4_PORT                                                     (GPIOA)
#define DATA_D4_PIN                                             (DL_GPIO_PIN_18)
#define DATA_D4_IOMUX                                            (IOMUX_PINCM40)
/* Defines for D5: GPIOB.18 with pinCMx 44 on package pin 15 */
#define DATA_D5_PORT                                                     (GPIOB)
#define DATA_D5_PIN                                             (DL_GPIO_PIN_18)
#define DATA_D5_IOMUX                                            (IOMUX_PINCM44)
/* Defines for D6: GPIOA.22 with pinCMx 47 on package pin 18 */
#define DATA_D6_PORT                                                     (GPIOA)
#define DATA_D6_PIN                                             (DL_GPIO_PIN_22)
#define DATA_D6_IOMUX                                            (IOMUX_PINCM47)
/* Defines for D7: GPIOA.8 with pinCMx 19 on package pin 54 */
#define DATA_D7_PORT                                                     (GPIOA)
#define DATA_D7_PIN                                              (DL_GPIO_PIN_8)
#define DATA_D7_IOMUX                                            (IOMUX_PINCM19)
/* Port definition for Pin Group CLK */
#define CLK_PORT                                                         (GPIOB)

/* Defines for WCLK: GPIOB.9 with pinCMx 26 on package pin 61 */
#define CLK_WCLK_PIN                                             (DL_GPIO_PIN_9)
#define CLK_WCLK_IOMUX                                           (IOMUX_PINCM26)
/* Defines for FQ: GPIOB.24 with pinCMx 52 on package pin 23 */
#define CLK_FQ_PIN                                              (DL_GPIO_PIN_24)
#define CLK_FQ_IOMUX                                             (IOMUX_PINCM52)

/* clang-format on */

void SYSCFG_DL_init(void);
void SYSCFG_DL_initPower(void);
void SYSCFG_DL_GPIO_init(void);
void SYSCFG_DL_SYSCTL_init(void);



#ifdef __cplusplus
}
#endif

#endif /* ti_msp_dl_config_h */

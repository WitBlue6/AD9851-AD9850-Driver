/*
 * Copyright (c) 2021, Texas Instruments Incorporated
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

#include "ti/driverlib/dl_gpio.h"
#include "ti_msp_dl_config.h"


#define SYS_CLK 180000000

void delay_ms(uint32_t ms){
    while(ms--)
        delay_cycles(CPUCLK_FREQ/1000);
}

void AD9851_init(void){
    //RST置高
    DL_GPIO_setPins(RST_PORT, RST_PIN_RST_PIN);
    delay_ms(20);
    DL_GPIO_clearPins(RST_PORT, RST_PIN_RST_PIN);
    //时钟全部置低
    DL_GPIO_clearPins(CLK_PORT, CLK_FQ_PIN);
    DL_GPIO_clearPins(CLK_PORT, CLK_WCLK_PIN);
    //数据置底
    DL_GPIO_clearPins(DATA_D0_PORT, DATA_D0_PIN);
    DL_GPIO_clearPins(DATA_D1_PORT, DATA_D1_PIN);
    DL_GPIO_clearPins(DATA_D2_PORT, DATA_D2_PIN);
    DL_GPIO_clearPins(DATA_D3_PORT, DATA_D3_PIN);
    DL_GPIO_clearPins(DATA_D4_PORT, DATA_D4_PIN);
    DL_GPIO_clearPins(DATA_D5_PORT, DATA_D5_PIN);
    DL_GPIO_clearPins(DATA_D6_PORT, DATA_D6_PIN);
    DL_GPIO_clearPins(DATA_D7_PORT, DATA_D7_PIN);
}

void AD9851_write_parallel(uint8_t word){
    //paralled load写入一个字(8bit)
    //word的LSB为D0
    if(word & 0b00000001){
        DL_GPIO_setPins(DATA_D0_PORT, DATA_D0_PIN);
    }
    else{
        DL_GPIO_clearPins(DATA_D0_PORT, DATA_D0_PIN);
    }
    if(word & 0b00000010){
        DL_GPIO_setPins(DATA_D1_PORT, DATA_D1_PIN);
    }
    else{
        DL_GPIO_clearPins(DATA_D1_PORT, DATA_D1_PIN);
    }
    if(word & 0b00000100){
        DL_GPIO_setPins(DATA_D2_PORT, DATA_D2_PIN);
    }
    else{
        DL_GPIO_clearPins(DATA_D2_PORT, DATA_D2_PIN);
    }
    if(word & 0b00001000){
        DL_GPIO_setPins(DATA_D3_PORT, DATA_D3_PIN);
    }
    else{
        DL_GPIO_clearPins(DATA_D3_PORT, DATA_D3_PIN);
    }
    if(word & 0b0010000){
        DL_GPIO_setPins(DATA_D4_PORT, DATA_D4_PIN);
    }
    else{
        DL_GPIO_clearPins(DATA_D4_PORT, DATA_D4_PIN);
    }
    if(word & 0b00100000){
        DL_GPIO_setPins(DATA_D5_PORT, DATA_D5_PIN);
    }
    else{
        DL_GPIO_clearPins(DATA_D5_PORT, DATA_D5_PIN);
    }
    if(word & 0b01000000){
        DL_GPIO_setPins(DATA_D6_PORT, DATA_D6_PIN);
    }
    else{
        DL_GPIO_clearPins(DATA_D6_PORT, DATA_D6_PIN);
    }
    if(word & 0b10000000){
        DL_GPIO_setPins(DATA_D7_PORT, DATA_D7_PIN);
    }
    else{
        DL_GPIO_clearPins(DATA_D7_PORT, DATA_D7_PIN);
    }
    //拉高WCLK表示一次写入
    DL_GPIO_setPins(CLK_PORT, CLK_WCLK_PIN);
    delay_ms(20);
    DL_GPIO_clearPins(CLK_PORT, CLK_WCLK_PIN);
}

void AD9851_ddsout(void){
    //完成四次写入后，拉高FQ
    DL_GPIO_setPins(CLK_PORT, CLK_FQ_PIN);
    delay_ms(20);
    DL_GPIO_setPins(CLK_PORT, CLK_FQ_PIN);
}

void AD9851_freq_output(uint32_t freq){
    //以Hz为单位
    uint32_t freq_word = freq * 0x100000000 / SYS_CLK;
    //写入W0, enable 6XREFCLK
    uint8_t W0 = 0b00000001;
    AD9851_write_parallel(W0);
    //将freq_word从高到低写入W1 W2 W3 W4
    uint8_t W1 = freq_word >> 24;
    uint8_t W2 = freq_word >> 16;
    uint8_t W3 = freq_word >> 8;
    uint8_t W4 = freq_word;
    AD9851_write_parallel(W1);
    AD9851_write_parallel(W2);
    AD9851_write_parallel(W3);
    AD9851_write_parallel(W4);
    AD9851_ddsout();
}

int main(void)
{
    SYSCFG_DL_init();
    AD9851_init();
    AD9851_freq_output(60000);
    while (1) {
    }
}

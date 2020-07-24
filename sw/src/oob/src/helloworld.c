/******************************************************************************
*
* Copyright (C) 2009 - 2014 Xilinx, Inc.  All rights reserved.
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* Use of the Software is limited solely to applications:
* (a) running on a Xilinx device, or
* (b) that interact with a Xilinx device through a bus or interconnect.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
* XILINX  BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
* WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
* OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*
* Except as contained in this notice, the name of the Xilinx shall not be used
* in advertising or otherwise to promote the sale, use or other dealings in
* this Software without prior written authorization from Xilinx.
*
******************************************************************************/

/*
 * helloworld.c: simple test application
 *
 * This application configures UART 16550 to baud rate 9600.
 * PS7 UART (Zynq) is not initialized by this application, since
 * bootrom/bsp configures it to baud rate 115200
 *
 * ------------------------------------------------
 * | UART TYPE   BAUD RATE                        |
 * ------------------------------------------------
 *   uartns550   9600
 *   uartlite    Configurable only in HW design
 *   ps7_uart    115200 (configured by bootrom/bsp)
 */

#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"
#include "xparameters.h"
#include "xgpio.h"
#include "sleep.h"

#define AXI_GPIO_0_BTN_CH 1
#define AXI_GPIO_0_LED_CH 2

int main()
{
	XGpio gpio;
	XGpio_Config *CfgPtr;
	u32 btn_last_state, btn_state;
	u32 led_state = 0b0001;
	u32 tmr = 0;
	u32 direction = 0;

	init_platform();

	CfgPtr = XGpio_LookupConfig(XPAR_AXI_GPIO_0_DEVICE_ID);
	XGpio_CfgInitialize(&gpio, CfgPtr, CfgPtr->BaseAddress);
	XGpio_InterruptGlobalDisable(&gpio);
	XGpio_DiscreteWrite(&gpio, AXI_GPIO_0_LED_CH, led_state);

	print("Welcome to the USB104 A7 Out-Of-Box Demo\n\r");
	btn_last_state = XGpio_DiscreteRead(&gpio, AXI_GPIO_0_BTN_CH);
    while (1) {
    	if (tmr >= 249) {
    		if (direction) {
    			led_state = (led_state << 1) | ((led_state & 0b1000) >> 3);
    		} else {
    			led_state = (led_state >> 1) | ((led_state & 0b0001) << 3);
    		}
    		tmr = 0;
    		XGpio_DiscreteWrite(&gpio, AXI_GPIO_0_LED_CH, led_state);
    	} else {
    		tmr++;
    		usleep(1000);
    	}
    	btn_state = XGpio_DiscreteRead(&gpio, AXI_GPIO_0_BTN_CH);
    	if ((btn_state & ~btn_last_state) != 0) {
    		print("Button Press Detected!\n\r");
    		switch (btn_state & ~btn_last_state) {
    		case 0b01: direction = 0; break;
    		case 0b10: direction = 1; break;
    		}
    		tmr++;
    		usleep(1000);
    	}
    	btn_last_state = btn_state;
    }

    cleanup_platform();
    return 0;
}

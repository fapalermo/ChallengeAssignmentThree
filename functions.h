/*
 * functions.h
 *
 *  Created on: Apr 6, 2016
 *      Author: Bralyn
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

// Include files
#include "driverlib.h"
#include "msp.h"
#include <grlib.h>
#include "Crystalfontz128x128_ST7735.h"
#include "HAL_MSP_EXP432P401R_Crystalfontz128x128_ST7735.h"
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

//	Definitions
#define WDT_A_TIMEOUT RESET_SRC_1

/* ADC results buffer */
static uint16_t resultsBuffer[3];

volatile uint32_t msTicks;				// counts 1ms timeTicks

/* Graphic library context */
Graphics_Context g_sContext;


// Functions
void port_init(void);
void screen_init(void);
//void drawTitle(void);
//void drawAccelData(void);
void delay(uint32_t);
void enableWDT(void);

#endif /* FUNCTIONS_H_ */

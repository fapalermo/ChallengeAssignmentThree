//----------------------------------------------------------------------------
//	Yo, this is a header file
//----------------------------------------------------------------------------

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

//	Include files
#include "msp.h"
#include <driverlib.h>
#include <grlib.h>
#include "Crystalfontz128x128_ST7735.h"
#include <stdio.h>

//	Graphic library context
Graphics_Context g_sContext;

//	ADC results buffer
static uint16_t resultsBuffer[3];

volatile uint32_t msTicks;				// counts 1ms timeTicks


//	Functions
void delay(uint32_t);
void drawTitle(void);
void drawAccelData(void);
void port_init(void);
void screen_init(void);
void enableWDT(void);

#endif //	FUNCTIONS_H_

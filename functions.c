//----------------------------------------------------------------------------
//	Here are our extraneous functions
//----------------------------------------------------------------------------

#include "functions.h"

//----------------------------------------------------------------------------
//	This is a function that delays for a period of time. It is based on the
//	Blinky example, and uses the SysTick interrupt.
//----------------------------------------------------------------------------
void delay (uint32_t dlyTicks) {
	uint32_t curTicks;
	curTicks = msTicks;
	while ((msTicks - curTicks) < dlyTicks);
}

//----------------------------------------------------------------------------
//	Clear display and redraw title + accelerometer data
//----------------------------------------------------------------------------
void drawTitle()
{
    Graphics_clearDisplay(&g_sContext);
    Graphics_drawStringCentered(&g_sContext,
                                    "Accelerometer:",
                                    AUTO_STRING_LENGTH,
                                    64,
                                    30,
                                    OPAQUE_TEXT);
    drawAccelData();
}

//----------------------------------------------------------------------------
//	Redraw accelerometer data
//----------------------------------------------------------------------------
void drawAccelData()
{
    char string[8];
    sprintf(string, "X: %5d", resultsBuffer[0]);
    Graphics_drawStringCentered(&g_sContext,
                                    (int8_t *)string,
                                    8,
                                    64,
                                    50,
                                    OPAQUE_TEXT);

    sprintf(string, "Y: %5d", resultsBuffer[1]);
    Graphics_drawStringCentered(&g_sContext,
                                    (int8_t *)string,
                                    8,
                                    64,
                                    70,
                                    OPAQUE_TEXT);

    sprintf(string, "Z: %5d", resultsBuffer[2]);
    Graphics_drawStringCentered(&g_sContext,
                                    (int8_t *)string,
                                    8,
                                    64,
                                    90,
                                    OPAQUE_TEXT);

}

//----------------------------------------------------------------------------
//	Initializing ports
//----------------------------------------------------------------------------
void port_init()
{

}

//----------------------------------------------------------------------------
//	Initializing the screen
//----------------------------------------------------------------------------
void screen_init()
{

}

//----------------------------------------------------------------------------
//	Watchdog timer
//----------------------------------------------------------------------------
void enableWDT()
{

}

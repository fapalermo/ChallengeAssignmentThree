/*
 * gfx.c
 *
 *  Created on: Apr 8, 2016
 *      Author: fapal
 */
#include "functions.h"

Graphics_Context g_sContext;

void initGfx(void)
{
	/* Initializes display */
	Crystalfontz128x128_Init();

	/* Set default screen orientation */
	Crystalfontz128x128_SetOrientation(0);

	/* Set screen stuff */
	Graphics_initContext(&g_sContext, &g_sCrystalfontz128x128);
	Graphics_setForegroundColor(&g_sContext, GRAPHICS_COLOR_RED);
	Graphics_setBackgroundColor(&g_sContext, GRAPHICS_COLOR_WHITE);
	GrContextFontSet(&g_sContext, &g_sFontFixed6x8);
	Graphics_clearDisplay(&g_sContext);
}

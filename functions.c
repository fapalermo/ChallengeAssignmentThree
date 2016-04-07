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
//	Initializing the screen
//----------------------------------------------------------------------------
void screen_init()
{
	//	Initializes Clock System
	MAP_CS_setDCOCenteredFrequency(CS_DCO_FREQUENCY_48);
	MAP_CS_initClockSignal(CS_MCLK, CS_DCOCLK_SELECT, CS_CLOCK_DIVIDER_1 );
	MAP_CS_initClockSignal(CS_HSMCLK, CS_DCOCLK_SELECT, CS_CLOCK_DIVIDER_1 );
	MAP_CS_initClockSignal(CS_SMCLK, CS_DCOCLK_SELECT, CS_CLOCK_DIVIDER_1 );
	MAP_CS_initClockSignal(CS_ACLK, CS_REFOCLK_SELECT, CS_CLOCK_DIVIDER_1);

	//	Initializes display
	Crystalfontz128x128_Init();

	//	Set default screen orientation
	Crystalfontz128x128_SetOrientation(LCD_ORIENTATION_UP);

	//	Initializes graphics context
	Graphics_initContext(&g_sContext, &g_sCrystalfontz128x128);
	Graphics_setForegroundColor(&g_sContext, GRAPHICS_COLOR_RED);
	Graphics_setBackgroundColor(&g_sContext, GRAPHICS_COLOR_WHITE);
	GrContextFontSet(&g_sContext, &g_sFontFixed6x8);
	drawTitle();

}

//----------------------------------------------------------------------------
//	Initializing ports
//----------------------------------------------------------------------------
void port_init()
{
	//	Configures Pin 4.0, 4.2, and 6.1 as ADC inputs
	MAP_GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P4, GPIO_PIN0 | GPIO_PIN2, GPIO_TERTIARY_MODULE_FUNCTION);
	MAP_GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P6, GPIO_PIN1, GPIO_TERTIARY_MODULE_FUNCTION);

	//	Initializing ADC (ADCOSC/64/8)
	MAP_ADC14_enableModule();
	MAP_ADC14_initModule(ADC_CLOCKSOURCE_ADCOSC, ADC_PREDIVIDER_64, ADC_DIVIDER_8, 0);

	//	Configuring ADC Memory (ADC_MEM0 - ADC_MEM2 (A11, A13, A14) with no repeat) with internal 2.5v reference
	MAP_ADC14_configureMultiSequenceMode(ADC_MEM0, ADC_MEM2, true);
	MAP_ADC14_configureConversionMemory(ADC_MEM0, ADC_VREFPOS_AVCC_VREFNEG_VSS, ADC_INPUT_A14, ADC_NONDIFFERENTIAL_INPUTS);

	MAP_ADC14_configureConversionMemory(ADC_MEM1, ADC_VREFPOS_AVCC_VREFNEG_VSS, ADC_INPUT_A13, ADC_NONDIFFERENTIAL_INPUTS);

	MAP_ADC14_configureConversionMemory(ADC_MEM2, ADC_VREFPOS_AVCC_VREFNEG_VSS, ADC_INPUT_A11, ADC_NONDIFFERENTIAL_INPUTS);

	//	Enabling the interrupt when a conversion on channel 2 (end of sequence) is complete and enabling conversions
	MAP_ADC14_enableInterrupt(ADC_INT2);

	//	Enabling Interrupts
	MAP_Interrupt_enableInterrupt(INT_ADC14);
	MAP_Interrupt_enableMaster();

	//	Setting up the sample timer to automatically step through the sequence convert
	MAP_ADC14_enableSampleTimer(ADC_AUTOMATIC_ITERATION);

	//	Triggering the start of the sample
	MAP_ADC14_enableConversion();
	MAP_ADC14_toggleConversionTrigger();
}

//----------------------------------------------------------------------------
//	Watchdog timer
//----------------------------------------------------------------------------
void enableWDT()
{

}

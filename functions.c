
#include "functions.h"

//----------------------------------------------------------------------------
//	Initializing ports
//----------------------------------------------------------------------------
void port_init()
{
	//	Initialize Red, Blue, and Green LEDs
	MAP_GPIO_setAsOutputPin(GPIO_PORT_P5, GPIO_PIN6);	// Blue
	MAP_GPIO_setOutputLowOnPin(GPIO_PORT_P5, GPIO_PIN6);
	MAP_GPIO_setAsOutputPin(GPIO_PORT_P2, GPIO_PIN4);	// Green
	MAP_GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN4);
	MAP_GPIO_setAsOutputPin(GPIO_PORT_P2, GPIO_PIN6);	// Red
	MAP_GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN6);

	// Configuring P3.5 as an input for button press
	MAP_GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P3, GPIO_PIN5);
	MAP_GPIO_clearInterruptFlag(GPIO_PORT_P3, GPIO_PIN5);

	// Configuring P5.1 as an input for button press
	MAP_GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P5, GPIO_PIN1);
	MAP_GPIO_clearInterruptFlag(GPIO_PORT_P5, GPIO_PIN1);

    /* Configures Pin 4.0, 4.2, and 6.1 as ADC input */
    MAP_GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P4, GPIO_PIN0 | GPIO_PIN2, GPIO_TERTIARY_MODULE_FUNCTION);
    MAP_GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P6, GPIO_PIN1, GPIO_TERTIARY_MODULE_FUNCTION);

    /* Initializing ADC (ADCOSC/64/8) */
    MAP_ADC14_enableModule();
    MAP_ADC14_initModule(ADC_CLOCKSOURCE_ADCOSC, ADC_PREDIVIDER_64, ADC_DIVIDER_8,
            0);

    /* Configuring ADC Memory (ADC_MEM0 - ADC_MEM2 (A11, A13, A14)  with no repeat)
         * with internal 2.5v reference */
    MAP_ADC14_configureMultiSequenceMode(ADC_MEM0, ADC_MEM2, true);
    MAP_ADC14_configureConversionMemory(ADC_MEM0,
            ADC_VREFPOS_AVCC_VREFNEG_VSS,
            ADC_INPUT_A14, ADC_NONDIFFERENTIAL_INPUTS);

    MAP_ADC14_configureConversionMemory(ADC_MEM1,
            ADC_VREFPOS_AVCC_VREFNEG_VSS,
            ADC_INPUT_A13, ADC_NONDIFFERENTIAL_INPUTS);

    MAP_ADC14_configureConversionMemory(ADC_MEM2,
            ADC_VREFPOS_AVCC_VREFNEG_VSS,
            ADC_INPUT_A11, ADC_NONDIFFERENTIAL_INPUTS);

    /* Enabling the interrupt when a conversion on channel 2 (end of sequence)
     *  is complete and enabling conversions */
    MAP_ADC14_enableInterrupt(ADC_INT2);

    /* Enabling Interrupts */
	MAP_GPIO_enableInterrupt(GPIO_PORT_P3, GPIO_PIN5);
	MAP_GPIO_enableInterrupt(GPIO_PORT_P5, GPIO_PIN1);
	MAP_Interrupt_enableInterrupt(INT_PORT3);
	MAP_Interrupt_enableInterrupt(INT_PORT5);
    MAP_Interrupt_enableInterrupt(INT_ADC14);
    MAP_Interrupt_enableMaster();

    /* Setting up the sample timer to automatically step through the sequence
     * convert.
     */
    MAP_ADC14_enableSampleTimer(ADC_AUTOMATIC_ITERATION);

    /* Triggering the start of the sample */
    MAP_ADC14_enableConversion();
    MAP_ADC14_toggleConversionTrigger();


}

//----------------------------------------------------------------------------
//	Initializing the screen
//----------------------------------------------------------------------------
void screen_init()
{
	/* Initializes Clock System */
	MAP_CS_setDCOCenteredFrequency(CS_DCO_FREQUENCY_48);
	MAP_CS_initClockSignal(CS_MCLK, CS_DCOCLK_SELECT, CS_CLOCK_DIVIDER_1 );
	MAP_CS_initClockSignal(CS_HSMCLK, CS_DCOCLK_SELECT, CS_CLOCK_DIVIDER_1 );
	MAP_CS_initClockSignal(CS_SMCLK, CS_DCOCLK_SELECT, CS_CLOCK_DIVIDER_1 );
	MAP_CS_initClockSignal(CS_ACLK, CS_REFOCLK_SELECT, CS_CLOCK_DIVIDER_1);

	/* Initializes display */
	Crystalfontz128x128_Init();

	/* Set default screen orientation */
	Crystalfontz128x128_SetOrientation(LCD_ORIENTATION_UP);

	/* Initializes graphics context */
	Graphics_initContext(&g_sContext, &g_sCrystalfontz128x128);
	Graphics_setForegroundColor(&g_sContext, GRAPHICS_COLOR_RED);
	Graphics_setBackgroundColor(&g_sContext, GRAPHICS_COLOR_WHITE);
	GrContextFontSet(&g_sContext, &g_sFontFixed6x8);
	drawTitle();
}

/*
 * Clear display and redraw title + accelerometer data
 */
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


/*
 * Redraw accelerometer data
 */
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
//	This is a function that delays for a period of time. It is based on the
//	Blinky example, and uses the SysTick interrupt.
//----------------------------------------------------------------------------
void delay (uint32_t dlyTicks) {
	uint32_t curTicks;
	curTicks = msTicks;
	while ((msTicks - curTicks) < dlyTicks);
}

//----------------------------------------------------------------------------
//	Watchdog timer
//----------------------------------------------------------------------------
void enableWDT()
{
//	volatile uint32_t ii;
//
//	// Halting the Watchdog (while we set it up)
//	MAP_WDT_A_holdTimer();
//
//	// If the watchdog just reset, do soemthing
//	if(MAP_ResetCtl_getSoftResetSource() & WDT_A_TIMEOUT)
//	{
//
//	}
//
//	// Configuring WDT to timeout after 512k iterations of SMCLK - about 2 seconds
//	MAP_SysCtl_setWDTTimeoutResetType(SYSCTL_SOFT_RESET);
//	MAP_WDT_A_initWatchdogTimer(WDT_A_CLOCKSOURCE_SMCLK, WDT_A_CLOCKITERATIONS_128M);
//
//	// Starting watchdog timer
//	MAP_WDT_A_startTimer();
//	return;
}


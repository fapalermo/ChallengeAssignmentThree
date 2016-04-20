/*
 * uartTransmission.c
 *
 *  Created on: Apr 8, 2016
 *      Author: Kevin A. Keim
 */

/* DriverLib Includes */
#include "driverlib.h"

/* Standard Includes */
#include <stdint.h>
#include "functions.h"
#include <stdbool.h>

extern Graphics_Context g_sContext;

void initADC(void) {
	// Configures Pin 4.0, 4.2, and 6.1 as ADC input for Accelerometer
   	MAP_GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P4, GPIO_PIN0 | GPIO_PIN2, GPIO_TERTIARY_MODULE_FUNCTION);
   	MAP_GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P6, GPIO_PIN1, GPIO_TERTIARY_MODULE_FUNCTION);

	ADC14_enableModule();
	MAP_ADC14_initModule(ADC_CLOCKSOURCE_ADCOSC, ADC_PREDIVIDER_64, ADC_DIVIDER_8, 0);

    // Configuring ADC Memory
    MAP_ADC14_configureMultiSequenceMode(ADC_MEM0, ADC_MEM2, false);
    MAP_ADC14_configureConversionMemory(ADC_MEM0, ADC_VREFPOS_AVCC_VREFNEG_VSS, ADC_INPUT_A14, false);
    MAP_ADC14_configureConversionMemory(ADC_MEM1, ADC_VREFPOS_AVCC_VREFNEG_VSS, ADC_INPUT_A13, false);
    MAP_ADC14_configureConversionMemory(ADC_MEM2, ADC_VREFPOS_AVCC_VREFNEG_VSS, ADC_INPUT_A11, false);

    // Enable the interrupts when the conversion is finished
    MAP_ADC14_enableInterrupt(ADC_INT2);

    /* Enable 5ms timer */
    Timer32_initModule((uint32_t)TIMER32_0_BASE,TIMER32_PRESCALER_1,TIMER32_32BIT,TIMER32_PERIODIC_MODE);
    Timer32_setCount((uint32_t)TIMER32_0_BASE,240000);
    Timer32_enableInterrupt((uint32_t)TIMER32_0_BASE);
    Interrupt_enableInterrupt(INT_T32_INT1);

    // Enable interrupts
    MAP_Interrupt_enableInterrupt(INT_ADC14);
    MAP_Interrupt_enableMaster();

    // Set up automatic sequence to convert
    MAP_ADC14_enableSampleTimer(ADC_AUTOMATIC_ITERATION);

    // Enabling/Toggling Conversion
    MAP_ADC14_enableConversion();
    MAP_ADC14_toggleConversionTrigger();
}
void display_accel(void)
{
	uint16_t acc_vals[3];
	char string[9];
	uint16_t last_val_x = 0;
	uint16_t last_val_y = 0;
	uint16_t last_val_z = 0;
	uint32_t average_x = 0;
	uint32_t average_y = 0;
	uint32_t average_z = 0;
	uint16_t cycle = 0;

	/* Display Accelerometer Section Title */
	Graphics_drawStringCentered(&g_sContext, "Accelerometer:", AUTO_STRING_LENGTH, 64, 20, OPAQUE_TEXT);

	while(1)
	{
		/* Wait for an ADC interrupt to pass in new accelerometer values */
		Mailbox_pend(adc_result, acc_vals, BIOS_WAIT_FOREVER);

		/* Accumulate the differences between values and increment count */
		average_x += abs(acc_vals[0] - last_val_x);
		average_y += abs(acc_vals[1] - last_val_y);
		average_z += abs(acc_vals[2] - last_val_z);
		last_val_x = acc_vals[0];
		last_val_y = acc_vals[1];
		last_val_z = acc_vals[2];
		cycle++;

		/* After 200 cycles (~1ms), take the average values and display them */
		if(cycle >= 200)
		{
			average_x /= 200;
			average_y /= 200;
			average_z /= 200;

			/* Print X average */
			sprintf(string, "X: %5d", average_x);
			Graphics_drawStringCentered(&g_sContext, (int8_t *)string, 8, 64, 30, OPAQUE_TEXT);

			/* Print Y average */
			sprintf(string, "Y: %5d", average_y);
			Graphics_drawStringCentered(&g_sContext, (int8_t *)string, 8, 64, 40, OPAQUE_TEXT);

			/* Print Z average */
			sprintf(string, "Z: %5d", average_z);
			Graphics_drawStringCentered(&g_sContext, (int8_t *)string, 8, 64, 50, OPAQUE_TEXT);

			/* Reset the averages for the next run */
			average_x = 0;
			average_y = 0;
			average_z = 0;
			cycle = 0;
		}
	}
}

void Timer32_IRQHandler(void)
{
	Timer32_clearInterruptFlag((uint32_t)TIMER32_0_BASE);
	ADC14_toggleConversionTrigger();
}

void ADC14_IRQHandler(void) {
    uint64_t status = MAP_ADC14_getEnabledInterruptStatus();
    uint16_t curADCResult[3];

    MAP_ADC14_clearInterruptFlag(status);

    if (ADC_INT2 & status) {
        curADCResult[0] = ADC14_getResult(ADC_MEM0);
        curADCResult[1] = ADC14_getResult(ADC_MEM1);
        curADCResult[2] = ADC14_getResult(ADC_MEM2);

        Mailbox_post(adc_result, &curADCResult, BIOS_NO_WAIT);
    }
}

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

#include <stdbool.h>

void initADC(void) {
	// Configures Pin 4.0, 4.2, and 6.1 as ADC input for Accelerometer
   	MAP_GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P4, GPIO_PIN0 | GPIO_PIN2, GPIO_TERTIARY_MODULE_FUNCTION);
   	MAP_GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P6, GPIO_PIN1, GPIO_TERTIARY_MODULE_FUNCTION);

	ADC14_enableModule();
    //ADC14_initModule(ADC_CLOCKSOURCE_MCLK, ADC_PREDIVIDER_1, ADC_DIVIDER_1,
    //        ADC_TEMPSENSEMAP); // TODO: Check if these are the correct inputs
	MAP_ADC14_initModule(ADC_CLOCKSOURCE_ADCOSC, ADC_PREDIVIDER_64, ADC_DIVIDER_8, 0);

    // Configuring ADC Memory
    MAP_ADC14_configureMultiSequenceMode(ADC_MEM0, ADC_MEM2, false);
    MAP_ADC14_configureConversionMemory(ADC_MEM0, ADC_VREFPOS_AVCC_VREFNEG_VSS,
    		ADC_INPUT_A14, false);
    MAP_ADC14_configureConversionMemory(ADC_MEM1, ADC_VREFPOS_AVCC_VREFNEG_VSS,
    		ADC_INPUT_A13, false);
    MAP_ADC14_configureConversionMemory(ADC_MEM1, ADC_VREFPOS_AVCC_VREFNEG_VSS,
       		ADC_INPUT_A11, false);

    // Enable the interrupts
    MAP_ADC14_enableInterrupt(ADC_INT2);

    /* Enable 5ms timer */
    Timer32_initModule((uint32_t)TIMER32_0_BASE,TIMER32_PRESCALER_1,TIMER32_32BIT,TIMER32_PERIODIC_MODE);
    Timer32_setCount((uint32_t)TIMER32_0_BASE,240000);
    Timer32_enableInterrupt((uint32_t)TIMER32_0_BASE);
    Interrupt_enableInterrupt(INT_T32_INT1);

    MAP_Interrupt_enableInterrupt(INT_ADC14);

    // Enable master
    MAP_Interrupt_enableMaster();

    // Set up automatic sequence to convert
    MAP_ADC14_enableSampleTimer(ADC_AUTOMATIC_ITERATION);

    // Enabling/Toggling Conversion
    MAP_ADC14_enableConversion();
}

void ADC14_IRQHandler(void) {
    uint64_t status = MAP_ADC14_getEnabledInterruptStatus();
    uint16_t curADCResult[3];

    MAP_ADC14_clearInterruptFlag(status);

    if (ADC_INT2 & status) {
        curADCResult[0] = ADC14_getResult(ADC_MEM0);
        curADCResult[1] = ADC14_getResult(ADC_MEM1);
        curADCResult[2] = ADC14_getResult(ADC_MEM2);

        //Mailbox_post(acc_results, curADCResult, 0);
    }


}

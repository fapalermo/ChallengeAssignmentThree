/*
 * button.c
 *
 *  Created on: Apr 13, 2016
 *      Author: fapal - this guy
 */
#include "functions.h"

void button_task(void) {
	Bool button_press = FALSE;

	Semaphore_pend(Button_Semaphore, BIOS_WAIT_FOREVER);

	if (button_press == FALSE)
	{
		// change status of LED from red to green or vice versa
		MAP_GPIO_toggleOutputOnPin(GPIO_PORT_P2, GPIO_PIN6);	// toggle Red
		MAP_GPIO_toggleOutputOnPin(GPIO_PORT_P2, GPIO_PIN4);	// toggle Green

		Timer32_startTimer((uint32_t)TIMER32_0_BASE,0);
		UART_transmitData(EUSCI_A0_BASE, 'g');

		button_press = TRUE;
	}
	else
	{
		// change status of LED from red to green or vice versa
		MAP_GPIO_toggleOutputOnPin(GPIO_PORT_P2, GPIO_PIN6);	// toggle Red
		MAP_GPIO_toggleOutputOnPin(GPIO_PORT_P2, GPIO_PIN4);	// toggle Green

		Timer32_haltTimer((uint32_t)TIMER32_0_BASE);

		button_press = FALSE;
	}
}

void buttonInit(void){
	GPIO_setCallback(Board_BUTTON0, gpioButton0);
	GPIO_enableInt(Board_BUTTON0);

	/* Configure RGB LED pins */
	GPIO_setAsOutputPin(GPIO_PORT_P2, GPIO_PIN4 | GPIO_PIN6);
	GPIO_setAsOutputPin(GPIO_PORT_P5, GPIO_PIN6);

	/* Set RGB LED to red */
	P2OUT |= BIT6;
	P2OUT &= ~BIT4;
	P5OUT &= ~BIT6;

	/* Setup Button */
	GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P5,GPIO_PIN1);
	GPIO_clearInterruptFlag(GPIO_PORT_P5, GPIO_PIN1);
	GPIO_enableInterrupt(GPIO_PORT_P5, GPIO_PIN1);
	GPIO_interruptEdgeSelect(GPIO_PORT_P5, GPIO_PIN1, GPIO_HIGH_TO_LOW_TRANSITION);
	Interrupt_enableInterrupt(INT_PORT5);
}

void gpioButton0(void){
	initUart();
}

void SW1_IRQHandler(void){
	uint32_t status;
	status = MAP_GPIO_getEnabledInterruptStatus(GPIO_PORT_P5);
	_delay_cycles(3000000);
	MAP_GPIO_clearInterruptFlag(GPIO_PORT_P5, status);

	Semaphore_post(Button_Semaphore);
}

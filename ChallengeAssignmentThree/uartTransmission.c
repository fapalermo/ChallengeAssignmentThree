/*
 * uartTransmission.c
 *
 *  Created on: Apr 8, 2016
 *      Author: fapal
 */

#include <functions.h>

extern Graphics_Context g_sContext;

const eUSCI_UART_Config uartConfig =
{
	EUSCI_A_UART_CLOCKSOURCE_SMCLK,          // SMCLK Clock Source
	312,                                     // BRDIV = 78
	8,                                       // UCxBRF = 2
	0,                                       // UCxBRS = 0
	EUSCI_A_UART_NO_PARITY,                  // No Parity
	EUSCI_A_UART_LSB_FIRST,                  // LSB First
	EUSCI_A_UART_ONE_STOP_BIT,               // One stop bit
	EUSCI_A_UART_MODE,                       // UART mode
	EUSCI_A_UART_OVERSAMPLING_BAUDRATE_GENERATION  // Oversampling
};

void initUart(void)
{
    /* Selecting P1.2 and P1.3 in UART mode */
    MAP_GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P1, GPIO_PIN1 | GPIO_PIN2 | GPIO_PIN3, GPIO_PRIMARY_MODULE_FUNCTION);

    /* Configuring UART Module */
    MAP_UART_initModule(EUSCI_A0_BASE, &uartConfig);

    /* Enable UART module */
    MAP_UART_enableModule(EUSCI_A0_BASE);

    /* Enabling interrupts */
    MAP_UART_enableInterrupt(EUSCI_A0_BASE, EUSCI_A_UART_RECEIVE_INTERRUPT);
    MAP_Interrupt_enableInterrupt(INT_EUSCIA0);
    MAP_Interrupt_enableSleepOnIsrExit();
    MAP_Interrupt_enableMaster();
}

void uart_task(void)
{
	char rx;
	char rx_buf[10];
	char string[50];
	int32_t acc = 0;
	double avg = 0;
	int32_t count = 0;
	uint16_t display_count = 0;
	uint8_t rx_buf_ptr = 0;
	uint8_t data_set_count = 1;

	/* Draw data section header */
	Graphics_drawStringCentered(&g_sContext, "Heart beats:", AUTO_STRING_LENGTH, 64, 70, OPAQUE_TEXT);

	while(1)
	{
		/* Wait for received character to be posted in mailbox */
		Mailbox_pend(uart_data, &rx, BIOS_WAIT_FOREVER);

		/* Check for end of data transmission */
		if(rx == '=')
		{
			/* Reset variables and send command to stop data aquisition */
			acc = 0;
			count = 0;
			rx_buf_ptr = 0;
			data_set_count = 0;
			Semaphore_post(Button_Semaphore);
		}

		/* Check for end of number */
		else if (rx == 'f')
		{
			/* Convert string to number and add it to the accumulation */
			rx_buf[rx_buf_ptr] = '\0';
			acc += atoi(rx_buf);
			count++;
			display_count++;

			Graphics_drawStringCentered(&g_sContext, (int8_t *)rx_buf, 10, 64, 90, OPAQUE_TEXT);
			rx_buf_ptr = 0;
			MAP_UART_transmitData(EUSCI_A0_BASE, 'c');
		}

		/* End of number hasn't been reached, store and wait for next byte */
		else
		{
			rx_buf[rx_buf_ptr] = rx;
			rx_buf_ptr++;
			MAP_UART_transmitData(EUSCI_A0_BASE, 'c');
		}
	}
}

/* EUSCI A0 UART ISR - Echoes data back to PC host */
void EUSCIA0_IRQHandler(void)
{
    uint32_t status = MAP_UART_getEnabledInterruptStatus(EUSCI_A0_BASE);

    MAP_UART_clearInterruptFlag(EUSCI_A0_BASE, status);
    char rx;

    if(status & EUSCI_A_UART_RECEIVE_INTERRUPT)
    {
        //MAP_UART_transmitData(EUSCI_A0_BASE, MAP_UART_receiveData(EUSCI_A0_BASE));
        /* Send data to handler task */
		rx = MAP_UART_receiveData(EUSCI_A0_BASE);
		Mailbox_post(uart_data, &rx, 0);
    }
}


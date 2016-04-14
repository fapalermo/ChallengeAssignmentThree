/*
 * button.c
 *
 *  Created on: Apr 13, 2016
 *      Author: fapal
 */
#include "functions.h"


void buttonInit(void){
	GPIO_setCallback(Board_BUTTON0, gpioButton0);
	GPIO_enableInt(Board_BUTTON0);

}
void gpioButton0(void){
	initUart();
}


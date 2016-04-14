/*
 * functions.h
 *
 *  Created on: Apr 8, 2016
 *      Author: fapal
 */
#include <xdc/std.h>
#include <xdc/runtime/System.h>

/* BIOS Header files */
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>

/* TI-RTOS Header files */
#include <ti/drivers/GPIO.h>
// #include <ti/drivers/I2C.h>
// #include <ti/drivers/SDSPI.h>
// #include <ti/drivers/SPI.h>
// #include <ti/drivers/UART.h>
// #include <ti/drivers/Watchdog.h>
// #include <ti/drivers/WiFi.h>

/* Board Header file */
#include "Board.h"

#include <driverlib.h>
#include <grlib.h>
#include "Crystalfontz128x128_ST7735.h"

#define TASKSTACKSIZE   512

void initUart(void);
void initClocks(void);
void initGfx(void);
void buttonInit(void);
void gpioButton0(void);

void initADC(void);




//----------------------------------------------------------------------------
//
//	Challenge 3 - ECE 461
//	Bralyn Fagel
//	Francesco Fagel
//	Kevin Fagel
//
//----------------------------------------------------------------------------

#include "functions.h"

//----------------------------------------------------------------------------
//	Main function
//----------------------------------------------------------------------------
void main(void)
{
    //	Halting WDT and disabling master interrupts
    MAP_WDT_A_holdTimer();
    MAP_Interrupt_disableMaster();

    screen_init();
    port_init();

	// Since the MCLK was changed, grab new core speed for delay calcs
	SystemCoreClockUpdate();
	SysTick_Config(SystemCoreClock / 1000);		// This sets the Systick interrupt to go off every 1ms

	// Set Red LED on
	MAP_GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN4);

    while(1)
    {
        MAP_PCM_gotoLPM0();
    }
}

//----------------------------------------------------------------------------
//	This is the SysTick_Handler. It continously interrupts at every
//	millisecond and increments a counter.
//----------------------------------------------------------------------------
void SysTick_Handler(void)
{
	MAP_GPIO_toggleOutputOnPin(GPIO_PORT_P2, GPIO_PIN6);	//	toggle Red
	MAP_GPIO_toggleOutputOnPin(GPIO_PORT_P2, GPIO_PIN4);	//	toggle Green
	msTicks++;
}

//----------------------------------------------------------------------------
//	This interrupt is fired whenever a conversion is completed and placed in
//	ADC_MEM2. This signals the end of conversion and the results array is
//	grabbed and placed in resultsBuffer
//----------------------------------------------------------------------------
void ADC14_IRQHandler(void)
{
    uint64_t status;

    status = MAP_ADC14_getEnabledInterruptStatus();
    MAP_ADC14_clearInterruptFlag(status);

    //	ADC_MEM2 conversion completed
    if(status & ADC_INT2)
    {
        //	Store ADC14 conversion results
        resultsBuffer[0] = ADC14_getResult(ADC_MEM0);
        resultsBuffer[1] = ADC14_getResult(ADC_MEM1);
        resultsBuffer[2] = ADC14_getResult(ADC_MEM2);

        //	Draw accelerometer data on display and determine if orientation
        //	change thresholds are reached and redraw as necessary
        if (resultsBuffer[0] < 4900) {
            if (Lcd_Orientation != LCD_ORIENTATION_LEFT) {
                Crystalfontz128x128_SetOrientation(LCD_ORIENTATION_LEFT);
                drawTitle();
            }
            else
                drawAccelData();
        }
        else if (resultsBuffer[0] > 11300) {
            if (Lcd_Orientation != LCD_ORIENTATION_RIGHT){
                Crystalfontz128x128_SetOrientation(LCD_ORIENTATION_RIGHT);
                drawTitle();
            }
            else
                drawAccelData();
        }
        else if (resultsBuffer[1] < 5000) {
            if (Lcd_Orientation != LCD_ORIENTATION_UP){
                Crystalfontz128x128_SetOrientation(LCD_ORIENTATION_UP);
                drawTitle();
            }
            else
                drawAccelData();
        }
        else if (resultsBuffer[1] > 11300) {
            if (Lcd_Orientation != LCD_ORIENTATION_DOWN){
                Crystalfontz128x128_SetOrientation(LCD_ORIENTATION_DOWN);
                drawTitle();
            }
            else
                drawAccelData();
        }
        else
            drawAccelData();
    }
}

//----------------------------------------------------------------------------
//	Port 3 interrupt	-	Doorbell
//----------------------------------------------------------------------------
void PORT3_IRQHandler(void)
{
	uint32_t status;

	status = MAP_GPIO_getEnabledInterruptStatus(GPIO_PORT_P3);
	MAP_GPIO_clearInterruptFlag(GPIO_PORT_P3, status);

	//	change status of LED from red to green or vice versa
	MAP_GPIO_toggleOutputOnPin(GPIO_PORT_P2, GPIO_PIN6);	//	toggle Red
	MAP_GPIO_toggleOutputOnPin(GPIO_PORT_P2, GPIO_PIN4);	//	toggle Green
}

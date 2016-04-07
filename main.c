//----------------------------------------------------------------------------
//
//	Challenge 3 - ECE 461
//	Bralyn Fagel
//	Francesco
//	Kevin
//
//----------------------------------------------------------------------------

#include <functions.h>

int main(void) 
{
	/* Halting WDT and disabling master interrupts */
    WDT_A_holdTimer();
    MAP_Interrupt_disableMaster();

    screen_init();
    port_init();

    // Since the MCLK was changed, grab new core speed for delay calcs
	SystemCoreClockUpdate();
	SysTick_Config(SystemCoreClock / 1000);		// This sets the Systick interrupt to go off every 1ms

//    delay(500);
//
//    Graphics_drawStringCentered(&g_sContext, "                 ", AUTO_STRING_LENGTH, 64, 30, OPAQUE_TEXT);
//    Graphics_drawStringCentered(&g_sContext, "Did it work?", AUTO_STRING_LENGTH, 64, 30, OPAQUE_TEXT);

    while(1)
    {
    	 MAP_PCM_gotoLPM0();
    }
}

void SysTick_Handler(void)
{
	msTicks++;
}

/* This interrupt is fired whenever a conversion is completed and placed in
 * ADC_MEM2. This signals the end of conversion and the results array is
 * grabbed and placed in resultsBuffer */
void ADC14_IRQHandler(void)
{
    uint64_t status;

    status = MAP_ADC14_getEnabledInterruptStatus();
    MAP_ADC14_clearInterruptFlag(status);

    /* ADC_MEM2 conversion completed */
    if(status & ADC_INT2)
    {
        /* Store ADC14 conversion results */
        resultsBuffer[0] = ADC14_getResult(ADC_MEM0);
        resultsBuffer[1] = ADC14_getResult(ADC_MEM1);
        resultsBuffer[2] = ADC14_getResult(ADC_MEM2);

        /*
         * Draw accelerometer data on display and determine if orientation
         * change thresholds are reached and redraw as necessary
         */
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

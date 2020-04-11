/* adc.c */
/* Import needed interfaces: */
#include "pinout.h"
#include <xc.h> // Compiler

/* Implements this interface: */
#include "adc.h"

void setupADC(void) {
    ADCON0bits.ADON = 1; // Enable the ADC module
    TRISAbits.TRISA0 = 1; // Setup RA0 as input
    ANSELbits.ANS0 = 1; // Set RA0 to analogue
    ADCON0 = 0b10000001; //Right justified, Vdd, ANO0, GO low, ADC en
    ADCON1 = 0b0100000; // ADC sample freq as Fosc/4, i.e. 1us
}

int readADC(void) {
       __delay_us(2); // Wait for required acquisition time
       ADCON0bits.GO = 1; //Start conversion
       while (ADCON0bits.GO == 1)
       {
           NOP(); // Just wait
       }
        int measurement;
        int low = ADRESL;
        int high = ADRESH;
        measurement = (high*256)+(low);  // The MSBs are in ADRESL.
                                         // *256 equivalent to shift left 8 times
        return measurement;          
        
}

/*
void interrupt tc_int(void)
{
 if (TMR0IE && TMR0IF) {
 TMR0IF=0;
 ++tick_count;
 return;
 }
 // process other interrupt sources here, if required
}
 */
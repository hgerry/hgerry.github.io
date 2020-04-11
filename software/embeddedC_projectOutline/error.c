/* error.c */
/* Import needed interfaces: */
#include "pinout.h"
#include <xc.h> // Compiler
/* Implements this interface: */
#include "error.h"

#define flashOn 300
#define flashOff 300

void error0(void) { // For debugging purposes 
    
    int i;
    PORTC = 0; // Clear the port
    
    for( i = 0; i < 10; i = i + 1){
        LED0 = 1;
        __delay_ms(flashOn);
        LED0 = 1;
        __delay_ms(flashOff);
    }
}

void error1(void) { // For debugging purposes 
    
    int i;
    PORTC = 0; // Clear the port
    
    for( i = 0; i < 10; i = i + 1){
        LED1 = 1;
        __delay_ms(flashOn);
        LED1 = 1;
        __delay_ms(flashOff);
    }
}

void flashAll(void) { // For debugging purposes 
    __delay_ms(1000);
    PORTC = 0b11111111;
    __delay_ms(1000);
    PORTC = 0b00000000;
}
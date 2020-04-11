/* led.c */
/* Import needed interfaces: */
#include "pinout.h"
#include <xc.h> // Compiler
/* Implements this interface: */
#include "led.h"

void initLED(void){ // Initialises the output LEDs
    // Set LED pins as digital
    ANSELbits.ANS4 = 0; // RC0 (0 is digital, 1 is analogue)
    ANSELbits.ANS5 = 0; // RC1
    ANSELbits.ANS6 = 0; // RC2
    ANSELbits.ANS7 = 0; // RC3
       
    // Set LED pins tri-state as output
    LED0_TRIS = 0;
    LED1_TRIS = 0;
    LED2_TRIS = 0;
    LED3_TRIS = 0;
}
   
void updateLED(int pos){
    // Takes position as an argument
    if(pos == 0){
        LED0=1;
        LED1=0;
        LED2=0;
        LED3=0;
    }
    if(pos == 1){
        LED0=1;
        LED1=1;
        LED2=0;
        LED3=0;
    }
    if(pos == 2){
        LED0=1;
        LED1=1;
        LED2=1;
        LED3=0;
    }
    if(pos == 3){
        LED0=1;
        LED1=1;
        LED2=1;
        LED3=1;
    }
}



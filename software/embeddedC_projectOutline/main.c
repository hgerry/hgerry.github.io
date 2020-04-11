/*
 * File:   main.c
 * Author: CAMGH8
 *
 * Created on 01 July 2016, 10:40
 * Demonstration software for PIC16f690
 * Designed for Pickit 2 low pin count dev board
 */

#include <xc.h> // Compiler
#include "adc.h"
#include "led.h"
#include "pinout.h"
#include "error.h"

#define _XTAL_FREQ 4000000

#define low 256  // Used in ADC data processing 
#define med 512
#define high 768

void main(void) {
    
    int pos;  // Potentiometer position
    int lastPos;
    char state = 'A'; // Boot into the initialisation state
    int meas;  // Place to store measurements
    
    //Infinite loop
    while(1){
        // State machine
        switch(state){
            case 'A':  // Initialise system
                initLED(); 
                setupADC();
                pos = -1; // Give a default
                state = 'B'; // One  time setup, then into idle
                flashAll(); // For debug
                break;
            case 'B' : // System idle
                if(pos != lastPos){
                    state = 'C';  // Time to update the LEDs
                }
                // Do something else useful in the future
                lastPos = pos;
                break;
            case 'C':  // Changing LED output
                updateLED(pos);
                break;
            default: // Should never get here!
                error0();
                break;
        }
        
        // Polling activities take place here
        // Data processing for ADC
        meas = readADC();
        if((meas < low)){
            pos = 0;
        }
        else if((meas >= low) && (meas < med)){
            pos = 1;
        }
        else if((meas >= med) && (meas < high)){
            pos = 2;
        }
        else if((meas >= high)){
            pos = 3;
        }
        else {
            error1();  // Error 
            }
        
                
    }
                  
}


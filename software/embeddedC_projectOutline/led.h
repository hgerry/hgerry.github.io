/* led.h */

// Enclose the entire contents in a condition to prevent the compiler
// processing the contents twice

#ifndef LED_H
#define LED_H

// Header file contents start here

// Function definitions

// Takes and returns nothing. Initialises LED peripheral.
void initLED(void);
// Takes an LED state as an integer, updates the LEDs as required.
void updateLED(int);

// Variable definitions

// Header file contents end here
#endif
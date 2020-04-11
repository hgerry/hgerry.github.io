/* pinout.h 
 * Describes the pin allocation for the PIC 16F690
 * when inserted into a PICkit2 low pin count dev board
 * Compiler datasheet: 
 * http://ww1.microchip.com/downloads/en/DeviceDoc/50002053E.pdf
 * Device datasheet: 
 * http://ww1.microchip.com/downloads/en/DeviceDoc/41262C.pdf
 * Dev board datasheet: 
 * http://ww1.microchip.com/downloads/en/DeviceDoc/Low%20Pin%20Count%20User%20Guide%2051556a.pdf/ */
#ifndef PINOUT_H
#define	PINOUT_H

// Function definitions

// Variable definitions
// USER DEFINED:
#define _XTAL_FREQ 4000000 
// HARDWARE DEFINED:
#define LED0 PORTCbits.RC0    
#define LED0_TRIS TRISCbits.TRISC0
#define LED1 PORTCbits.RC1
#define LED1_TRIS TRISCbits.TRISC1
#define LED2 PORTCbits.RC2
#define LED2_TRIS TRISCbits.TRISC2
#define LED3 PORTCbits.RC3
#define LED3_TRIS TRISCbits.TRISC3
#define SW PORTAbits.RA3           // Normally open, pulled HIGH
#define SW_TRIS TRISAbits.TRISA3   
#define POT PORTAbits.RA0
#define POT_TRIS TRISAbits.TRISA0

#endif	/* PINOUT_H */


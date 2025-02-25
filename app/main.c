#include <msp430.h>
#include <stdbool.h>

/**
 *  PROJECT 3
 *
 *  Aaron McLean & Alex Deadmond    EELE 465
 *
 *  Last Updated: 02/20/2025
 *
 *  A program that takes inputs from a membrain 
 *  keypad and detemines a locked or unlocked state, 
 *  and outputs state and patterns on an LED strip.
 */


int main(void)
{
    // Stop watchdog timer
    WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer
    
    // Disable the GPIO power-on default high-impedance mdoe to activate
    // previously configure port settings
    PM5CTL0 &= ~LOCKLPM5;

    while(true)
    {

        // if Locked
            // check for combo: sets to unlocked, resets timeout
        // if Unlocked
            // turn on ISR(s) for columns
            // while not timed out
            // turn off ISR(s) for columns




    }
}

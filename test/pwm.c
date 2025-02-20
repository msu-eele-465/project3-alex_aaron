#include <msp430.h>
#include <stdbool.h>

/**
    PROJECT 3: Pulse Width Modulator
 
    Aaron McLean    EELE 465
 
    Last Updated: 02/20/2025
 
    A test program that modulates the pulse
    width of an output square signal
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

    }
}

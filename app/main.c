#include <msp430.h>
#include <stdbool.h>

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

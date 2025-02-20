#include <msp430.h>
#include <stdbool.h>

int main(void)
{
    // Stop watchdog timer
    WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer

    // Set up Ports 1.0-1.3 as outputs (column)
    P1DIR |= BIT0;
    P1DIR |= BIT1;
    P1DIR |= BIT2;
    P1DIR |= BIT3;

    // Set up Ports 1.4-1.7 as inputs (rows)
    P1DIR &= BIT4;
    P1DIR &= BIT5;
    P1DIR &= BIT6;
    P1DIR &= BIT7;

    // Set outputs as high to start
    P1OUT |= BIT4;
    P1OUT |= BIT5;
    P1OUT |= BIT6;
    P1OUT |= BIT7;

    // Enable pull up resistors for rows
    P1REN |= BIT4;
    P1REN |= BIT5;
    P1REN |= BIT6;
    P1REN |= BIT7;

    
    // Disable the GPIO power-on default high-impedance mdoe to activate
    // previously configure port settings
    PM5CTL0 &= ~LOCKLPM5;

    while(true)
    {
    }
}

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

    P1DIR |= BIT0;  // configure p1.0 as output
    P1OUT |= BIT0;  // LED 1 set high for PWM

    // Disable the GPIO power-on default high-impedance mdoe to activate
    // previously configure port settings
    PM5CTL0 &= ~LOCKLPM5;

    // setup timer B
    TB0CTL |= TBCLR;            // clear timers and dividers
    TB0CTL |= TBSSEL__ACLK;     // source=ACLK
    TB0CTL |= MC__UP            // mode=UP

    TB0CCR0 = 32768;
    TB0CCR1 = 1638;

    // setup timer compare IRQs for CCR 1 and 0

    TB0CCTL0 |= CCIE;           // enable TB0 CCR0 overflow IRQ
    TB0CCTL0 &= ~CCIFG;         // clear CCR0 Flag
    TB0CCTL0 |= CCIE;           // enable TB1 CCR0 overflow IRQ
    TB0CCTL0 &= ~CCIFG;         // clear CCR1 Flag

    __enable_interrupt();

    while(true){}

    return 0;
}


// interrupt service routines
#pragma vector = TIMER_B0_VECTOR
__interrupt void ISR_TB0_CCR0(void){
    P1OUT |= BIT0;
    TB0CCTL0 &CCIFG;
}

#pragma vector = TIMER_B1_VECTOR
__interrupt void ISR_TB0_CCR1(void){
    P1OUT |= ~BIT0;
    TB0CCTL1 &CCIFG;
}

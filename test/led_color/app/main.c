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


    P3DIR |= BIT0;  // configure p3.0 as output
    P2DIR |= BIT5;  // configure p2.5 as output
    P4DIR |= BIT4;  // configure p4.4 as output


    P3OUT |= BIT0;  // LED 1 set high for PWM
    P2OUT = BIT5;  // LED 1 set high for PWM
    P4OUT = BIT4;  // LED 1 set high for PWM
    

    // Disable the GPIO power-on default high-impedance mdoe to activate
    // previously configure port settings
    PM5CTL0 &= ~LOCKLPM5;

    // setup timer B
    TB0CTL |= TBCLR;            // clear timers and dividers
    TB0CTL |= TBSSEL__ACLK;     // source=ACLK
    TB0CTL |= MC__UP;           // mode=UP

    TB0CCR0 = 328;
    TB0CCR1 = 164;

    // setup timer compare IRQs for CCR 1 and 0

    TB0CCTL0 |= CCIE;           // enable TB0 CCR0 overflow IRQ
    TB0CCTL0 &= ~CCIFG;         // clear CCR0 Flag
    TB0CCTL1 |= CCIE;           // enable TB1 CCR0 overflow IRQ
    TB0CCTL1 &= ~CCIFG;         // clear CCR1 Flag

    __enable_interrupt();

    while(1){}

    return 0;
}


// interrupt service routines
#pragma vector = TIMER0_B0_VECTOR
__interrupt void ISR_TB0_CCR0(void){
    P3OUT |= BIT0;
    P2OUT |= BIT5;
    P4OUT |= BIT4;
    TB0CCTL0 &= ~CCIFG;
}

#pragma vector = TIMER0_B1_VECTOR
__interrupt void ISR_TB0_CCR1(void){
    P3OUT &= ~BIT0;
    P2OUT &= ~BIT5;
    P4OUT &= ~BIT4;
    TB0CCTL1 &= ~CCIFG;
}

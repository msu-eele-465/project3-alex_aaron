void keypad_init() {
    // LED P6.6 as an output for lock
    P6DIR |= BIT6;
    P6OUT &= ~BIT6;

    // P1.0 - P1.3 as Outputs (col)
    P1DIR |= BIT0 | BIT1 | BIT2 | BIT3;

    // P1.4 - P1.7 as inputs (row) with pull-up resistor
    P1DIR &= ~(BIT4 | BIT5 | BIT6 | BIT7);
    P1REN |= BIT4 | BIT5 | BIT6 | BIT7;
    P1OUT |= BIT4 | BIT5 | BIT6 | BIT7;

    // Port 3 as an output
    P3DIR = 0xFF;
    P3OUT = 0x00;

    // Disable digital I/O low-power default
    PM5CTL0 &= ~LOCKLPM5;
}
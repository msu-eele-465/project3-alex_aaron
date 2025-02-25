void readKeypad() {
    // Pulling second column high while the rest low.
    P1OUT |= BIT0;
    P1OUT &= ~BIT1;
    P1OUT |= BIT2;
    P1OUT |= BIT3;

    if (!(P1IN & BIT7)) { // Checking if first button is pressed
        handleButtonPress(1);
    }
    if (!(P1IN & BIT6)) { // Checking if second button is pressed
        handleButtonPress(2);
    }
    if (!(P1IN & BIT5)) { // Checking if third button is pressed
        handleButtonPress(3);
    }
    if (!(P1IN & BIT4)) { // Checking if fourth button is pressed
        handleButtonPress(4);
    }

    // Pulling first column high while the rest low.
    P1OUT &= ~BIT0;
    P1OUT |= BIT1;
    P1OUT |= BIT2;
    P1OUT |= BIT3;

    if (!(P1IN & BIT7)) { // Checking if first button is pressed
        handleButtonPress(5);
    }
    if (!(P1IN & BIT6)) { // Checking if second button is pressed
        handleButtonPress(6);
    }
    if (!(P1IN & BIT5)) { // Checking if third button is pressed
        handleButtonPress(7);
    }
    if (!(P1IN & BIT4)) { // Checking if fourth button is pressed
        handleButtonPress(8);
    }

    // Pulling third column high while the rest low.
    P1OUT |= BIT0;
    P1OUT |= BIT1;
    P1OUT &= ~BIT2;
    P1OUT |= BIT3;

    if (!(P1IN & BIT7)) { // Checking if first button is pressed
        handleButtonPress(9);
    }
    if (!(P1IN & BIT6)) { // Checking if second button is pressed
        handleButtonPress(10);
    }
    if (!(P1IN & BIT5)) { // Checking if third button is pressed
        handleButtonPress(11);
    }
    if (!(P1IN & BIT4)) { // Checking if fourth button is pressed
        handleButtonPress(12);
    }

    // Pulling fourth column high while the rest low.
    P1OUT |= BIT0;
    P1OUT |= BIT1;
    P1OUT |= BIT2;
    P1OUT &= ~BIT3;

    if (!(P1IN & BIT7)) { // Checking if first button is pressed
        handleButtonPress(13);
    }
    if (!(P1IN & BIT6)) { // Checking if second button is pressed
        handleButtonPress(14);
    }
    if (!(P1IN & BIT5)) { // Checking if third button is pressed
        handleButtonPress(15);
    }
    if (!(P1IN & BIT4)) { // Checking if fourth button is pressed
        handleButtonPress(16);
    }
}
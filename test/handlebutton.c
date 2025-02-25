void handleButtonPress(int button) {
    switch (button) {
        case 1: // if A is pressed
            P3OUT = 0xAA;
            break;
        case 2: // if B is pressed
            for (int i = 0; i <= 255; i++) {
                P3OUT = i;
                delay();
                delay();
            }
            break;
        case 3: // if C is pressed
            P3OUT = 0xFE;
            for (int i = 0; i < 8; i++) {
                delay(); delay(); delay(); delay();
                delay(); delay(); delay(); delay();
                P3OUT = (P3OUT << 1) | 0x01;
            }
            P3OUT = 0xFE;
            break;
        case 4: // if D is pressed
            P3OUT = 0x18;
            delay(); delay(); delay(); delay(); delay(); delay(); delay(); delay();
            P3OUT = 0x00;
            delay();
            P3OUT = 0x24;
            delay(); delay(); delay(); delay(); delay(); delay(); delay(); delay();
            P3OUT = 0x00;
            delay();
            P3OUT = 0x42;
            delay(); delay(); delay(); delay(); delay(); delay(); delay(); delay();
            P3OUT = 0x00;
            delay();
            P3OUT = 0x81;
            delay(); delay(); delay(); delay(); delay(); delay(); delay(); delay();
            P3OUT = 0x00;
            delay();
            P3OUT = 0x42;
            delay(); delay(); delay(); delay(); delay(); delay(); delay(); delay();
            P3OUT = 0x00;
            delay();
            P3OUT = 0x24;
            delay(); delay(); delay(); delay(); delay(); delay(); delay(); delay();
            P3OUT = 0x00;
            delay();
            P3OUT = 0x18;
            break;
        case 5: // if 3 is pressed
            P3OUT = 0x03;
            break;
        case 6: // if 6 is pressed
            P3OUT = 0x06;
            break;
        case 7: // if 9 is pressed
            P3OUT = 0x09;
            break;
        case 8: // if # is pressed
            P3OUT = 0x00;
            delay(); delay();
            P3OUT = 0x73;
            delay(); delay(); delay(); delay();
            P3OUT = 0x00;
            delay(); delay();
            P3OUT = 0x6F;
            delay(); delay(); delay(); delay();
            P3OUT = 0x00;
            delay(); delay();
            P3OUT = 0x6F;
            delay(); delay(); delay(); delay();
            P3OUT = 0x00;
            delay(); delay();
            P3OUT = 0x73;
            delay(); delay(); delay(); delay();
            P3OUT = 0x00;
            break;
        case 9: // if 2 is pressed
            P3OUT = 0x02;
            break;
        case 10: // if 5 is pressed
            P3OUT = 0x05;
            break;
        case 11: // if 8 is pressed
            P3OUT = 0x08;
            break;
        case 12: // if 0 is pressed
            P3OUT = 0x00;
            break;
        case 13: // if 1 is pressed
            P3OUT = 0x01;
            break;
        case 14: // if 4 is pressed
            P3OUT = 0x04;
            break;
        case 15: // if 7 is pressed
            P3OUT = 0x07;
            break;
        case 16: // if * is pressed
            P3OUT = 0xFF;
            break;
    }
}
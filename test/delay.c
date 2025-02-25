void delay() {
    volatile unsigned int i;
    for (i = 0xFFFF; i > 0; i--);
}
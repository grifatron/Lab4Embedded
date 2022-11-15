#include <msp430.h>
int main(void)
{
    WDTCTL = WDT_ADLY_250;                      // WDT 2500ms, SMCLK, interval timer
    P6OUT &= ~BIT0;                             // P6.0 Output (connected to green LED)
    P6DIR |= BIT0;
    PM5CTL0 &= ~LOCKLPM5;
    SFRIE1 |= WDTIE;
    _enable_interrupts();
    while (1);
    }
    #pragma vector=WDT_VECTOR
    __interrupt void wdtled(void)
    {
            P6OUT^=BIT0;
    }

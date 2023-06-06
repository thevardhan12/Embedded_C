#include<xc.h>
void init_config();
void init_timer0();


void init_config()
{
    ADCON1=0X0F;
    TRISB=0X00;
    PORTB=0X00;
    init_timer0();

}
void init_timer0()
{
    GIE=1;
    PEIE=1;
    TMR0IE=1;
    TMR0IF=0;
    TMR0ON=1;
    T08BIT=1;
    T0CS=0;
    PSA=1;
    TMR0=6;
}
void interrupt isr()
{
    static unsigned int count;
    if(TMR0IF)
    {
        TMR0=TMR0+8;
        if(count++ == 20000)
        {
            PORTB = ~PORTB;
            count=0;
        }
        TMR0IF=0;
    }
}

void main()
{
    init_config();
    while (1)
    {
        /* code */
    }
    
}
/*
Name:Harshavardhana B
Date:
Discripton:
Sample input:
Sample output:
*/
#include <xc.h>
void init_config();
void init_timer0();
void init_timer1();
void init_timer2();

void main()
{
    init_config();
    while (1)
    {
        ;
    }
}
void init_config()
{
    PEIE = 1;
    TRISB = 0X00;
    PORTB = 0x00;

    ADCON1 = 0x0F;
    init_timer0();
    init_timer1();
    init_timer2();
    GIE = 1;
}
void init_timer0()
{
    TMR0ON = 1;
    TMR0IF = 0;
    TMR0IE = 1;
    T0CS = 0;
    T08BIT = 1;
    TMR0 = 6;
    PSA = 1; // no preesaclar
}
void init_timer1()
{
    TMR1ON = 1;
    TMR1IF = 0;
    TMR1IE = 1;
    TMR1 = 3036;
    TMR1CS = 0;
    T1OSCEN = 1;
}

void init_timer2()
{
    TMR2ON = 1;
    TMR2IF = 0;
    TMR2IE = 1;
    TMR2 = 6;
}
void interrupt isr()
{
    static unsigned int count0, count1, count2;
    if (TMR0IF)
    {

        // RB0 = 1;
        TMR0 = TMR0 + 8;

        if (count0++ == 20000)
        {
            count0 = 0;
            RB0 = !RB0;
        }
        TMR0IF = 0;
    }
    if (TMR1IF)
    {
        //  RB1 = 1;
        TMR1 = TMR1 + 3038;
        if (count1++ == 80)
        {
            RB1 = !RB1;
            count1 = 0;
        }
        TMR1IF = 0;
    }
    if (TMR2IF)
    {
        //  RB2 = 1;
        TMR2 = TMR2 + 8;
        if (count2++ == 20000)
        {
            RB2 = !RB2;
            count2 = 0;
        }
        TMR2IF = 0;
    }
}
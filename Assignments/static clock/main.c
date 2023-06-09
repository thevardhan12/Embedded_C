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
static unsigned int half_sec, sec;
static int hour = 12, minute;
unsigned char ssd[4];
unsigned char data[] = {0xe7, 0x21, 0xcb, 0x6b, 0x2d, 0x6e, 0xee, 0x23, 0xef, 0x6f};

void main()
{
    init_config();
    ssd[1] = data[(hour % 10)];
    ssd[0] = data[((hour / 10) % 10)];
    ssd[3] = data[minute % 10];
    ssd[2] = data[(minute / 10) % 10];

    while (1)
    {
        for (int i = 0; i < 4; i++)
        {
            PORTD = ssd[i];
            PORTA = (PORTA & 0Xf0) | (1 << i);
            for (unsigned int j = 0; j < 1000; j++)
                ;
        }
        if (half_sec == 2)
        {

            half_sec = 0;
            minute++;
            if (minute == 60)
            {
                hour++;
                minute = 0;
                if (hour == 24)
                {
                    hour = 0;
                }
            }

            ssd[0] = data[(hour / 10) % 10];
            ssd[3] = data[minute % 10];
            ssd[2] = data[(minute / 10) % 10];
        }
        if (half_sec % 2)
            ssd[1] = data[(hour % 10)] | 0x10;
        else
            ssd[1] = data[(hour % 10)];
    }
}
void init_config()
{
    TRISD = 0X00;
    TRISA = TRISA & 0XF0;
    PORTA = PORTA & 0XF0;
    init_timer0();
}
void init_timer0()
{
    GIE = 1;
    PEIE = 1;
    TMR0IE = 1;
    TMR0IF = 0;
    TMR0ON = 1;
    T08BIT = 1;
    T0CS = 0;
    PSA = 1;
    TMR0 = 6;
}
void interrupt isr()
{

    static int count;
    if (TMR0IF)
    {
        TMR0 = TMR0 + 8;
        if (count++ == 10000)
        {
            half_sec++;

            count = 0;
        }
        TMR0IF = 0;
    }
}
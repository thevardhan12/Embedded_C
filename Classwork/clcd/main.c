/*
Name:Harshavardhana B
Date:
Discripton:
Sample input:
Sample output:
*/
#include <xc.h>
void init_config();
void init_clcd();

void main()
{
    init_config();
    while (1)
    {
    }
}
void init_config()
{
    init_clcd();
}
void init_clcd()
{
    TRISD = 0X00;
    TRISC = TRISC & 0XF8; ////8 -BIT MODE
    __delay_ms(30);       /// 30 micro sececonds of delay after start
    PORTD = 0X30;

    RC1 = 0;
    RC0 = 0;
    __delay_us(4100); /// 4.1  micrseconds of delay
}

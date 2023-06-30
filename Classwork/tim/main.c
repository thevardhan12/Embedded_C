/*
Name:Harshavardhana B 
Date:
Discripton:
Sample input:
Sample output:
*/
#include<xc.h>
void init_config();
//int time=0;
void main()
{
while(1)
{
    ;

}


}
void interrupt isr()
{
    static int count=0;
    if(TMR0IF)
    {
        TMR0=TMR0+8;
        if(count++ == 20000)
        {
            PORTB = 0XAA;
            count=0;
        }
        TMR0IF=0;
    }
    
}
void init_config()
{
    TMR0ON=1;
    TMR0IF=0;
    TMR0IE=1;
    GIE=1;
    PEIE=1;
    //PSA=0;
    T08BIT=1;
    T0CS=0;
    TMR0=6;
    //T0CON=T0CON | 0X01;
    TRISB=0X00;

}
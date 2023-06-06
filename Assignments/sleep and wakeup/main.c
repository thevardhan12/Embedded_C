/*
Name:Harshavardhana B 
Date:
Discripton:
Sample input:
Sample output:
*/
#include<xc.h>
void init_config();
void init_interrupt();

void display(unsigned char *ssd);
void main()
{
    init_config();
     unsigned char ssd[4];
     unsigned char count=0;
     unsigned int delay=0;

    while(1)
    {
        ssd[0]=0x21;
        ssd[1]=0xcb;
        ssd[2]=0x6b;
        ssd[3]=0x2d;
        display(ssd);
        if(delay++ ==  100)
        {
            count++;
            RB1=~RB1;
            delay=0;
        }
        if(count == 5)
        {
            count = 0;
            SLEEP();
        }



    }


}
void init_config()
{
    TRISD=0X00;         // tri state pin as to be 0 because the SSD is giving output from MC
    TRISA=TRISA & 0XF0; //to controll the ssd we are using control port A (A0,A1,A2,A3)
    RB1=0;             //initilising the LED 1 to toggle 
    TRISB0=1;      // B0 is pin used as external inerrupt where MC will accept the input from the inrterrupt
    TRISB1=0;          // B1 led 1 is making as the output pin
    PORTA=PORTA & 0XF0;
    PORTD=0X00;
    init_interrupt();
 
}
void display(unsigned char *ssd)
{
    for (int  i = 0; i <4; i++)
    {
        PORTD=ssd[i];
        PORTA=(PORTA & 0XF0) | (1<<i);
        for (int  j = 0; j < 1000; j++)
        {
            /* code */
        }
        
    }
    
}
void init_interrupt()
{
    GIE=1;
    PEIE=1;
    INT0IF=0;
    INT0IE=1;
    INTEDG0=0;
}
void interrupt isr()
{
    if(INT0IF)
    {
        INT0IF=0;
    }
}
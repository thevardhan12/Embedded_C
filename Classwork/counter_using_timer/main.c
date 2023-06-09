/*
Name:Harshavardhana B 
Date:
Discripton:
Sample input:
Sample output:
*/
#include<xc.h>
void init_config();
void init_timer0();

   unsigned char ssd[4];  
    unsigned char data[]={0xe7,0x21,0xcb,0x6b,0x2d,0x6e,0xee,0x23,0xef,0x6f};


void main()
{
    init_config();

while(1)
{
    
    for(int i=0;i < 4;i++)
            {
	            PORTD=ssd[i];
	            PORTA=(PORTA & 0Xf0 ) | (1<<i);
	            for(unsigned int j =0;j<1000;j++);
            }


}


}

void init_config()
{
    TRISD=0X00;
    TRISA=TRISA & 0XF0;
    PORTA=PORTA & 0XF0;
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
 

    static int count;
    static int number;
    if(TMR0IF)
    {
        TMR0=TMR0 +8;
        if(count++ == 20000)
        {
            number++;
            count=0;
            ssd[3]=data[number % 10];
	        ssd[2]=data[(number / 10)%10];
	        ssd[1]=data[(number /100)%10];
	        ssd[0]=data[(number/1000)];
            
	        


        }
        TMR0IF=0;

    }
}

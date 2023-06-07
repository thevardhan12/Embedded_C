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
    //SLEEP();
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
    TMR1IE=1;
    TMR1IF=0;
    TMR1ON=1;
    TMR1CS=0;
    T1CONbits.RD16=1;
    TMR1=3036;
    T1OSCEN=0;
}
void interrupt isr()
{
 

    static int count;
    static int number;
    if(TMR1IF)
    {
        TMR1=TMR1+3038;
        if(count++ == 80)
        {
            number++;
            count=0;
            ssd[3]=data[number % 10];
	        ssd[2]=data[(number / 10)%10];
	        ssd[1]=data[(number /100)%10];
	        ssd[0]=data[(number/1000)];
            
	        


        }
        TMR1IF=0;

    }
}

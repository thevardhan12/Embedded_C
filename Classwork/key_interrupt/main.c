/*
Name:Harshavardhana B 
Date:
Discripton:
Sample input:
Sample output:
*/
#include<xc.h>
void   init_exr_config();

void init_config();
void   init_exr_config();
void main()
{
    char ssd[4];
    unsigned char delay=0,count=0; 
while(1)
{
    ssd[0]=0xe7;
    ssd[1]=0x21;
    ssd[2]=0xcb;
    ssd[3]=0x6b;
    display(ssd);
    if(delay++ > 200)
    {
       // RB1=0X00;
        RB1=!RB1;
        count++;
        delay=0;
    }
    if(count==5)
    {
        count=0;
        SLEEP();
    }




}


}

void init_config()
{
    ADC0N1=0X0F;
    TRISB0=1;
    TRISB1=0;
    PORTB=0;
    TRISD=0X00;
    PORTD=PORTD & 0XF0;
    TRISA=TRISA & 0XF0;
    init_exr_config();

}m
void   init_exr_config()
{
    GIE=1;
    PEIE=1;
    INT0IE=1;
    INTOIF=0;
    INTEDGO=0;
}
void interrupt isr()
{
    if(INTFOIF)
    {
        INTFOIF=0;


    }
}
void display()
{
    for (int  i = 0; i < 4; i++)
    {
        PORTD=ssd[i];
	  PORTA=(PORTD & 0Xf0 ) | (1<<i);
	  for(unsigned int j =0;j<1000;j++);
      for(unsigned int i=1000;;i--);
    }
    
}
/*
Name:Harshavardhana B 
Date:
Discripton:
Sample input:
Sample output:
*/
#include<xc.h>
void init_config();
void display(unsigned char *ssd);
unsigned char data[]={0xe7,0x21,0xcb,0x6b,0x2d,0x6e,0xee,0x23,0xef,0x6f,0x40,0x40};
unsigned char ssd[4];  
unsigned long wait=1000,i=0;
void main()
{
    init_config();
while(1)
{
    if(wait-- ==0 )
    {
        i++;
        wait=1000;
    }
      ssd[0]=data[i % 12];
        ssd[1]=data[(i + 1)%12];
        ssd[2]=data[((i+2) %12)];
        ssd[3]=data[(i+3)%12];
        display(ssd);




}


}
void init_config()
{
    TRISD=0X00;
    TRISA=TRISA & 0XF0;
    PORTD=0X00;
}

void display(unsigned char *ssd)
{
    for(int i=0;i < 4;i++)
    {
        PORTD=ssd[i];
        PORTA=(PORTA & 0Xf0 ) | (1<<i);
        for(unsigned int j =0;j<1000;j++);
    }


}



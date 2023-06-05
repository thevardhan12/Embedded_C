#include<xc.h>
int main()
{
    void init_config();
    init_config();
    void display(unsigned char *ssd);
    unsigned char i=5;
    unsigned char data[]={0xe7,0x21,0xcb,0x6b,0x6c,0xb6,0xee,0x23,0xef,0x2f};
    unsigned char ssd[4];   
    while(1)
    {
        ssd[0]=0x8e;
        ssd[1]=0xe5;
        ssd[2]=0xc6;
        ssd[3]=0xac;


        display(ssd);
    }
}
//SETTING THE CONFIGURATION 
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



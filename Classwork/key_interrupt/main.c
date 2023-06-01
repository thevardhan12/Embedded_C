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
void main()
{
while(1)
{

}


}
void init_config()
{
    ADC0N1=0X0F;
    TRISB=0X01;
    PORTB=PORTB & 0X01;
    init_exr_config();

}
void   init_exr_config()
{
    GIE=1;
    PEIE=1;
    INT0IE=1;
    INT
}
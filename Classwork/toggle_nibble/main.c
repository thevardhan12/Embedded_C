#include<xc.h>
void delay();
void main()
{
     TRISB=0x00;
     PORTB=0xf0;
     while(1)
     {
	  PORTB=~PORTB;
	  delay();
     }
     /*for(i=0;i<8;i++)
       {
       PORTB=0x00;
       PORTB=PORTB|(1>>i);
       delay();
       }*/


}
void delay()
{
     for(unsigned int i=50000;i;i--);
     for(unsigned int i=50000;i;i--);

}









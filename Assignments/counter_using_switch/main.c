/*
Name:Harshavardhana B 
Date:
Discripton:
Sample input:
Sample output:
 */
#include<xc.h>

void init_config();
unsigned char read_digital_key();
void display(unsigned char *ssd);
unsigned char data[]={0xe7,0x21,0xcb,0x6b,0x2d,0x6e,0xee,0x23,0xef,0x6f};
unsigned char ssd[4];   


void main()
{
     init_config();
     unsigned char key; 
     unsigned int delay=0,wait=0;

     unsigned int count=0;
     while(1)
     {       
	  key=read_digital_key();





	  if(key==0)
	  {
	       if(++wait == 200)
		    count=0;
	  }

	  else if(wait>0 && wait <200)
	  {
	       count++;
	       wait=0;
	  }
	  else
	  {
	       wait=0;
	  }
	  ssd[3]=data[count % 10];
	  ssd[2]=data[(count / 10)%10];
	  ssd[1]=data[(count /100)%10];
	  ssd[0]=data[(count/1000)];
	  display(ssd);
     }

}
void init_config()
{
     TRISD=0X00;
     TRISA=TRISA & 0XF0;
	 TRISC0=1;
     PORTD=0x00;
}
unsigned char read_digital_key()
{
     return (PORTC & 1);
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

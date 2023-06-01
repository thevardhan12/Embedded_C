/*
Name:Harshavardhana B 
Date:
Discripton:
Sample input:
Sample output:
 */
#include<xc.h>

#define edge 1
#define switch1 0x0e
#define switch2 0x0d
#define switch3 0x0b
#define switch4 0x07

void init_config();

unsigned char read_digital_keypad(unsigned char detection);
void patteren1();
void patteren2();
void patteren3();
void patteren4();
void main()
{
     init_config();
     unsigned char key;
     patteren1();
     while(1)
     {

	  key=read_digital_keypad(edge);
	  if(key==switch1)
	  {
	       patteren1();
	  }
	  else if(key==switch2)
	  {
	       patteren2();
	  }
	  else if(key==switch3)
	  {
	       patteren3();
	  }
	  else if(key==switch4)
	  {
	       patteren4();
	  }



     }


}

//initializing the configuration
void init_config()
{
     TRISB=0x00;
     TRISC=TRISC|0x0F;
     PORTB=0x00;
}

//reading th switch value

unsigned char read_digital_keypad(unsigned char detection)
{
     static unsigned char once=1;

     if(detection ==1)
     {
	  if((PORTC & 0x0f) && once)
	  {
	       once =0;
	       return (PORTC & 0x0f);
	  }
	  
     
     else if( (PORTC & 0x0f)==0x0f)
     {
	  once=1;
      return 0x0f;
     }
     
     }
}


///patteren 1 train entering and leaaving the tunnel in two ways
void patteren1()
{
     unsigned char count=0;
     unsigned long int delay=0;

     if(++delay >=5000)
     {
	  if(count <8)
	  {
	       PORTB=PORTB<<1 | 1;
	  }
	  else if( count <16)
	  {
	       PORTB=PORTB<<1;


	  }
	  else if(count <23)
	  {
	       PORTB=PORTB>>1 | 0x80;

	  }
	  else if(count <31)
	  {
	       PORTB=PORTB>>1;

	  }
	  count ++;
	  delay=0;



     }
}

///patteren two train only entering to the tunnel in only one way


void patteren2()
{
     unsigned char count=0;
     unsigned long int delay=0;
     if(++delay >=5000)
     {
	  if(count <8)
	  {
	       PORTB=PORTB<<1 | 1;
	  }
	  else if( count <16)
	  {
	       PORTB=PORTB<<1;
	  }

     }
     count ++;
     delay=0;



}


//if we press switch 3 all the led should blink alternatively

void patteren3()
{

     unsigned long int delay=0;
     unsigned char flag=1;
     if(delay++ >= 50000)
     {
	  if(flag==1)
	  {
	       PORTB=0xaa;
	       flag++;

	  }

	  else if(flag==2)
	  {
	       PORTB=~PORTB;
	       flag=1;
	  }


     }



}
void patteren4()
{
     unsigned long int delay=0;
     unsigned char flag=1;
     if(delay++ >= 50000)
     {
	  if(flag==1)
	  {
	       PORTB=0xf0;
	       flag++;

	  }
	  else if(flag==2)
	  {
	       PORTB=~PORTB;
	       flag=1;
	  }



     }



}



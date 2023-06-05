/*
Name:Harshavardhana B 
Date:
Discripton:
Sample input:
Sample output:
 */
#include<xc.h>
void init_config();
void main()
{
     void init_config();
     init_config();
     unsigned char count=0;
     unsigned long int delay=0;

     while(1)
     {
	  if(++delay >=50000)
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
	       else if(count <32)
	       {
		    PORTB=PORTB>>1;
			if(count==31)
			{
				count=0;
			}

	       }
		   

	       delay=0;
	       count ++;


	  }

     }
    // for(unsigned int i=500;i;i--);
}

void init_config()
	       {
	       TRISB=0x00;
	       PORTB=0x00;

	       }


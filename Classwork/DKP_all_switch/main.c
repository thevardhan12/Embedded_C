/*
Name:Harshavardhana B 
Date:
Discripton:
Sample input:
Sample output:
*/
#include<xc.h>
void init_config();
unsigned char read_digital_keypad(unsigned char detection);

void main()
{
unsigned char key;
init_config();
unsigned int i=0;
while(1)
{
key=read_digital_keypad(0);
if( i==5000)
{
if(key!=0x0F)
{
PORTB=~PORTB;
i=0;

}
}

i++;


}


}
void init_config()
{
TRISC=TRISC | 0x0f;                                                          //TRIS has to be 1  if microcontroller will accept input.
TRISB=0x00;
PORTB=0x00;								//TRIS has to be 0 if microcontroller will give the output.
}	
unsigned char read_digital_keypad(unsigned char detection)
{
static unsigned char once=1;

if(detection ==0)
{
return (PORTC & 0x0f);

}
else if(detection ==1)
{
if(PORTC & 0x0f && once)
{
once =0;
return PORTC & 0x0f;
}
return 0x0f;
}

else if( (PORTC & 0x0f)==0x0f)
{
once=1;
}




}

													

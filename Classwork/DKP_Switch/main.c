/*
Name:Harshavardhana B 
Date:
Discripton:
Sample input:
Sample output:
*/
#include<xc.h>
void init_config();
void edge();
void level();

void main()
{
init_config();
while(1)
{
level();
}
/*while(1)
{
edge();
}*/
}
void init_config()
{
TRISB=0x00;
TRISC=TRISC|0x0F;
PORTB=0x00;
}

void level()
{
if(RC0==0)
{
PORTB=0xff;
}
else if(RC0==1)
{
PORTB=0x00;
}
for(unsigned int i=50000;i;i++);
}


void edge()
{
unsigned int once=1;
if(RC1==0 && once)
{
PORTB=~PORTB;
once=0;
}
else if(RC1==1)
{
once=1;
}
for(unsigned int i=50000;i;i++);
for(unsigned int i=50000;i;i++);
}




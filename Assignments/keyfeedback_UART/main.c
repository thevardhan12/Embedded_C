/*
Name:Harshavardhana B 
Date:
Discripton:
Sample input:
Sample output:
*/
#include<xc.h>
void init_config();
unsigned char read_digital_keypad(unsigned char detection_type);
void putch(unsigned char byte);
int puts(const char *s);
unsigned char getch(void);
unsigned char getche(void);
void init_uart();
#define INPUT_PINS  0x0f
#define LEVEL					     	0
#define STATE_CHANGE			       	1

#define KEY_PORT					PORTC

#define SWITCH1					0x0E
#define SWITCH2					0x0D
#define SWITCH3					0x0B
#define SWITCH4					0x07
#define ALL_RELEASED					0x0F


void main()
{
    unsigned char key;
    char c;
    init_config();
while(1)
{
   key = read_digital_keypad(STATE_CHANGE);
   if(key == SWITCH1)
   {
    puts("switch 1 is pressed ");
   }
   else if(key == SWITCH2)
   {
     puts("switch 2 is pressed ");

   }
   else if(key == SWITCH3)
   {
    puts("switch 3 is pressed ");

   }
    else if(key == SWITCH4)
   {
    puts("switch 4 is pressed ");

   }
}


}
void init_config()
{
    init_uart();
}
void init_uart()
{
    TRISC = TRISC | 0x0F;
    TXIE=1;
    TXIF=0;
    TRISC6=0;
    TRISC7=1;
    TX9D=0;
    TXEN=1;
    SYNC=0;
    SENDB=1;
    TRMT=1;
    BRGH=1;
    SPEN=1;
    RX9=0;
    SREN=0;
    CREN=1;
    FERR=0;
    OERR=0;
    RX9D=0;
    ABDOVF=0;
    RCIDL=1;
    SCKP=0;
    BRG16=0;
    ABDEN=0;
    RCIE=1;
    RCIF=0;
}
void putch(unsigned char byte) 
{
	/* Output one byte */
	/* Set when register is empty */
	while(!TXIF)
	{
		continue;
	}
	TXREG = byte;
}
int puts(const char *s)
{
	while(*s)		
	{
		putch(*s++);	
	}

	return 0;
}
unsigned char getch(void)
{
	/* Retrieve one byte */
	/* Set when register is not empty */
	while(!RCIF)
	{
		continue;
	}

	return RCREG;
}
unsigned char getche(void)
{
	unsigned char c;

	putch(c = getch());

	return (c);
}
unsigned char read_digital_keypad(unsigned char detection_type)
{
	static unsigned char once = 1;

	if (detection_type == STATE_CHANGE)
	{
		if (((KEY_PORT & INPUT_PINS) != ALL_RELEASED) && once)
		{
			once = 0;

			return (KEY_PORT & INPUT_PINS);
		}
		else if ((KEY_PORT & INPUT_PINS) == ALL_RELEASED)
		{
			once = 1;
		}
	}
	else if (detection_type == LEVEL)
	{
		return (KEY_PORT & INPUT_PINS);
	}

	return 0xFF;
}
/*
Name:Harshavardhana B 
Date:
Discripton:
Sample input:
Sample output:
*/
#include"password.h"
#include"matrix_keypad.h"
void init_config();
void main()
{

	init_config();
	int chance=3;
    long int delay=0;
	 clcd_print("Enter Password",LINE1(0));
while(1)
{
   
    if(delay++<25000)
    {
        clcd_putch('_',LINE2(0));

    }
    else if(delay <50000)
    {
        check_matrix_keypad();
    }
	else
	{
		delay=0;
	}
	char flag=1;
	for(int i=0;pre_passw[i]!='\0';i++)
	{
		if(passw[i]!=pre_passw[i])
		{
			flag=0;
		}
		

	}
	if(flag)
	{
		clcd_print("Successfull",LINE2(0));

	}
	else
	{
		unsigned long int delay=0;
		chance--;
		if(chance==2)
		{
			clcd_print("attemps left:2",LINE2(0));
			
		}
		else if (chance ==1)
		{
			clcd_print("attemps left:1",LINE2(0));
		}
		else
		{
			clcd_print("FAILED",LINE2(0));
		}
		
		

	}
    


}


}
void clcd_print(const unsigned char *data, unsigned char addr)
{
	clcd_write(addr, INSTRUCTION_COMMAND);
	while (*data != '\0')
	{
		clcd_write(*data++, DATA_COMMAND);
	}
}

void clcd_write(unsigned char byte, unsigned char control_bit)
{
	PORTD = control_bit;
	PORTD = byte;

	/* Should be atleast 200ns */
	RC2 = 1;
	RC2 = 0;

	TRISD = 0XFF;
	RC0 = 1;
	RC1 = INSTRUCTION_COMMAND;

	do
	{
		RC2 = 1;
		RC2 = 0;
	} while (RD7);

	RC0 = 0;
	TRISD = 0X00;
}
void check_matrix_keypad()
{
    unsigned char key;
	 unsigned int i;
    

	key = read_switches(1);

	if (key != 0xff)
	{
        for(int i=0;i<8;i++)
        {
			passw[i]=key;
            clcd_putch('*' , LINE2(0));

        }
		for (i = 50000; i--;);
	}

}
unsigned char read_switches(unsigned char detection_type)
{
    static unsigned char once = 1, key;

	if (detection_type == 1)
	{
		key = scan_key();
		if(key != 0xFF && once  )
		{
			once = 0;
			return key;
		}
		else if(key == 0xFF)
		{
			once = 1;
		}
	}
	else if (detection_type == 0)
	{
		return scan_key();
	}

	return 0xFF;
}
unsigned char scan_key()
{
    ROW1 = 0;
	ROW2 = 1;
	ROW3 = 1;

	if (COL1 == 0)
	{
		return 1;
	}
	else if (COL2 == 0)
	{
		return 4;
	}
	else if (COL3 == 0)
	{
		return 7;
	}
	else if (COL4 == 0)
	{
		return 10;
	}

	ROW1 = 1;
	ROW2 = 0;
	ROW3 = 1;

	if (COL1 == 0)
	{
		return 2;
	}
	else if (COL2 == 0)
	{
		return 5;
	}
	else if (COL3 == 0)
	{
		return 8;
	}
	else if (COL4 == 0)
	{
		return 11;
	}

	/*ROW1 = 1;
	ROW2 = 1;
	ROW3 = 0;
	/* TODO: Why more than 2 times? */
	/*ROW3 = 0;

	if (COL1 == 0)
	{
		return 3;
	}
	else if (COL2 == 0)
	{
		return 6;
	}
	else if (COL3 == 0)
	{
		return 9;
	}
	else if (COL4 == 0)
	{
		return 12;
	}*/

	return 0xFF;
}

void init_config()
{
	TRISB=0X00;
	PORTB=0X00;
	//CLCD CONFIGURATION
	/* Set PortD as output port for CLCD data */
	TRISD = 0x00;
	/* Set PortC as output port for CLCD control */
	TRISC = TRISC & 0xF8;

	RC0 = 0;

	CURSOR_HOME;
	TWO_LINE_5x8_MATRIX_8_BIT;
	DISP_ON_AND_CURSOR_OFF;
	CLEAR_DISP_SCREEN;
	
}
#include<xc.h>
#include<string.h>

#define LINE1(x) (0x80 + (x))
#define LINE2(x) (0xC0 + (x))
#define DATA_COMMAND			1
#define INSTRUCTION_COMMAND		0
#define TWO_LINE_5x8_MATRIX_8_BIT  clcd_write(0x38, INSTRUCTION_COMMAND)
#define CLEAR_DISP_SCREEN 		 clcd_write(0x01, INSTRUCTION_COMMAND)
#define DISP_ON_AND_CURSOR_OFF	clcd_write(0x0C, INSTRUCTION_COMMAND)
static  char passw[9];
#define CURSOR_HOME	 clcd_write(0x02, INSTRUCTION_COMMAND)
char pre_passw[9];
#define ROW3					PORTBbits.RB7
#define ROW2					PORTBbits.RB6
#define ROW1					PORTBbits.RB5
#define COL4					PORTBbits.RB4
#define COL3					PORTBbits.RB3
#define COL2					PORTBbits.RB2
#define COL1					PORTBbits.RB1
						
void init_clcd(void);
void clcd_print(const unsigned char *data, unsigned char addr);
void clcd_putch(const unsigned char data, unsigned char addr);
void clcd_write(unsigned char bit_values, unsigned char control_bit);
void init_matrix_keypad(void);
void check_matrix_keypad();
unsigned char scan_key(void);
unsigned char read_switches(unsigned char detection_type);

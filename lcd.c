/*
 * lcd.c
 *
 * Created: 19/01/2024 08:20:53 م
 *  Author: AMR MOSTAFA
 */
#include "lcd.h" 
 static void generate_falling_edge(void)
{
	DIO_WRITE(CONTROLPORT,EN,1);
	_delay_ms(5);
	DIO_WRITE(CONTROLPORT,EN,0);
	_delay_ms(5);
}
void lcd_send_cmd(char cmd )
{
	#if defined  eight_bit_mode
	DIO_PORT_WRITE(DATAPORT,cmd);
	DIO_WRITE(CONTROLPORT,RS,0);
	generate_falling_edge();
	#elif defined four_bits_mode
	dio_write_high_nibble(DATAPORT,cmd);
	DIO_WRITE(CONTROLPORT,RS,0);
	generate_falling_edge();
	dio_write_high_nibble(DATAPORT,cmd<<4);
	DIO_WRITE(CONTROLPORT,RS,0);
	generate_falling_edge();
	_delay_ms(1);
	#endif
}
void lcd_send_char( char data)
{
	#if defined eight_bit_mode 
	DIO_PORT_WRITE(DATAPORT,data);
	DIO_WRITE(CONTROLPORT,RS,1);
	generate_falling_edge();
	#elif defined four_bits_mode
	dio_write_high_nibble(DATAPORT,data);
	DIO_WRITE(CONTROLPORT,RS,1);
	generate_falling_edge();
	dio_write_high_nibble(DATAPORT,data<<4);
	DIO_WRITE(CONTROLPORT,RS,1);
	generate_falling_edge();
	_delay_ms(1);
	#endif
}
void lcd_initialize(void)
{
	#if defined eight_bit_mode
	DIO_SET_PORT_DIRECTION(DATAPORT,1);
	DIO_SET_PIN_DIRECTION(CONTROLPORT,EN,1);
	DIO_SET_PIN_DIRECTION(CONTROLPORT,RW,1);
	DIO_SET_PIN_DIRECTION(CONTROLPORT,RS,1);
	DIO_WRITE(CONTROLPORT,RW,0);
	lcd_send_cmd(EIGHT_BITS);
	_delay_ms(1);
	lcd_send_cmd(CURSOR_ON_DISPLAN_ON);
	_delay_ms(1);
	lcd_send_cmd(CLR_SCREEN);
	_delay_ms(1);
	lcd_send_cmd(ENTRY_MODE);
	_delay_ms(1);
	#elif defined four_bits_mode
	dio_set_high_nibble_direction(DATAPORT,1);
	DIO_SET_PIN_DIRECTION(CONTROLPORT,EN,1);
	DIO_SET_PIN_DIRECTION(CONTROLPORT,RW,1);
	DIO_SET_PIN_DIRECTION(CONTROLPORT,RS,1);
	DIO_WRITE(CONTROLPORT,RW,0);
	lcd_send_cmd(RETURN_HOME);
	_delay_ms(1);
	lcd_send_cmd(FOUR_BITS);
	_delay_ms(1);
	lcd_send_cmd(CURSOR_ON_DISPLAN_ON);
	_delay_ms(1);
	lcd_send_cmd(CLR_SCREEN);
	_delay_ms(1);
	lcd_send_cmd(ENTRY_MODE);
	_delay_ms(1);
	#endif
}
void lcd_send_string(char *str)
{
	while((*str)!='\0')
	{
		lcd_send_char(*str);
		_delay_ms(1);
		str++;
	}
}
void lcd_clr_screen(void)
{
	lcd_send_cmd(CLR_SCREEN);
	_delay_ms(2);
}
void lcd_move_curser(char row, char coloumn)
{
	char data;
	if (row>2||row<1||coloumn>16||coloumn<1)
	{
		data = 0x80;
	}
	else if(row==1)
	{
		data= 0x80+coloumn-1;
	} 
	else if (row==2)
	{
		data = 0xc0+coloumn-1;
	}
	lcd_send_cmd(data);
}
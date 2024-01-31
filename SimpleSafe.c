/*
 * SimpleSafe.c
 *
 * Created: 21/01/2024 10:22:26 ص
 *  Author: AMR MOSTAFA
 */ 


#include <avr/io.h>
#include "lcd.h"
#include "EEPROM.h"
#include "keypad.h"

#include "button.h"
#define  F_CPU 8000000UL
#include <util/delay.h>


int main(void)
{
	char value =0xff,flag=2,i,arr[4]={0xff,0xff,0xff,0xff};
	lcd_initialize();
	lcd_send_cmd(0x0c);
	key_bad_initialize();
	button_initialize('d',0);
	button_pull_up_res('d',0);
	button_initialize('b',4);
	button_pull_up_res('b',4);
	if (eeprom_read(0x30)==0xff)
	{
		lcd_send_string("SetYourPassword");
		lcd_move_curser(2,1);
		for(i=0;i<4;i++)
		{	
			do 
			{
				value = key_bad_read();
			} while (value==0xff);
			lcd_send_char(value);
			lcd_move_curser(2,1+i);
			_delay_ms(10);
			lcd_send_char('*');
			eeprom_write(0x31+i,value);	
		}
		eeprom_write(0x30,0x00); 
	}		
	
    while(flag!=0)
    {
		lcd_clr_screen();
		lcd_send_string("enterPassTries=");
		lcd_send_char(flag+48);
		lcd_move_curser(2,1);
		for(i=0;i<4;i++)
		{
			do
			{
				arr[i]=key_bad_read();
			} while (arr[i]==0xff);
			_delay_ms(10);
			lcd_send_char(arr[i]);
			lcd_move_curser(2,1+i);
			_delay_ms(10);
			lcd_send_char('*');
		}
		if (arr[0]==eeprom_read(0x31)&&arr[1]==eeprom_read(0x32)&&arr[2]==eeprom_read(0x33)&&arr[3]==eeprom_read(0x34))
		{
			lcd_clr_screen();
			lcd_move_curser(1,1);
			lcd_send_string("safe open");
			flag=0;
			while (button_read('d',0)==1&&button_read('b',4)==1);
				if (button_read('d',0)==0)			
				{	
					lcd_clr_screen();
					lcd_move_curser(1,1);
					lcd_send_string("SetNewPassword");
					lcd_move_curser(2,1);
					for(i=0;i<4;i++)
					{
						do
						{
							value = key_bad_read();
						} while (value==0xff);
						lcd_send_char(value);
						lcd_move_curser(2,1+i);
						_delay_ms(10);
						lcd_send_char('*');
						eeprom_write(0x31+i,value);
					}
				}
				else if (button_read('b',4)==0)
				{
					lcd_clr_screen();
					lcd_send_string("safe is closed");
					_delay_ms(100);
					lcd_clr_screen();
				}					
				flag=2;
			}
		else 
		{
			flag--;
			if (flag==0)
				{
					lcd_clr_screen();
					lcd_send_string("wrong pass");
					lcd_move_curser(2,1);
					lcd_send_string("no more tries");
				}
		}
	}	
		
}		
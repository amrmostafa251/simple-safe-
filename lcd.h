/*
 * lcd.h
 *
 * Created: 19/01/2024 08:21:04 م
 *  Author: AMR MOSTAFA
 */ 



#ifndef LCD_H_
#define LCD_H_
#define CLR_SCREEN 0x01
#define CURSOR_ON_DISPLAN_ON 0x0e
#define RETURN_HOME 0x02
#define ENTRY_MODE 0x06
#define EIGHT_BITS 0x38
#define FOUR_BITS 0x28

#include "DIO.h"
#include "lcd_config.h"
#define  F_CPU 8000000UL
#include <util/delay.h>

void lcd_send_cmd(char cmd );
void lcd_send_char(char data );
void lcd_initialize(void);
void lcd_send_string(char *str);

void lcd_clr_screen(void);
void lcd_move_curser(char row, char coloumn);

#endif /* LCD_H_ */
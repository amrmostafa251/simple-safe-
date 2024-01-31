/*
 * EEPROM.c
 *
 * Created: 14/01/2024 10:52:13 ص
 *  Author: AMR MOSTAFA
 */ 
#include "std_macros.h"
#include <avr/io.h>
eeprom_write(unsigned short address , unsigned char data )
{
	EEAR = address;
	EEDR = data;
	SET_BIT(EECR ,EEMWE);
	SET_BIT(EECR ,EEWE);
	while(READ_BIT(EECR,EEWE)==1);
}
unsigned char eeprom_read (const unsigned short address )
{
	EEAR= address;
	SET_BIT(EECR,EERE);
	return EEDR;
}
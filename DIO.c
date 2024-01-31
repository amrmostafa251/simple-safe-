/*
 * DIO.c
 *
 * Created: 30/12/2023 11:20:39 م
 *  Author: AMR MOSTAFA
 */ 
#include "std_macros.h"
#include "DIO.h"
#include <avr/io.h>
#define F_CPU 8000000UL
#include<util/delay.h>
void  DIO_SET_PIN_DIRECTION (unsigned char portname , unsigned char pinnumber , unsigned char diraction )
{
	switch (portname)
	{
		case 'a' :
		case 'A' :
		if (diraction == 1 )
			SET_BIT (DDRA, pinnumber);
		else
			CLR_BIT (DDRA , pinnumber);
		break;
		case 'b' :
		case 'B' :
		if (diraction == 1 )
			{SET_BIT (DDRB, pinnumber);}
		else
			{CLR_BIT (DDRB , pinnumber);}
		break;
		case 'c' :
		case 'C' :
		if (diraction == 1 )
			{SET_BIT (DDRC, pinnumber);}
		else
			{CLR_BIT (DDRC , pinnumber);}
		break;
		case 'd' :
		case 'D' :
		if (diraction == 1 )
			{SET_BIT (DDRD, pinnumber);}
		else
			{CLR_BIT (DDRD , pinnumber);}
		break;
	}	
}
void  DIO_WRITE  (unsigned char portname , unsigned char pinnumber , unsigned char outputvalue )
{
	switch (portname)
	{
		case'a':
		case'A':
		 if (outputvalue==1 )
		 {
			 SET_BIT(PORTA,pinnumber);
		 }
		 else 
		 {
			 CLR_BIT(PORTA,pinnumber);
		 }
		 break;
		 case'b':
		 case'B':
		 if (outputvalue==1 )
		 {
			 SET_BIT(PORTB,pinnumber);
		 }
		 else
		 {
			 CLR_BIT(PORTB,pinnumber);
		 }
		 break;
		 case'c':
		 case'C':
		 if (outputvalue==1 )
		 {
			 SET_BIT(PORTC,pinnumber);
		 }
		 else
		 {
			 CLR_BIT(PORTC,pinnumber);
		 }
		 break;
		 case'd':
		case'D':
		 if (outputvalue==1 )
		 {
			 SET_BIT(PORTD,pinnumber);
		 }
		 else 
		 {
			 CLR_BIT(PORTD,pinnumber);
		 }
		 break;
	}
}
unsigned char  DIO_READ (unsigned char portname , unsigned char pinnumber  )
{
	unsigned char inputvalue;
	switch (portname)
	{
		case 'a':
		case 'A':
		inputvalue = READ_BIT(PINA,pinnumber);
		break; 
		case 'b':
		case'B':
		inputvalue = READ_BIT(PINB,pinnumber);
		break;
		case 'c':
		case'C':
		inputvalue = READ_BIT(PINC,pinnumber);
		break;
		case 'd':
		case'D':
		inputvalue = READ_BIT(PIND,pinnumber);
		break;		
	} 
	return inputvalue;
}
void  DIO_TOGGLE (unsigned char portname , unsigned char pinnumber )
{
	switch (portname)
	{
		case 'a':
		case 'A':
		TOG_BIT(PORTA,pinnumber);
		break; 
		case 'b':
		case 'B':
		TOG_BIT(PORTB,pinnumber);
		break;
		case 'c':
		case 'C':
		TOG_BIT(PORTC,pinnumber);
		break;
		case 'd':
		case 'D':
		TOG_BIT(PORTD,pinnumber);
		break;
	}
}
void DIO_SET_PORT_DIRECTION (unsigned char portname , unsigned char direction ) 
{
	switch(portname)
	{
		case 'a':
		case'A':
			DDRA = direction;
			break;
		case 'b':
		case'B':
			DDRB = direction;
			break;
		case 'c':
		case'C':
			DDRC = direction;
			break;
		case 'd':
		case'D':
			DDRD = direction;
			break;		
	} 
}
void DIO_PORT_WRITE (unsigned char portname , unsigned char outputvalue  ) 
{
	switch (portname)
	{
		case 'a':
		case 'A':
			PORTA = outputvalue;
			break;
		 case 'b':
		 case 'B':
			PORTB = outputvalue;
			break;
		case 'c':
		case 'C':
			PORTC = outputvalue;
			break;
		case 'd':
		case 'D':
			PORTD = outputvalue;
			break;
	}			
}
unsigned char  DIO_PORT_READ (unsigned char portname )
{
	unsigned char inputvalue ;
	switch (portname)
	{
		case 'a':
		case 'A':
			inputvalue= PINA;
			break;
		case 'b':
		case 'B':
			inputvalue= PINB;
			break;
		case 'c':
		case 'C':
			inputvalue= PINC;
			break;
		case 'd':
		case 'D':
		inputvalue= PIND;
		break; 
	}
	return inputvalue;
}
void DIO_PORT_TOGGLE (unsigned char portname)
{
	int value  ;
	switch (portname)
	{
		case 'a':
		case 'A':
		value = PINA;
		PORTA = (value) ^(0xff);
		break;
		case 'b':
		case 'B':
		value = PINB;
		PORTB = (value) ^(0xff);
		break;
		case 'c':
		case 'C':
		value = PINC;
		PORTC = (value) ^(0xff);
		break;
		case 'd':
		case 'D':
		value = PIND;
		PORTD = (value) ^(0xff);
		break;
	}
}
void  dio_internal_pull_up_res_intialize(unsigned char portname, unsigned char pinnumber)
{
	DIO_WRITE(portname,pinnumber,1);
}
void dio_set_high_nibble_direction(unsigned char portname,unsigned direction)
{
	switch (portname)
	{
		DIO_SET_PIN_DIRECTION(portname,4,direction);
		DIO_SET_PIN_DIRECTION(portname,5,direction);
		DIO_SET_PIN_DIRECTION(portname,6,direction);
		DIO_SET_PIN_DIRECTION(portname,7,direction);
	}
}
void dio_set_low_nibble_direction(unsigned char portname,unsigned direction)
{
	DIO_SET_PIN_DIRECTION(portname,0,direction);
	DIO_SET_PIN_DIRECTION(portname,1,direction);
	DIO_SET_PIN_DIRECTION(portname,2,direction);
	DIO_SET_PIN_DIRECTION(portname,3,direction);
}
void dio_write_high_nibble(unsigned char portname, unsigned char value )
{
	DIO_WRITE(portname,7,READ_BIT(value,7));
	DIO_WRITE(portname,6,READ_BIT(value,6));
	DIO_WRITE(portname,5,READ_BIT(value,5));
	DIO_WRITE(portname,4,READ_BIT(value,4));
}

void dio_write_low_nibble(unsigned char portname, unsigned char value )
{
	DIO_WRITE(portname,3,READ_BIT(value,3));
	DIO_WRITE(portname,2,READ_BIT(value,2));
	DIO_WRITE(portname,1,READ_BIT(value,1));
	DIO_WRITE(portname,0,READ_BIT(value,0));
}
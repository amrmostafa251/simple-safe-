/*
 * CFile1.c
 *
 * Created: 17/01/2024 12:43:35 ص
 *  Author: AMR MOSTAFA
 */ 
#include <avr/interrupt.h>
#include "std_macros.h"
void global_interrupt_enable(void )
{
	sei();
}
void INT0_enable(unsigned char control1,unsigned char control0 )
{
	SET_BIT(GICR,INT0);
	MCUCR|=(control0<<ISC00)|(control1<<ISC01);
	
}
void INT1_enable(unsigned char control1,unsigned char control0 )
{
	SET_BIT(GICR,INT1);
	MCUCR|=(control0<<ISC10)|(control1<<ISC11);
}
void INT2_enable(unsigned char control )
{
	SET_BIT(GICR,INT2);
	MCUCSR|=(control<<ISC2);
}
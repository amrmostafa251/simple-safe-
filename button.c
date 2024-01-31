/*
 * button.c
 *
 * Created: 31/12/2023 08:40:05 م
 *  Author: AMR MOSTAFA
 */ 
#include "button.h"
#include "DIO.h"
void button_initialize(unsigned char portname, unsigned char pinnumber )
{
	DIO_SET_PIN_DIRECTION(portname,pinnumber,0);
}
unsigned char button_read(unsigned char portname, unsigned char pinnumber )
{
	return DIO_READ(portname,pinnumber);
}
void button_pull_up_res(unsigned char portname, unsigned char pinnumber )
{
	dio_internal_pull_up_res_intialize(portname,pinnumber);
}
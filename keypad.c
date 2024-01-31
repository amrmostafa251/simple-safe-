/*
 * keypad.c
 *
 * Created: 20/01/2024 06:11:05 م
 *  Author: AMR MOSTAFA
 */ 
#include "keypad.h"
void key_bad_initialize()
{
	DIO_SET_PORT_DIRECTION(key_bad_port,0x0f);
	dio_internal_pull_up_res_intialize(key_bad_port,4);
	dio_internal_pull_up_res_intialize(key_bad_port,5);
	dio_internal_pull_up_res_intialize(key_bad_port,6);
	dio_internal_pull_up_res_intialize(key_bad_port,7);
}
 char key_bad_read()
{
	char arr[4][4]= {{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'a','0','=','+'}};
	char row,coloum,x;
	char return_val=0xff;
	for (row=0;row<4;row++)
	{
		DIO_WRITE(key_bad_port,0,1);
		DIO_WRITE(key_bad_port,1,1);
		DIO_WRITE(key_bad_port,2,1);
		DIO_WRITE(key_bad_port,3,1);
		DIO_WRITE(key_bad_port,row,0);
		for (coloum=0; coloum<4;coloum++)
		{
			x=DIO_READ(key_bad_port,(coloum+4));
			if (x==0)
			{
				return_val= arr[row][coloum];
				break;
			}
			
		}
		if (x==0)
		{
			break;
		}
	}
	return return_val;
}
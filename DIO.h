/*
 * DIO.h
 *
 * Created: 30/12/2023 08:37:39 م
 *  Author: AMR MOSTAFA
 */ 


#ifndef DIO_H_
#define DIO_H_
void  DIO_SET_PIN_DIRECTION (unsigned char portname , unsigned char pinnumber , unsigned char dieaction ); 
void  DIO_WRITE  (unsigned char portname , unsigned char pinnumber , unsigned char outputvalue );
unsigned char  DIO_READ (unsigned char portname , unsigned char pinnumber  );
void  DIO_TOGGLE (unsigned char portname , unsigned char pinnumber );
void DIO_SET_PORT_DIRECTION (unsigned char portname , unsigned char direction ) ;
unsigned char  DIO_PORT_READ (unsigned char portname );  
void DIO_PORT_TOGGLE (unsigned char portname);
void DIO_PORT_WRITE(unsigned char portname , unsigned char outputval);
void  dio_internal_pull_up_res_intialize(unsigned char portname, unsigned char pinnumber);
void dio_set_high_nibble_direction(unsigned char portname,unsigned direction);
void dio_set_low_nibble_direction(unsigned char portname,unsigned direction);
void dio_write_high_nibble(unsigned char portname, unsigned char value );
void dio_write_low_nibble(unsigned char portname, unsigned char value );





#endif /* DIO_H_ */
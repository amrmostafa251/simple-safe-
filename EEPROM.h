/*
 * EEPROM.h
 *
 * Created: 14/01/2024 10:52:01 ص
 *  Author: AMR MOSTAFA
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

void eeprom_write(unsigned short address , unsigned char data );
unsigned char eeprom_read (const unsigned short address );



#endif /* EEPROM_H_ */
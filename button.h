/*
 * button.h
 *
 * Created: 31/12/2023 08:39:50 م
 *  Author: AMR MOSTAFA
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

void button_initialize(unsigned char portname, unsigned char pinnumber );
 unsigned char button_read (unsigned char portname, unsigned char pinnumber );
 void button_pull_up_res(unsigned char portname, unsigned char pinnumber );
#endif /* BUTTON_H_ */
/*
 * seven_segment_init.c
 *
 *  Created on: Oct 22, 2020
 *      Author: MRM
 */


#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "STD_MACROS.h"

void seven_segment_init()
{
	DDRC = 0x0f;  // setting the first 4 pins in port C as output pins
	DDRA = 0x3f;  // setting the first 6 ins in port A as output pins
	PORTC = 0x00; // out a zero value on all the seven segments at first
	PORTA = 0xff; // enable all the seven segments at first
}



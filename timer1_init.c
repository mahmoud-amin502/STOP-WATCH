/*
 * timer1_init.c
 *
 *  Created on: Oct 22, 2020
 *      Author: MRM
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "STD_MACROS.h"

void timer1_init()
{
	SET_PIN(SREG,7);  // setting the I bit in the SREG to enable all interrupts
	TCNT1 = 0;        // setting initial value zero to the TCNT1 register

	TCCR1B = (1<<WGM12) | (1<<CS10) | (1<<CS12);  // enabling the CTC mode in timer1
	                                              // setting both CS10 and CS12 to make the pre-scaler 1024 on the CTC mode


	SET_PIN(TIMSK,OCIE1A);  //enabling the interrupt on compare match with the value assigned to the OCR1A
	OCR1A = 1000;

}

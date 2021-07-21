/*
 * buttons_init.c
 *
 *  Created on: Oct 22, 2020
 *      Author: MRM
 */


#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "STD_MACROS.h"

void buttons_init()
{

	CLR_PIN(DDRD,PD2); //setting PD2 as input pins
	CLR_PIN(DDRD,PD3); //setting PD3 as input pins
	CLR_PIN(DDRB,PB3); //setting PB2 as input pins

	SET_PIN(PORTD,PD2); //to enable internal pull up on the PD2 pin
	SET_PIN(PORTB,PB2); //to enable internal pull up on the PB2 pin

	SET_PIN(GICR,INT0); // enable the interrupt of external INT0 (module interrupt)
	SET_PIN(MCUCR,ISC01); // make it give an interrupt when detecting a falling edge

	SET_PIN(GICR,INT1);     //enable the interrupt of external INT0 (module interrupt)
	SET_PIN(MCUCR,ISC01);   // make it give an interrupt when detecting a falling edge
	SET_PIN(MCUCR,ISC11);

	SET_PIN(GICR,INT2); // enable the interrupt of external INT0 (module interrupt)
	CLR_PIN(MCUCSR,ISC2); // make it give an interrupt when detecting a falling edge

}

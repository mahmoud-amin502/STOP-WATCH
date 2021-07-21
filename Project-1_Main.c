/*
 * Project-1.c
 *
 *  Created on: Oct 17, 2020
 *      Author: MRM
 */


#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>


//including all .h files
#include "STD_MACROS.h"
#include "buttons_init.h"
#include "GlobalVariables.h"
#include "seven_segment_init.h"
#include "timer1_init.h"


void displaynumbers(); //displaynumbers function prototype


int main()
{

	seven_segment_init(); //calling seven_segment_init
	buttons_init(); //calling buttons_init
	timer1_init(); //calling timer1_init

	while(1)
	{
		displaynumbers(); //calling displaynumbers to display numbers from 0 to 9
	}
}


void displaynumbers()  // function definition of the display number function that start displaying the global variables on the
{        				// seven segment according to the T timer


	PORTA = 0x01;           //enabling the the first seven segment
	PORTC = (num1 & 0x0f);  // writing the num1 value anded with the 0X0F to ensure we have the correct num value
	_delay_ms(2);           // set a very small delay to enable the effect of multiplexing on the 6 seven segments

	PORTA = 0x02;          //enabling the the second seven segment
	PORTC = (num2 & 0x0f); // writing the num2 value anded with the 0X0F to ensure we have the correct num value
	_delay_ms(2);          // set a very small delay to enable the effect of multiplexing on the 6 seven segments

	PORTA = 0x04;          //enabling the the third seven segment
	PORTC = (num3 & 0x0f); // writing the num3 value anded with the 0X0F to ensure we have the correct num value
	_delay_ms(2);          // set a very small delay to enable the effect of multiplexing on the 6 seven segments

	PORTA = 0x08;          //enabling the the fourth seven segment
	PORTC = (num4 & 0x0f); // writing the num4 value anded with the 0X0F to ensure we have the correct num value
	_delay_ms(2);          // set a very small delay to enable the effect of multiplexing on the 6 seven segments

	PORTA = 0x10;          //enabling the the fifth seven segment
	PORTC = (num5 & 0x0f); // writing the num5 value anded with the 0X0F to ensure we have the correct num value
	_delay_ms(2);          // set a very small delay to enable the effect of multiplexing on the 6 seven segments

	PORTA = 0x20;          //enabling the the sixth seven segment
	PORTC = (num6 & 0x0f); // writing the num6 value anded with the 0X0F to ensure we have the correct num value
	_delay_ms(2);          // set a very small delay to enable the effect of multiplexing on the 6 seven segments

}




ISR(INT0_vect) // ISR for resetting button detecting Falling edge using the internal pull up on External INT0
{
	num1 = 0;
	num2 = 0;
	num3 = 0;
	num4 = 0;    // setting all global variables to zero
	num5 = 0;
	num6 = 0;
}




ISR(INT1_vect) // ISR for Pausing button detecting raising edge using the external pull down on External_INT1
{
	TCNT1 = temp;    //setting the TCNT0 to the global temp variable so we can resume from this value
	CLR_PIN(TCCR1B,CS10);   //writing zero to CS01 and CS12 to stop the timer 1 counting
	CLR_PIN(TCCR1B,CS12);
}




ISR(INT2_vect) // ISR for Resuming button detecting falling edge using the external pull up on External_INT2
{
	TCNT1 = temp; ////setting the TCNT0 to the global variable temp
	SET_PIN(TCCR1B,CS10);
	SET_PIN(TCCR1B,CS12);   // re-enabling the timer 1 to count again from the temp valuer
}


ISR(TIMER1_COMPA_vect) //ISR of timer 1 to increment the global numbers
{
	num1 ++; // incrementing num1 until it reaches 10 then we make it equal to zero and starts to increment num2 and
	if(num1 == 10)  // this goes on with all variables from num3 to num6
	{
		num1 =0;
		num2++;
		if(num2 == 10)
		{
			num2 =0;
			num3 ++;
			if(num3 == 10)
			{
				num3=0;
				num4++;
				if(num4 == 10)
				{
					num4 =0;
					num5++;
					if(num5 == 10)
					{
						num5 =0;
						num6 ++;
						if(num6 == 10)
						{
							num6=0;
						}
					}
				}
			}
		}
	}
}




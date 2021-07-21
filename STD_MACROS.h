/*
 * STD_MACROS.h
 *
 *  Created on: Oct 22, 2020
 *      Author: MRM
 */

#ifndef STD_MACROS_H_
#define STD_MACROS_H_


#define REG_SIZE 8

#define SET_PIN(reg,pin) reg|=(1<<pin)
#define CLR_PIN(reg,pin) reg &=(~(1<<pin))
#define TOG_PIN(reg,pin) reg^=(1<<pin)
#define READ_PIN(reg,pin) ((reg&(1<<pin))>>pin)

#define IS_PIN_SET(reg,pin) ((reg&(1<<pin))>>pin)
#define IS_PIN_CLR(reg,pin) (!(reg&(1<<pin))>>pin)

#define ROR (reg,num) reg=((reg<<(REG_SIZE - num))|(reg>>num))
#define ROL (reg,num) reg=((reg>>(REG_SIZE - num))|(reg<<num))




#endif /* STD_MACROS_H_ */

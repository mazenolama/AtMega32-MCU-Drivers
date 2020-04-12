/*
 * Servo.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mr.M.O
 */


#include "../../LIB/STDTYPES.h"
#include "../../MCAL/DIO/DIO_Reg.h"
#include "../../LIB/Bit_Math.h"
#include "Servo.h"

void Servo_init()
{
	//DDRD |= (1<<PD5);	/* Make OC1A pin as output */
	SET_BIT(DDRD_REG,5);
	TCNT1 = 0;	     	/* Set timer1 count zero */
	ICR1 = 3749;		/* Set TOP count for timer1 in ICR1 register */
   //ICR1 = 4999;

	/* Set Fast PWM, TOP in ICR1, Clear OC1A on compare match, clk/64 */

	//TCCR1A = (1<<WGM11)|(1<<COM1A1);
	SET_BIT(TCCR1A,1);// BIT - WGM11
	SET_BIT(TCCR1A,7);// BIT - COM1A1

	//TCCR1B = (1<<WGM12)|(1<<WGM13)|(1<<CS10)|(1<<CS11);
	SET_BIT(TCCR1B,3);// BIT - WGM12
	SET_BIT(TCCR1B,4);// BIT - WGM1
	SET_BIT(TCCR1B,0);// BIT - CS10
	SET_BIT(TCCR1B,1);// BIT - CS11
}

	/* 64.5 --> 180   , 175 --> 90 , 308 --> 0 */



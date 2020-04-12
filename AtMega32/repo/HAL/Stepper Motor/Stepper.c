/*
 * Stepper.c


 *
 *  Created on: ??þ/??þ/????
 *      Author: Mr.M.O
 */


#include "../../LIB/STDTYPES.h"
#include <util/delay.h>
#include <avr/io.h>
#include "../../LIB/Bit_Math.h"
#include"Stepper.h"

void Stepper(void)
{
	// PORT D as output
	DDRD = 0xff;
	u8 i;

	while (1)
	{
		// Rotate clock wise for 5 seconds
		for (i=0;i<250;i++)
			{
			Stepper_RotateCW();
			}

		 //Rotate anti clock wise for 5 seconds
		/*for (i=0;i<250;i++)
		{
			Stepper_RotateACW();
		}*/


	}

}


void Stepper_RotateCW(void)
{
	SET_BIT(PORTD,Coil_Blue);
	CLR_BIT(PORTD,Coil_Pink);
	CLR_BIT(PORTD,Coil_Yellow);
	CLR_BIT(PORTD,Coil_Orange);
	_delay_ms(5);

	CLR_BIT(PORTD,Coil_Blue);
	SET_BIT(PORTD,Coil_Pink);
	CLR_BIT(PORTD,Coil_Yellow);
	CLR_BIT(PORTD,Coil_Orange);
	_delay_ms(5);

	CLR_BIT(PORTD,Coil_Blue);
	CLR_BIT(PORTD,Coil_Pink);
	SET_BIT(PORTD,Coil_Yellow);
	CLR_BIT(PORTD,Coil_Orange);
	_delay_ms(5);

	CLR_BIT(PORTD,Coil_Blue);
	CLR_BIT(PORTD,Coil_Pink);
	CLR_BIT(PORTD,Coil_Yellow);
	SET_BIT(PORTD,Coil_Orange);
	_delay_ms(5);
}

void Stepper_RotateACW(void)
{

	CLR_BIT(PORTD,Coil_Blue);
	CLR_BIT(PORTD,Coil_Pink);
	CLR_BIT(PORTD,Coil_Yellow);
	SET_BIT(PORTD,Coil_Orange);
	_delay_ms(5);

	CLR_BIT(PORTD,Coil_Blue);
	CLR_BIT(PORTD,Coil_Pink);
	SET_BIT(PORTD,Coil_Yellow);
	CLR_BIT(PORTD,Coil_Orange);
	_delay_ms(5);

	CLR_BIT(PORTD,Coil_Blue);
	SET_BIT(PORTD,Coil_Pink);
	CLR_BIT(PORTD,Coil_Yellow);
	CLR_BIT(PORTD,Coil_Orange);
	_delay_ms(5);

	SET_BIT(PORTD,Coil_Blue);
	CLR_BIT(PORTD,Coil_Pink);
	CLR_BIT(PORTD,Coil_Yellow);
	CLR_BIT(PORTD,Coil_Orange);
	_delay_ms(5);
}



/*
 * PUSH.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mr.M.O
 */


#include "../MCAL/DIO/DIO_types.h"
#include "../MCAL/DIO/DIO.h"
#include <util/delay.h>

void push(){

	DIO_SetPinDirection(PORTC , PIN0 , INPUT);
	DIO_SetPinDirection(PORTD , PIN0 , OUTPUT);


	while(1)
	{
		DIO_SetPinValue(PORTD , PIN0 ,LOW);
		DIO_SetPinValue(PORTC , PIN0 ,LOW);
		if(DIO_GetPinValue(PORTC , PIN0 )==HIGH)
		{
			DIO_SetPinValue(PORTD , PIN0 ,LOW);
		}

		else if(DIO_GetPinValue(PORTC , PIN0 )==LOW)
		{
			DIO_SetPinValue(PORTD , PIN0 ,HIGH);

		}
		DIO_SetPinValue(PORTD , PIN0 ,HIGH);

	}

}


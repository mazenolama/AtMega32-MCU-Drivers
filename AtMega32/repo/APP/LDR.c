/*
 * LDR.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mr.M.O
 */
#include "../MCAL/DIO/DIO_types.h"
#include "../MCAL/DIO/DIO.h"
#include "../MCAL/ADC/ADC.h"
#include <util/delay.h>


void LDR(void)
{
	ADC_Init();
	_delay_ms(50);
	int Res;
	DIO_SetPortDirection(PORTC,OUTPUT);
	while(1)
	{
		Res =ADC_Read(0);
		if(Res < 950)
			DIO_SetPortValue(PORTC,HIGH);
		else
			DIO_SetPortValue(PORTC,LOW);
	}
}

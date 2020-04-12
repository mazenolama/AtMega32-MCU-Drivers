/*
 * Temp.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mr.M.O
 */


#include "../../LIB/STDTYPES.h"
#include "../../MCAL/ADC/ADC.h"
#include "../../MCAL/DIO/DIO_types.h"
#include "../../MCAL/DIO/DIO.h"
#include "../../HAL/LCD/LCD.h"
#include "../../MCAL/LOG/LOG.h"
#include <util/delay.h>

void Temp(void)
{
	u16 Result=0;
	u8 temp;
	DIO_SetPortDirection(PORTB,OUTPUT);
	LCD_Initialize();
	ADC_Init();
	//DIO_SetPortDirection(PORTC,OUTPUT); // LED

	LCD_WriteCmd(lcd_Clear);// Home LCD
	LCD_WriteCmd(0x0C); // fixd pos of value on LCD
	LCD_WriteString(" Temp = ", 0,0);
	while(1)
	{
		Result = ADC_Read(0);
		Result /=5; // temp
		//Result /=5; // variable resistant
		LCD_GotoXY(0,8);
		LCD_IntegerToString(Result);

		_delay_ms(500);

		if(Result>15)
		{
			DIO_SetPinValue(PORTC,PIN0,HIGH);
		}
		else
		{
			DIO_SetPinValue(PORTC,PIN0,LOW);
		}

	}
}



/*
 * LOG.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mr.M.O
 */

#include "../../HAL/LCD/LCD.h"
#include "../../LIB/STDTYPES.h"
void Log_Print_String(u8 str[]){
	while(*str != '\0')
		{
			LCD_WriteChar(*str);
			str++;
		}
}
void Log_Print_Number(u16 num)
{
	u8 Temp;

	if (num >= (u16)10000)
	{
		Temp = (u8)(num / (u16) 10000);
		LCD_WriteChar(Temp+48);
		num = num - (u16)(Temp * (u16)10000);

		Temp = (u8)(num / (u16) 1000);
		LCD_WriteChar(Temp+48);
		num = num - (u16)(Temp * (u16)1000);

		Temp = (u8)(num / (u16) 100);
		LCD_WriteChar(Temp+48);
		num = num - (u16)(Temp * (u8)100);

		Temp = (u8)(num / (u16) 10);
		LCD_WriteChar(Temp+48);
		Temp = num - (u16)(Temp * (u8)10);
		LCD_WriteChar(Temp+48);

	}

	else if (num >= (u16) 1000 )
	{
		Temp = (u8)(num / (u16) 1000);
		LCD_WriteChar(Temp+48);
		num = num - (u16)(Temp * (u16)1000);

		Temp = (u8)(num / (u16) 100);
		LCD_WriteChar(Temp+48);
		num = num - (u16)(Temp * (u8)100);

		Temp = (u8)(num / (u16) 10);
		LCD_WriteChar(Temp+48);
		Temp = num - (u16)(Temp * (u8)10);
		LCD_WriteChar(Temp+48);
	}

	else if (num >= (u8)100 )
	{
		Temp = (u8)(num / (u16) 100);
		LCD_WriteChar(Temp+48);
		num = num - (u16)(Temp * (u8)100);

		Temp = (u8)(num / (u16) 10);
		LCD_WriteChar(Temp+48);
		Temp = num - (u16)(Temp * (u8)10);
		LCD_WriteChar(Temp+48);
	}

	else if (num >= (u8) 10 )
	{
		Temp = (u8)((u8)num / (u8) 10);
		LCD_WriteChar(Temp+48);
		Temp = num - (u16)(Temp * (u8)10);
		LCD_WriteChar(Temp+48);
	}

	else
	{
		LCD_WriteChar(num+48);
	}
}

/*
 * LCD.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mr.M.O
 */
#include <util/delay.h>
#include "../HAL/LCD/LCD.h"

void LCD_LAP()
{
	LCD_Initialize();
	 //LCD_WriteString("MAZEN" ,0, 5); // 1st line & column 14
	LCD_GotoXY(1,6);
     LCD_WriteString("MAZEN", 1 , 6);

}

/*
 * LCD.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mr.M.O
 */

#ifndef REPO_HAL_LCD_LCD_H_
#define REPO_HAL_LCD_LCD_H_
#include "../../LIB/STDTYPES.h"

#define lcd_Clear           0x01          /* replace all characters with ASCII 'space'                       */
#define lcd_Home            0x02          /* return cursor to first position on first line                   */
#define lcd_EntryMode       0x06          // shift cursor from left to right on read/write
#define lcd_DisplayOff      0x08          // turn display off
#define lcd_DisplayOn       0x0C          // display on, cursor off, don't blink character
#define lcd_FunctionReset   0x30          // reset the LCD
#define lcd_FunctionSet8bit 0x38          // 8-bit data, 2-line display, 5 x 7 font
#define lcd_SetCursor       0x80          // set cursor position

void LCD_Initialize(void);
void LCD_WriteCmd(u8 Cmd);
void LCD_WriteChar(u8 Data);
void LCD_WriteString(u8* Data , u8 X , u8 Y);
void LCD_GotoXY(u8 X , u8 Y );
void LCD_IntegerToString(u16 data);
void LCD_SendString(u8 *str);


#endif /* REPO_HAL_LCD_LCD_H_ */

/*
 * LCD.c

 *
 *  Created on: ??þ/??þ/????
 *      Author: Mr.M.O
 */
#include <util/delay.h>
#include "../../LIB/STDTYPES.h"
#include "../../MCAL/DIO/DIO_REG.h"
#include "../../MCAL/DIO/DIO_types.h"
#include "../../MCAL/DIO/DIO.h"
#include "../../LIB/Bit_Math.h"



static u8 InitStepFinish =0;
void LCD_Initialize() // 4-bit mode
{

	//DIO_SetPORTBirection(PORTB, OUTPUT); //Data Pins
	// Contorl Pins
	_delay_ms(30);
	LCD_WriteCmd(0x20); // 0010 0000
	LCD_WriteCmd(0x20);
	LCD_WriteCmd(0x80); //10-- ---- : --> 0x80
	_delay_ms(1);
	LCD_WriteCmd(0x00);
	//Cursor elmoa'asher
	LCD_WriteCmd(0xf0); // 1111 0000
	_delay_ms(1);
	LCD_WriteCmd(0x00);
	LCD_WriteCmd(0x10);
	_delay_ms(2);
	LCD_WriteCmd(0x00);
	LCD_WriteCmd(0x60); //0110 0000

	InitStepFinish =1; // 3shan akhaleh yb3at el 4 bit eltanyn
}


void LCD_WriteCmd(u8 Cmd)
{


	DIO_SetPinValue(PORTB, PIN1 , LOW);// RS = 0
	DIO_SetPinValue(PORTB, PIN2 , LOW);// RW= 0


	DIO_SetPinValue(PORTB, PIN4 , GET_BIT(Cmd,4)); //DB4
	DIO_SetPinValue(PORTB, PIN5 , GET_BIT(Cmd,5)); //DB5
	DIO_SetPinValue(PORTB, PIN6 , GET_BIT(Cmd,6)); //DB6
	DIO_SetPinValue(PORTB, PIN7 , GET_BIT(Cmd,7)); //DB7
    //  Sent 1st 4 bit
	// PIN E READ ALLINH EDGE ( H , H-->L)
	DIO_SetPinValue(PORTB, PIN3 ,HIGH); // PIN E

	_delay_ms(1);

	DIO_SetPinValue(PORTB, PIN3 ,LOW);
	// 0 -- > false  not happen

	// awl lama ykhlas el init. func el7ta de hattshtaghl ma3aya
	if (InitStepFinish  )
	{
		DIO_SetPinValue(PORTB, PIN4 , GET_BIT(Cmd,0)); //DB4
		DIO_SetPinValue(PORTB, PIN5 , GET_BIT(Cmd,1)); //DB5
		DIO_SetPinValue(PORTB, PIN6 , GET_BIT(Cmd,2)); //DB6
		DIO_SetPinValue(PORTB, PIN7 , GET_BIT(Cmd,3)); //DB7
		// Sent 2nd 4 bit
		DIO_SetPinValue(PORTB, PIN3 ,HIGH); // PIN E

		_delay_ms(1);

		DIO_SetPinValue(PORTB, PIN3 ,LOW);
	}
	_delay_ms(2);
}

void LCD_WriteChar(u8 Data)
{
	DIO_SetPinValue(PORTB, PIN1 , HIGH); // RS
	DIO_SetPinValue(PORTB, PIN2 , LOW); // RW
	// Send 1st 4 bit (UPPER OREDER)

	DIO_SetPinValue(PORTB, PIN4 ,GET_BIT(Data , 4));
	DIO_SetPinValue(PORTB, PIN5 , GET_BIT(Data , 5));
	DIO_SetPinValue(PORTB, PIN6 , GET_BIT(Data , 6));
	DIO_SetPinValue(PORTB, PIN7 , GET_BIT(Data , 7));

	 //PIN E READ ALLINH EDGE ( H , H-->L)
	DIO_SetPinValue(PORTB, PIN3 ,HIGH); // PIN E

	_delay_ms(1);

	DIO_SetPinValue(PORTB, PIN3 ,LOW);
	// 0 -- > false  not happen

	 //Send 2nd 4 bit (LOWER OREDER)

	DIO_SetPinValue(PORTB, PIN4 , GET_BIT(Data , 0));
	DIO_SetPinValue(PORTB, PIN5 , GET_BIT(Data , 1));
	DIO_SetPinValue(PORTB, PIN6 , GET_BIT(Data , 2));
	DIO_SetPinValue(PORTB, PIN7 , GET_BIT(Data , 3));

	 //PIN E READ ALLINH EDGE ( H , H-->L)
	DIO_SetPinValue(PORTB, PIN3 ,HIGH); // PIN E

	_delay_ms(1);

	DIO_SetPinValue(PORTB, PIN3 ,LOW);
	// 0 -- > false  not happen
	_delay_ms(2);

}

void LCD_WriteString(u8* Data, u8 X , u8 Y )
{
	LCD_GotoXY(X ,Y);
	u8 index =0 ;
	u8 line0 =0 ; // b7aded beh lw ana katbt fe 1st column fe el 2nd line

	while(Data[index]  != '\0' && ((X *16) + (index + Y)) < 32 )  //  \0 -- > null & ba7seb ba2y kam char 3ala akher elshasha w weslt le akher eLCD wla La2
	{
		if ( ((X *16) + (index + Y)) < 16 ) // first line
		{
			LCD_WriteChar(Data[index]);
			index++;
		}
		else if (((X *16) + (index + Y)) == 16 && line0 == 0 )
		{
			LCD_GotoXY(1, 0); // second line
			line0++;

		}
		else if(((X *16) + (index + Y)) < 32 && line0 ==1)
		{
			LCD_WriteChar(Data[index]);
			index++;
		}
	}
}

void LCD_GotoXY(u8 X , u8 Y )
{
	u8 Address ;
	if (X < 2  && Y <16 )
	{
		Address = (X * 0x40) + Y; // Address = 0x00 or 0x40 + new Y (column)
		Address = SET_BIT(Address ,7); // SET DB7 --> 1
		LCD_WriteCmd(Address);
	}/*
	if (X>0 && X<=16)
		{
		    switch(Y)
		    {
			    case 1: LCD_WriteCmd(X+127);
			    break;
			    case 2: LCD_WriteCmd(X+191);
			    break;
			    default:
			    	break;
		    }
		}*/
}
void LCD_IntegerToString(u16 data)
{
	u8 BUFF[16];
	itoa(data,BUFF,10);
	LCD_SendString(BUFF);
	//return BUFF;
}
void LCD_SendString(u8 *str)
{
	while(*str != '\0')
	{
		LCD_WriteChar(*str);
		str++;
	}
}

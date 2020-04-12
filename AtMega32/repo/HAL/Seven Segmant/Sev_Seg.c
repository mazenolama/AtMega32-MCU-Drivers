/*
 * Sev_Seg.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mr.M.O
 */
#include "../../MCAL/DIO/Bit_Math.h"
#include "../../MCAL/DIO/DIO_types.h"
#include "../../MCAL/DIO/DIO.h"


void SS_Init()
{
 DIO_SetPortDirection(PORTA,OUTPUT);
}
void SS_Write_Num(unsigned char Num)
{
     	//          7 6 5 4 3 2 1 0
		// 5 --> 0b 0 0 0 0 0 1 0 1
		//            G F E D C B A
		Num =~ Num;
		DIO_SetPinValue(PORTA, PIN0,GET_BIT(Num , 0)); //A
		DIO_SetPinValue(PORTA, PIN1,GET_BIT(Num , 1)); //B
		DIO_SetPinValue(PORTA, PIN2,GET_BIT(Num , 2)); //C
		DIO_SetPinValue(PORTA, PIN3,GET_BIT(Num , 3)); //D
		DIO_SetPinValue(PORTA, PIN4,GET_BIT(Num , 4)); //E
		DIO_SetPinValue(PORTA, PIN5,GET_BIT(Num , 5)); //F
		DIO_SetPinValue(PORTA, PIN6,GET_BIT(Num , 6)); //G
}



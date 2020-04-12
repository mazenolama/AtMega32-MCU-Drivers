/*
 * KeyPadLCD.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mr.M.O
 */

/*
#include "../HAL/LCD/LCD.h"
#include "../HAL/KeyPad/KeyPad.h"
#include "../MCAL/ADC/ADC.h"
#include "../MCAL/DIO/DIO_types.h"    // change pathes
#include "../MCAL/DIO/DIO.h"
#include "../MCAL/LOG/LOG.h"
#include "../MCAL/UART/UART.h"
#include "../LIB/STDTYPES.h"
#include "../LIB/Bit_Math.h"
#include <util/delay.h>

void Smart_Home()
{
	//SET Directions of ports
		DIO_SetPinDirection(PORTC,PIN2,OUTPUT); // LED1
		DIO_SetPinDirection(PORTC,PIN3,OUTPUT); // LED2
		DIO_SetPinDirection(PORTC,PIN4,OUTPUT); // LED3
		DIO_SetPinDirection(PORTC,PIN5,OUTPUT); // LED4
		DIO_SetPortDirection(PORTB, OUTPUT); //Data Pins D4 --> D7(LCD) DB4 --> DB7 (4 bit mode)
											// Contorl Pins D1,D2,D3 --> RS, RW, E (LCD)
		DIO_SetPinDirection(PORTD, PIN0,INPUT); // Rx enable
		DIO_SetPinDirection(PORTD, PIN1,OUTPUT); // Tx enable
	//Initialize LCD & ADC & UART
	LCD_Initialize();
	ADC_Init();
	//USART_Init();

	//Initialize some Variables
	u8 ID ; u8 Pass;u8 tries=3 ;u8 Temp =0; u8 chooseLed =0; u8 out=1;

	//Print Intro on LCD
	LCD_WriteString(" Welcome " , 0, 5);
	_delay_ms(2000);
	LCD_WriteCmd(0x01);  // Clear LCD after 3 sec
	LCD_WriteString(" ID : " , 0 , 1);
	ID = KeyPad_GetPress();
	LCD_WriteChar(ID);
	_delay_ms(1000);
	if(KeyPad_GetPress() != '1')
		LCD_WriteString(" Invalid ID " , 0 ,1);
	LCD_WriteCmd(0x01);
	LCD_WriteString(" Pass = " ,0, 1);
	Pass = KeyPad_GetPress();
	LCD_WriteChar(Pass);
	_delay_ms(1000);
	LCD_WriteCmd(0x01);
	if(Pass != 1)
	{
		while(tries>0)
		{
		LCD_WriteString(" Invalid Password ",1,1);
		_delay_ms(2000);
		LCD_WriteCmd(0x01);
		LCD_WriteString(" Tries left = " ,1,1);
		_delay_ms(2000);
		LCD_WriteCmd(0x01);
		tries--;
		}
	}
	LCD_WriteCmd(0x01);
	LCD_WriteString(" Welcome Mazen " ,1,1);
	_delay_ms(4000);
	LCD_WriteCmd(0x01);
	DIO_SetPinValue(PORTC, PIN1,HIGH); // Opening the door by moving arm of linear motion motor
	LCD_WriteString(" DOOR IS OPENED " ,1,1);
	_delay_ms(4000);
	LCD_WriteCmd(0x01);
	LCD_WriteCmd(0x0C); // fixd pos of value on LCD
	while(1)
		{
			Temp = ADC_Read(0);
			Temp /=5;
			LCD_GotoXY(0,8);
			Log_Print_Number(Temp);
			_delay_ms(1500);
			if(Temp>20)
			{
				DIO_SetPinValue(PORTC,PIN0,HIGH);// Turn on Fan
			}
			else
			{
				DIO_SetPinValue(PORTC,PIN0,LOW);
			}
			LCD_WriteString(" Press 0 to retun to home",2,1);
			out =USART_ReceiveChar();;
			if(out== 0)
				break;
		}
	LCD_WriteString(" Select No. of LEDs to turn on " , 1, 0);
	LCD_WriteString("1,2,3,4 " , 2 ,1);
	chooseLed= USART_ReceiveChar();;
	while(chooseLed!=0)
		{
			switch(chooseLed)
			{
				case 1: DIO_SetPinValue(PORTC,PIN2,HIGH);
						break;
				case 2: DIO_SetPinValue(PORTC,PIN2,HIGH);
						DIO_SetPinValue(PORTC,PIN3,HIGH);
						break;
				case 3: DIO_SetPinValue(PORTC,PIN2,HIGH);
						DIO_SetPinValue(PORTC,PIN3,HIGH);
						DIO_SetPinValue(PORTC,PIN4,HIGH);
						break;
				case 4: DIO_SetPinValue(PORTC,PIN2,HIGH);
						DIO_SetPinValue(PORTC,PIN3,HIGH);
						DIO_SetPinValue(PORTC,PIN4,HIGH);
						DIO_SetPinValue(PORTC,PIN5,HIGH);
						break;
			}
		}

}
*/

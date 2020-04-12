/*
 * KeyPad.c
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
#define KEY_PRT 	PORTA_REG
#define KEY_DDR		DDRA_REG
#define KEY_PIN		PINA_REG



u8 keypad[4][4] = {
				{'1','2','3','/'},
				{'4','5','6','*'},
				{'7','8','9','-'},
				{'#','0','=','+'}
	};

unsigned char Col, Row;

u8 KeyPad_GetPress(void){
{
	while(1)
	{
	    KEY_DDR = 0xF0;           /* set port direction as input-output */
	    KEY_PRT = 0xFF;

	    do
	    {
		KEY_PRT &= 0x0F;      /* mask PORT for column read only */
		asm("NOP");
		Col = (KEY_PIN & 0x0F); /* read status of column */
	 }
	    while(Col != 0x0F);
	    do
	    {
	    	do
	    	{
	            _delay_ms(20);             /* 20ms key debounce time */
		        Col = (KEY_PIN & 0x0F); /* read status of column */
	     	}
	     while(Col == 0x0F);        /* check for any key press */

		 _delay_ms (40);	            /* 20 ms key debounce time */
		 Col = (KEY_PIN & 0x0F);
	    }while(Col == 0x0F);

	   /* now check for rows */
	    KEY_PRT = 0xEF;            /* check for pressed key in 1st row */
	    asm("NOP");
	    Col = (KEY_PIN & 0x0F);
	    if(Col != 0x0F)
            {
		Row = 0;
		break;
	    }

	    KEY_PRT = 0xDF;		/* check for pressed key in 2nd row */
	    asm("NOP");
	    Col = (KEY_PIN & 0x0F);
	    if(Col != 0x0F)
	    {
		Row = 1;
		break;
	    }

	    KEY_PRT = 0xBF;		/* check for pressed key in 3rd row */
	    asm("NOP");
            Col = (KEY_PIN & 0x0F);
	    if(Col != 0x0F)
	    {
		Row = 2;
		break;
	    }

	    KEY_PRT = 0x7F;		/* check for pressed key in 4th row */
	    asm("NOP");
	    Col = (KEY_PIN & 0x0F);
	    if(Col != 0x0F)
	    {
		Row = 3;
		break;
	    }
	}

	if(Col == 0x0E)
	   return(keypad[Row][0]);
	else if(Col == 0x0D)
	   return(keypad[Row][1]);
	else if(Col == 0x0B)
	   return(keypad[Row][2]);
	else
	   return(keypad[Row][3]);
}
}

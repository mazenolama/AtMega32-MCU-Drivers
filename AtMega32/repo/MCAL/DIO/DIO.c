/*
 * DIO.c
 *
 *  Created on: 2020/1/26
 *      Author: Mr.Mazen Olama 
 */
#include "../../LIB/STDTYPES.h"
#include "../../LIB/Bit_Math.h"
#include "DIO_REG.h"
#include "DIO_types.h"



void DIO_SetPortDirection(u8 Port_id, u8 Dir)
{
	if (OUTPUT== Dir)
	{
		switch(Port_id)
		{
			case PORTA: DDRA_REG = 0xFF; ; break ;
			case PORTB: DDRB_REG  = 0xFF; ; break ;
			case PORTC: DDRC_REG  = 0xFF; ; break ;
			case PORTD: DDRD_REG  = 0xFF; ; break ;
		}
	}
	else if (INPUT == Dir)
	{
		switch(Port_id)
				{
					case PORTA: DDRA_REG  = 0x00; ; break ;
					case PORTB: DDRB_REG  = 0x00; ; break ;
					case PORTC: DDRC_REG  = 0x00; ; break ;
					case PORTD: DDRD_REG  = 0x00; ; break ;
				}
	}

}

void DIO_SetPortValue(u8 Port_ID , u8 value)
{
	switch(Port_ID)
	{
		case PORTA : PORTA_REG =value; break;
		case PORTB : PORTB_REG =value; break;
		case PORTC : PORTC_REG =value; break;
		case PORTD : PORTD_REG =value; break;
	}
}

void DIO_SetPinDirection(u8 Port_id , u8 Pin_ID , u8 Dir)
{
	if ((Port_id <= PORTD) && (Pin_ID <= PIN7))
	{
		if (Dir == OUTPUT)
		{
			switch (Port_id)
			{
				case PORTA: SET_BIT(DDRA_REG, Pin_ID) ; break;
				case PORTB: SET_BIT(DDRA_REG, Pin_ID) ; break;
				case PORTC: SET_BIT(DDRA_REG, Pin_ID) ; break;
				case PORTD: SET_BIT(DDRA_REG, Pin_ID) ; break;
			} 
		}
	}
	else if (Dir == INPUT)
	{
		switch(Port_id)
		{
			case PORTA: CLR_BIT(DDRA_REG, Pin_ID); break;
			case PORTB: CLR_BIT(DDRA_REG, Pin_ID); break;
			case PORTC: CLR_BIT(DDRA_REG, Pin_ID); break;
			case PORTD: CLR_BIT(DDRA_REG, Pin_ID); break;
		}
	}
}

void DIO_SetPinValue(u8 Port_ID, u8 Pin_ID  , u8 value)
{
	/* Make sure that the Port ID and Pin ID are in the valid range */
	if ((Port_ID <= PORTD) && (Pin_ID <= PIN7))
	{
		if (value == HIGH)
		{
			/* Check on the Required PORT Number */
			switch (Port_ID)
			{
				case PORTA: SET_BIT(PORTA_REG,Pin_ID); break;
				case PORTB: SET_BIT(PORTB_REG,Pin_ID); break;
				case PORTC: SET_BIT(PORTC_REG,Pin_ID); break;
				case PORTD: SET_BIT(PORTD_REG,Pin_ID); break;
			}

		}

		else if (value == LOW)
		{
			/* Check on the Required PORT Number */
			switch (Port_ID)
			{
				case PORTA: CLR_BIT(PORTA_REG,Pin_ID); break;
				case PORTB: CLR_BIT(PORTB_REG,Pin_ID); break;
				case PORTC: CLR_BIT(PORTC_REG,Pin_ID); break;
				case PORTD: CLR_BIT(PORTD_REG,Pin_ID); break;
			}
		}

		else
		{
			/* Do nothing, Wrong value to set */
		}
	}

	else
	{
		/* Do nothing, Error in the Pin ID or PORT ID */
	}

}

u8 DIO_GetPinValue(u8 Port_ID, u8 Pin_ID  )
{
	/* Define Local Variable to get the BIT Value */
		u8 Result =0;
		/* Make sure that the Port ID and Pin ID are in the valid range */
		if ((Port_ID <= PORTD) && (Pin_ID <= PIN7))
		{
			/* Check on the Required PORT Number */
			switch (Port_ID)
			{
				case PORTA: Result= GET_BIT(PINA_REG,Pin_ID); break;
				case PORTB: Result= GET_BIT(PINB_REG,Pin_ID); break;
				case PORTC: Result= GET_BIT(PINC_REG,Pin_ID); break;
				case PORTD: Result= GET_BIT(PIND_REG,Pin_ID); break;
			}
		}
		return Result;

/******************************************************************************/
		/*
		u8 Result ;
		if ((Port_ID <= PORTD) && (Pin_ID <= PIN7))
		{
			switch (Port_ID)
			{
				case PORTA: Result = GET_BIT(PINA_REG , Pin_ID) ; break;
				case PORTB: Result = GET_BIT(PINB_REG , Pin_ID) ; break;
				case PORTC: Result = GET_BIT(PINC_REG , Pin_ID) ; break;
				case PORTD: Result = GET_BIT(PIND_REG , Pin_ID) ; break;
			}
		}
		return Result;*/

}


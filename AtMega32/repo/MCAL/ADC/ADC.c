/*
 * ADC.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mr.M.O
 */

#include "../../LIB/STDTYPES.h"
#include "ADC.h"
#include "../../LIB/Bit_Math.h"
//#include <avr/io.h>
//#include <avr/pgmspace.h>

extern void ADC_Init(void)
{
	// ADC Enable
	SET_BIT(ADCSRA,7);

	//Prescaler Configuration as 128
	SET_BIT(ADCSRA,2);
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,0);

	//Select Voltage Ref. to AVCC at AREF pin
	CLR_BIT(ADMUX,7);
	SET_BIT(ADMUX,6);

	// ADC Data Rgith Adjustment
	CLR_BIT(ADMUX,5);
}

extern u16 ADC_Read(u8 ch)
{
	// ADC Channel Selection
	ch=ch&0b00000111;
		ADMUX&=0b11100000;
		ADMUX|=ch;

		// Start Single Convention
		SET_BIT(ADCSRA,6);
	// Start Single Convention
		SET_BIT(ADCSRA,6);

		//wait for the conversion
		while(!(ADCSRA & (1<<4))); //polling on

		//ADC Flag Clear
		SET_BIT(ADCSRA,4);

		return (ADC);
}

/*
u16 ReadADC(u8 ch)
{
	//Select ADC Channel ch must be 0-7
	ch=ch&0b00000111;
	ADMUX&=0b11100000;
	ADMUX|=ch;

	//Start Single conversion
	ADCSRA|=(1<<ADSC);

	//Wait for conversion to complete
	while(!(ADCSRA & (1<<ADIF)));

	//Clear ADIF by writing one to it
	//Note you may be wondering why we have write one to clear it
	//This is standard way of clearing bits in io as said in datasheets.
	//The code writes '1' but it result in setting bit to '0' !!!

	ADCSRA|=(1<<ADIF);

	return(ADC);
}
*/

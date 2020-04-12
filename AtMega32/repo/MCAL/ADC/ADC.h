/*
 * ADC.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mr.M.O
 */

#ifndef REPO_MCAL_ADC_ADC_H_
#define REPO_MCAL_ADC_ADC_H_


#define ADMUX 	*((volatile u8*)0x27) 	// ADC Multiplexer Register
#define ADCSRA 	*((volatile u8*)0x26) 	// ADC Control And Status Register
#define ADCH 	*((volatile u8*)0x25) 		// ADC High Register
#define ADCL 	*((volatile u8*)0x24) 		// ADC Low Register
#define ADC (*(volatile u16 *)((0x04) + 0x20)) // to Return ADCL & ADCH


extern void ADC_Init(void);
extern u16 ADC_Read(u8 channel);
//u16 ReadADC(u8 ch);

#endif /* REPO_MCAL_ADC_ADC_H_ */

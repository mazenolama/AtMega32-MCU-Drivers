/*
 * Bit_Math.h
 *
 * Created: 29/01/2020 02:49:57 PM
 *  Author: Mr.M.O
 */ 
#ifndef REPO_MCAL_DIO_BIT_MATH_H_
#define REPO_MCAL_DIO_BIT_MATH_H_

#define SET_BIT(PORT_ID ,PIN_ID  ) (PORT_ID) |= (1<<(PIN_ID) )
#define CLR_BIT(PORT_ID ,PIN_ID  )  (PORT_ID) &= ~(1<<(PIN_ID) )
#define TOGGLE_BIT(PORT_ID ,PIN_ID  ) (PORT_ID) ^= (1<<(PIN_ID) )
#define GET_BIT(VAR,BITNO) (((VAR) >> (BITNO)) & 0x01) // 0  1

#endif /*REPO_MCAL_DIO_BIT_MATH_H_*/

/*
 * DIO.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mr.M.O
 */

#ifndef REPO_MCAL_DIO_DIO_H_
#define REPO_MCAL_DIO_DIO_H_
#include "../../LIB/STDTYPES.h"

void DIO_SetPortDirection(u8 Port_id,u8 Dir); //direction 1 or 0 (out or in)

void DIO_SetPortValue(u8 Port_ID , u8 value);

void DIO_SetPinDirection(u8 Port_id , u8 Pin_ID , u8 Dir);

void DIO_SetPinValue(u8 Port_ID, u8 Pin_ID  , u8 value);

u8 DIO_GetPinValue(u8 Port_ID, u8 Pin_ID  );


#endif /* REPO_MCAL_DIO_DIO_H_ */

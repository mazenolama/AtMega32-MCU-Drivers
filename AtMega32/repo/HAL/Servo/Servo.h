/*
 * Servo.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mr.M.O
 */

#ifndef REPO_HAL_SERVO_SERVO_H_
#define REPO_HAL_SERVO_SERVO_H_

/* Defines Reg. */
#define OCR1A (*(volatile u16 *)((0x2A) + 0x20))
#define TCNT1 (*(volatile u16 *)((0x2C) + 0x20))
#define ICR1  (*(volatile u16 *)((0x26) + 0x20))
#define TCCR1A *((volatile u8*)0x4F)
#define TCCR1B *((volatile u8*)0x4E)

 /* Funcs Prototypes */
void Servo_init();

/*          angels sets                      */
/*                   internal               */
/* 64.5 --> 180   , 175 --> 90 , 308 --> 0 */



 /*              Micro servo angles external  */
			//OCR1A = 230; angle 90

			//OCR1A =105;  angle 0

		//	//	OCR1A = 316;

			//OCR1A = 320.5;
/*
	OCR1A =105;  //angle 0
	_delay_ms(1500);
	OCR1A = 230; //angle 90
	_delay_ms(1500);*/
	//OCR1A = 250; //angle 180
	//_delay_ms(4000);

#endif /* REPO_HAL_SERVO_SERVO_H_ */

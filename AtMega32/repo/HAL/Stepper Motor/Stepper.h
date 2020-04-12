/*
 * Stepper.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mr.M.O
 */

#ifndef REPO_HAL_STEPPER_MOTOR_STEPPER_H_
#define REPO_HAL_STEPPER_MOTOR_STEPPER_H_

#define Coil_Blue     0
#define Coil_Pink     1
#define Coil_Yellow   2
#define Coil_Orange   3

void Stepper_RotateACW(void);
void Stepper_RotateCW(void);
void Stepper(void);


#endif /* REPO_HAL_STEPPER_MOTOR_STEPPER_H_ */

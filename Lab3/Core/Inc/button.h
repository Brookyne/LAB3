/*
 * button.h
 *
 *  Created on: Oct 26, 2024
 *      Author: USER
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include"main.h"
//Button's State
#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

//typedef enum{
//	Normalpress,Longpress,
//} btn_state_press;

//Declare Button
extern int KeyReg0[3];
extern int KeyReg1[3];
extern int KeyReg2[3];
extern int KeyReg3[3];

extern int TimeOutForKeyPress;
extern int button_pressed[3];
extern int button_long_pressed[3];
extern int button_flag[3];

int isButtonPressed(int index);
int isButtonLongPressed(int index);



void getKeyInput();
int subKeyProcess();

#endif /* INC_BUTTON_H_ */

/*
 * button.c
 *
 *  Created on: Oct 26, 2024
 *      Author: USER
 */
#include "button.h"
#include "main.h"
int KeyReg0[3] = { NORMAL_STATE, NORMAL_STATE, NORMAL_STATE };
int KeyReg1[3] = { NORMAL_STATE, NORMAL_STATE, NORMAL_STATE };
int KeyReg2[3] = { NORMAL_STATE, NORMAL_STATE, NORMAL_STATE };
int KeyReg3[3] = { NORMAL_STATE, NORMAL_STATE, NORMAL_STATE };

//btn_state_press btn_state = Normalpress;
int TimeOutForKeyPress = 500;
int button_pressed[3] = { 0, 0, 0 };
int button_long_pressed[3] = { 0, 0, 0 };
int button_flag[3] = { 0, 0, 0 };

//Mode button
int isButtonPressed(int index) {
	if (button_flag[index] == 1) {
		button_flag[index] = 0;
		return 1;
	}
	return 0;
}

int isButtonLongPressed(int index) {
	if (button_long_pressed[index] == 1) {
		button_long_pressed[index] = 0;
		return 1;
	}
	return 0;
}
void getKeyInput() {
	for (int i = 0; i < 3; i++) {
		KeyReg2[i] = KeyReg1[i];
		KeyReg1[i] = KeyReg0[i];
	}
	// Add your key
	KeyReg0[0] = HAL_GPIO_ReadPin(BTN1_GPIO_Port, BTN1_Pin);
	KeyReg0[1] = HAL_GPIO_ReadPin(BTN2_GPIO_Port, BTN2_Pin);
	KeyReg0[2] = HAL_GPIO_ReadPin(BTN3_GPIO_Port, BTN3_Pin);

	for (int i = 0; i < 3; i++) {
		if ((KeyReg1[i] == KeyReg0[i]) && (KeyReg1[i] == KeyReg2[i])) {
			if (KeyReg2[i] != KeyReg3[i]) {
				KeyReg3[i] = KeyReg2[i];
				if (KeyReg3[i] == PRESSED_STATE) {
					TimeOutForKeyPress = 500;
					//subKeyProcess();
					button_flag[i] = 1;
				}
			}
			else {
				TimeOutForKeyPress--;
				if (TimeOutForKeyPress == 0) {
					TimeOutForKeyPress = 500;
					if (KeyReg3[i] == PRESSED_STATE) {
						//subKeyProcess();
						button_flag[i] = 1;
					}
				}
			}
		}
	}


}


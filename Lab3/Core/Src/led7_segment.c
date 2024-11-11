/*
 * light_traffic.c
 *
 *  Created on: Oct 27, 2024
 *      Author: USER
 */

#include <led7_segment.h>
#include "main.h"

int count = 0;
Waystate current_WayState = horizontal_state;
LEDhorizontalstate current_LEDStateHorizontal = greenhorizontal_state;
LEDverticalstate current_LEDStateVertical = greenvertical_state;
int countTimeHorizontal = 5;
int countTimeVertical = 3;
int EN = 0;
void display7SEG1(int num) {
	switch (num) {
	case 0:
		HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
		HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
		HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
		HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, RESET);
		HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
		HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, SET);
		break;
	case 1:
		HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, SET);
		HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
		HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
		HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, SET);
		HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
		HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, SET);
		HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, SET);

		break;
	case 2:
		HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET); //0
		HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET); //1
		HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, SET); //2
		HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET); //3
		HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, RESET); //4
		HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, SET); //5
		HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET); //6
		break;
	case 3:
		HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET); //0
		HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET); //1
		HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET); //2
		HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET); //3
		HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET); //4
		HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, SET); //5
		HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET); //6
		break;
	case 4:
		HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, SET); //0
		HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET); //1
		HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET); //2
		HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, SET); //3
		HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET); //4
		HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET); //5
		HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET); //6
		break;
	case 5:
		HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET); //0
		HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, SET); //1
		HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET); //2
		HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET); //3
		HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET); //4
		HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET); //5
		HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET); //6
		break;
	case 6:
		HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET); //0
		HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, SET); //1
		HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET); //2
		HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET); //3
		HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, RESET); //4
		HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET); //5
		HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET); //6
		break;
	case 7:
		HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET); //0
		HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET); //1
		HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET); //2
		HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, SET); //3
		HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET); //4
		HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, SET); //5
		HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, SET); //6
		break;
	case 8:
		HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET); //0
		HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET); //1
		HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET); //2
		HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET); //3
		HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, RESET); //4
		HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET); //5
		HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET); //6
		break;
	case 9:
		HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET); //0
		HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET); //1
		HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET); //2
		HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET); //3
		HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET); //4
		HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET); //5
		HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET); //6

		break;
	}
}

void display7SEG2(int num) {
	switch (num) {
	case 0:
		HAL_GPIO_WritePin(SEG0_R_GPIO_Port, SEG0_R_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_R_GPIO_Port, SEG1_R_Pin, RESET);
		HAL_GPIO_WritePin(SEG2_R_GPIO_Port, SEG2_R_Pin, RESET);
		HAL_GPIO_WritePin(SEG3_R_GPIO_Port, SEG3_R_Pin, RESET);
		HAL_GPIO_WritePin(SEG4_R_GPIO_Port, SEG4_R_Pin, RESET);
		HAL_GPIO_WritePin(SEG5_R_GPIO_Port, SEG5_R_Pin, RESET);
		HAL_GPIO_WritePin(SEG6_R_GPIO_Port, SEG6_R_Pin, SET);
		break;
	case 1:
		HAL_GPIO_WritePin(SEG0_R_GPIO_Port, SEG0_R_Pin, SET);
		HAL_GPIO_WritePin(SEG1_R_GPIO_Port, SEG1_R_Pin, RESET);
		HAL_GPIO_WritePin(SEG2_R_GPIO_Port, SEG2_R_Pin, RESET);
		HAL_GPIO_WritePin(SEG3_R_GPIO_Port, SEG3_R_Pin, SET);
		HAL_GPIO_WritePin(SEG4_R_GPIO_Port, SEG4_R_Pin, SET);
		HAL_GPIO_WritePin(SEG5_R_GPIO_Port, SEG5_R_Pin, SET);
		HAL_GPIO_WritePin(SEG6_R_GPIO_Port, SEG6_R_Pin, SET);

		break;
	case 2:
		HAL_GPIO_WritePin(SEG0_R_GPIO_Port, SEG0_R_Pin, RESET); //0
		HAL_GPIO_WritePin(SEG1_R_GPIO_Port, SEG1_R_Pin, RESET); //1
		HAL_GPIO_WritePin(SEG2_R_GPIO_Port, SEG2_R_Pin, SET); //2
		HAL_GPIO_WritePin(SEG3_R_GPIO_Port, SEG3_R_Pin, RESET); //3
		HAL_GPIO_WritePin(SEG4_R_GPIO_Port, SEG4_R_Pin, RESET); //4
		HAL_GPIO_WritePin(SEG5_R_GPIO_Port, SEG5_R_Pin, SET); //5
		HAL_GPIO_WritePin(SEG6_R_GPIO_Port, SEG6_R_Pin, RESET); //6
		break;
	case 3:
		HAL_GPIO_WritePin(SEG0_R_GPIO_Port, SEG0_R_Pin, RESET); //0
		HAL_GPIO_WritePin(SEG1_R_GPIO_Port, SEG1_R_Pin, RESET); //1
		HAL_GPIO_WritePin(SEG2_R_GPIO_Port, SEG2_R_Pin, RESET); //2
		HAL_GPIO_WritePin(SEG3_R_GPIO_Port, SEG3_R_Pin, RESET); //3
		HAL_GPIO_WritePin(SEG4_R_GPIO_Port, SEG4_R_Pin, SET); //4
		HAL_GPIO_WritePin(SEG5_R_GPIO_Port, SEG5_R_Pin, SET); //5
		HAL_GPIO_WritePin(SEG6_R_GPIO_Port, SEG6_R_Pin, RESET); //6
		break;
	case 4:
		HAL_GPIO_WritePin(SEG0_R_GPIO_Port, SEG0_R_Pin, SET); //0
		HAL_GPIO_WritePin(SEG1_R_GPIO_Port, SEG1_R_Pin, RESET); //1
		HAL_GPIO_WritePin(SEG2_R_GPIO_Port, SEG2_R_Pin, RESET); //2
		HAL_GPIO_WritePin(SEG3_R_GPIO_Port, SEG3_R_Pin, SET); //3
		HAL_GPIO_WritePin(SEG4_R_GPIO_Port, SEG4_R_Pin, SET); //4
		HAL_GPIO_WritePin(SEG5_R_GPIO_Port, SEG5_R_Pin, RESET); //5
		HAL_GPIO_WritePin(SEG6_R_GPIO_Port, SEG6_R_Pin, RESET); //6
		break;
	case 5:
		HAL_GPIO_WritePin(SEG0_R_GPIO_Port, SEG0_R_Pin, RESET); //0
		HAL_GPIO_WritePin(SEG1_R_GPIO_Port, SEG1_R_Pin, SET);   //1
		HAL_GPIO_WritePin(SEG2_R_GPIO_Port, SEG2_R_Pin, RESET); //2
		HAL_GPIO_WritePin(SEG3_R_GPIO_Port, SEG3_R_Pin, RESET); //3
		HAL_GPIO_WritePin(SEG4_R_GPIO_Port, SEG4_R_Pin, SET);   //4
		HAL_GPIO_WritePin(SEG5_R_GPIO_Port, SEG5_R_Pin, RESET); //5
		HAL_GPIO_WritePin(SEG6_R_GPIO_Port, SEG6_R_Pin, RESET); //6
		break;
	case 6:
		HAL_GPIO_WritePin(SEG0_R_GPIO_Port, SEG0_R_Pin, RESET); //0
		HAL_GPIO_WritePin(SEG1_R_GPIO_Port, SEG1_R_Pin, SET);   //1
		HAL_GPIO_WritePin(SEG2_R_GPIO_Port, SEG2_R_Pin, RESET); //2
		HAL_GPIO_WritePin(SEG3_R_GPIO_Port, SEG3_R_Pin, RESET); //3
		HAL_GPIO_WritePin(SEG4_R_GPIO_Port, SEG4_R_Pin, RESET); //4
		HAL_GPIO_WritePin(SEG5_R_GPIO_Port, SEG5_R_Pin, RESET); //5
		HAL_GPIO_WritePin(SEG6_R_GPIO_Port, SEG6_R_Pin, RESET); //6
		break;
	case 7:
		HAL_GPIO_WritePin(SEG0_R_GPIO_Port, SEG0_R_Pin, RESET); //0
		HAL_GPIO_WritePin(SEG1_R_GPIO_Port, SEG1_R_Pin, RESET); //1
		HAL_GPIO_WritePin(SEG2_R_GPIO_Port, SEG2_R_Pin, RESET); //2
		HAL_GPIO_WritePin(SEG3_R_GPIO_Port, SEG3_R_Pin, SET);   //3
		HAL_GPIO_WritePin(SEG4_R_GPIO_Port, SEG4_R_Pin, SET);   //4
		HAL_GPIO_WritePin(SEG5_R_GPIO_Port, SEG5_R_Pin, SET);   //5
		HAL_GPIO_WritePin(SEG6_R_GPIO_Port, SEG6_R_Pin, SET);   //6
		break;
	case 8:
		HAL_GPIO_WritePin(SEG0_R_GPIO_Port, SEG0_R_Pin, RESET); //0
		HAL_GPIO_WritePin(SEG1_R_GPIO_Port, SEG1_R_Pin, RESET); //1
		HAL_GPIO_WritePin(SEG2_R_GPIO_Port, SEG2_R_Pin, RESET); //2
		HAL_GPIO_WritePin(SEG3_R_GPIO_Port, SEG3_R_Pin, RESET); //3
		HAL_GPIO_WritePin(SEG4_R_GPIO_Port, SEG4_R_Pin, RESET); //4
		HAL_GPIO_WritePin(SEG5_R_GPIO_Port, SEG5_R_Pin, RESET); //5
		HAL_GPIO_WritePin(SEG6_R_GPIO_Port, SEG6_R_Pin, RESET); //6
		break;
	case 9:
		HAL_GPIO_WritePin(SEG0_R_GPIO_Port, SEG0_R_Pin, RESET); //0
		HAL_GPIO_WritePin(SEG1_R_GPIO_Port, SEG1_R_Pin, RESET); //1
		HAL_GPIO_WritePin(SEG2_R_GPIO_Port, SEG2_R_Pin, RESET); //2
		HAL_GPIO_WritePin(SEG3_R_GPIO_Port, SEG3_R_Pin, RESET); //3
		HAL_GPIO_WritePin(SEG4_R_GPIO_Port, SEG4_R_Pin, SET); //4
		HAL_GPIO_WritePin(SEG5_R_GPIO_Port, SEG5_R_Pin, RESET); //5
		HAL_GPIO_WritePin(SEG6_R_GPIO_Port, SEG6_R_Pin, RESET); //6

		break;
	}
}

void display7SEGEN(int num) {
	switch (EN) {
	case 0:
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, RESET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, SET);
		display7SEG1(0);
//		if (num >= 4) {
//			num = num % 4;
//		}
		display7SEG2(num);
		break;
	case 1:
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, SET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, RESET);
		if (num >= 100) {
			num = num % 100;
		}
		display7SEG1(num / 10);
		display7SEG2(num % 10);
		break;
	}

}

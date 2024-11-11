/*
 * traffic_light.c
 *
 *  Created on: Oct 28, 2024
 *      Author: USER
 */

#include "traffic_light.h"
#include "software_timer.h"
#include "main.h"
int tmp = 0;
void led_red_and_green() {
	//On 2
	HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, SET);
	HAL_GPIO_WritePin(G2_GPIO_Port, G2_Pin, SET);

	//Off 4
	HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, RESET);
	HAL_GPIO_WritePin(Y1_GPIO_Port, Y1_Pin, RESET);

	HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, RESET);
	HAL_GPIO_WritePin(Y2_GPIO_Port, Y2_Pin, RESET);
}

void led_red_and_yellow() {
	//ON 2
	HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, SET);
	HAL_GPIO_WritePin(Y2_GPIO_Port, Y2_Pin, SET);

	//0FF 4
	HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, RESET);
	HAL_GPIO_WritePin(Y1_GPIO_Port, Y1_Pin, RESET);

	HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, RESET);
	HAL_GPIO_WritePin(G2_GPIO_Port, G2_Pin, RESET);

}

void led_green_and_red() {
	//ON 2
	HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, SET);
	HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, SET);

	//0FF 4
	HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, RESET);
	HAL_GPIO_WritePin(Y1_GPIO_Port, Y1_Pin, RESET);

	HAL_GPIO_WritePin(Y2_GPIO_Port, Y2_Pin, RESET);
	HAL_GPIO_WritePin(G2_GPIO_Port, G2_Pin, RESET);

}

void led_yellow_and_red() {
	//ON 2
	HAL_GPIO_WritePin(Y1_GPIO_Port, Y1_Pin, SET);
	HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, SET);

	//0FF 4
	HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, RESET);
	HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, RESET);

	HAL_GPIO_WritePin(Y2_GPIO_Port, Y2_Pin, RESET);
	HAL_GPIO_WritePin(G2_GPIO_Port, G2_Pin, RESET);

}

void led_init() {
	HAL_GPIO_WritePin(Y1_GPIO_Port, Y1_Pin, RESET);
	HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, RESET);

	//0FF 4
	HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, RESET);
	HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, RESET);

	HAL_GPIO_WritePin(Y2_GPIO_Port, Y2_Pin, RESET);
	HAL_GPIO_WritePin(G2_GPIO_Port, G2_Pin, RESET);
}
void led_green() {
	//ON 2
	if (timer2_flag == 1) {
		setTimer2(50);
//		HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, SET);
//		HAL_GPIO_WritePin(G2_GPIO_Port, G2_Pin, SET);
		HAL_GPIO_TogglePin(G1_GPIO_Port, G1_Pin);
		HAL_GPIO_TogglePin(G2_GPIO_Port, G2_Pin);
	}
//			HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, SET);
//			HAL_GPIO_WritePin(G2_GPIO_Port, G2_Pin, SET);
	//0FF 4
	HAL_GPIO_WritePin(Y1_GPIO_Port, Y1_Pin, RESET);
	HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, RESET);

	HAL_GPIO_WritePin(Y2_GPIO_Port, Y2_Pin, RESET);
	HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, RESET);
}

void led_red() {
	//ON 2

	if (timer2_flag == 1) {
		setTimer2(50);
		if (tmp == 0) {
			HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, RESET);
			HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, RESET);
			tmp = 1 - tmp;

		}
		HAL_GPIO_TogglePin(R1_GPIO_Port, R1_Pin);
		HAL_GPIO_TogglePin(R2_GPIO_Port, R2_Pin);
	}
//				HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, SET);
//				HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, SET);

	//0FF 4
	HAL_GPIO_WritePin(Y1_GPIO_Port, Y1_Pin, RESET);
	HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, RESET);

	HAL_GPIO_WritePin(Y2_GPIO_Port, Y2_Pin, RESET);
	HAL_GPIO_WritePin(G2_GPIO_Port, G2_Pin, RESET);
}

void led_yellow() {
	//ON 2
	if (timer2_flag == 1) {
		setTimer2(50);
//		HAL_GPIO_WritePin(Y1_GPIO_Port, Y1_Pin, SET);
//		HAL_GPIO_WritePin(Y2_GPIO_Port, Y2_Pin, SET);
		HAL_GPIO_TogglePin(Y1_GPIO_Port, Y1_Pin);
		HAL_GPIO_TogglePin(Y2_GPIO_Port, Y2_Pin);
	}

//			HAL_GPIO_WritePin(Y1_GPIO_Port, Y1_Pin, SET);
//			HAL_GPIO_WritePin(Y2_GPIO_Port, Y2_Pin, SET);
	//0FF 4
	HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, RESET);
	HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, RESET);

	HAL_GPIO_WritePin(G2_GPIO_Port, G2_Pin, RESET);
	HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, RESET);
}


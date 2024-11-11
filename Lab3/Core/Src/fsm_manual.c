/*
 * fsm_manual.c
 *
 *  Created on: Oct 30, 2024
 *      Author: USER
 */

#include "fsm_manual.h"

void fsm_manual_run() {
	switch (status) {
	case MAN_INIT:
		led_init();
		setTimer1(100);
		status = MAN_RED;
		if (isButtonPressed(0) == 1) {
			status = MAN_RED;
			setTimer1(200);
		}
		if(timer1_flag==1){
			status=MAN_RED;
			setTimer1(200);
		}

		break;
	case MAN_RED:
		led_red();
//		if(timer1_flag==1){
//					status=MAN_RED;
//					setTimer1(200);
//				}
		if (isButtonPressed(0) == 1) {
			status = MAN_YELLOW;
			setTimer1(200);
		}
		if (timer3_flag == 1) {
			if (EN == 0) {
				display7SEGEN(2);
			} else
				display7SEGEN(tmp_RedDura);
			setTimer3(50);
			EN = 1 - EN;
		}
		//BTN2 INCREASE VALUE
		if (isButtonPressed(1) == 1) {
			tmp_RedDura++;
			if (tmp_RedDura> 99) {
				tmp_RedDura = 2;
			}
		}
//		BTN3 VERIFY VALUE
		if (isButtonPressed(2) == 1) {

		}
		break;
	case MAN_YELLOW:
		led_yellow();
		if (isButtonPressed(0) == 1) {
			status = MAN_GREEN;
			setTimer1(200);
		}
//		if(timer1_flag==1){
//					status=MAN_RED;
//					setTimer1(200);
//				}
		if (timer3_flag == 1) {
			if (EN == 0) {
				display7SEGEN(3);
			} else
				display7SEGEN(tmp_YellowDura);
			setTimer3(50);
			EN = 1 - EN;
		}
		//BTN2 INCREASE VALUE
		if (isButtonPressed(1) == 1) {
			tmp_YellowDura++;

			if (tmp_YellowDura> 99 ) {
				tmp_YellowDura = 1;
			}
		}
		//BTN3 VERIFY VALUE
		if (isButtonPressed(2) == 1) {

		}
		break;
	case MAN_GREEN:
		led_green();
		if (isButtonPressed(0) == 1) {
			status = INIT;
			setTimer1(200);
		}
//		if(timer1_flag==1){
//					status=MAN_RED;
//					setTimer1(200);
//				}
		if (timer3_flag == 1) {
			if (EN == 0) {
				display7SEGEN(4);
			} else
				display7SEGEN(tmp_GreenDura);
			setTimer3(50);
			EN = 1 - EN;
		}
		//BTN2 INCREASE VALUE
		if (isButtonPressed(1) == 1) {
			tmp_GreenDura++;
			if (tmp_GreenDura > 99) {
				tmp_GreenDura = 1;
			}
		}
		//BTN3 VERIFY VALUE
		if (isButtonPressed(2) == 1) {
			if(tmp_GreenDura + tmp_YellowDura == tmp_RedDura){
			GreenDura=tmp_GreenDura;
			RedDura=tmp_RedDura;
			YellowDura=tmp_YellowDura;
			}
			else {
				tmp_RedDura=RedDura;
				tmp_YellowDura=YellowDura;
				tmp_GreenDura=GreenDura;
			}
		}
		break;
	default:
		break;
	}

}

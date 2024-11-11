/*
 * fsm_automatic.c
 *
 *  Created on: Oct 29, 2024
 *      Author: USER
 */

#include "fsm_automatic.h"
#include "main.h"

void fsm_automatic_run() {
	switch (status) {
	case INIT:
		setTimer1(GreenDura * 100);
//		setTimer3(50);
		status = LED_RED_AND_GREEN;
		break;
	case LED_RED_AND_GREEN:
		led_red_and_green();
		if (timer1_flag == 1) {
			setTimer1(YellowDura * 100);
			status = LED_RED_AND_YELLOW;
		}
		if (isButtonPressed(0) == 1) {
			status = MAN_INIT;

		}
		if (timer3_flag == 1) {
			setTimer3(50);
			if (EN == 0) {
				display7SEGEN(RedDura--);
				if (RedDura == 0) {
					RedDura = tmp_RedDura;
				}
			} else {
				display7SEGEN(GreenDura--);
				if (GreenDura == 0) {
					GreenDura = tmp_GreenDura;
				}
			}
			EN = 1 - EN;
		}
		break;
	case LED_RED_AND_YELLOW:
		led_red_and_yellow();
		if (timer1_flag == 1) {
			setTimer1(GreenDura * 100);
			status = LED_GREEN_AND_RED;
		}
		if (isButtonPressed(0) == 1) {
			status = MAN_INIT;
			setTimer1(200);
		}
		if (timer3_flag == 1) {
			setTimer3(50);
			if (EN == 0) {
				display7SEGEN(RedDura--);
				if (RedDura == 0) {
					RedDura = tmp_RedDura;
				}
			} else {
				display7SEGEN(YellowDura--);
				if (YellowDura == 0) {
					YellowDura = tmp_YellowDura;
				}
			}
			EN = 1 - EN;
		}
		break;
	case LED_GREEN_AND_RED:
		led_green_and_red();
		if (timer1_flag == 1) {
			setTimer1(YellowDura * 100);
			status = LED_YELLOW_AND_RED;
		}
		if (isButtonPressed(0) == 1) {
			status = MAN_INIT;
			setTimer1(200);
		}
		if (timer3_flag == 1) {
			setTimer3(50);
			if (EN == 0) {
				display7SEGEN(RedDura--);
				if (RedDura == 0) {
					RedDura = tmp_RedDura;
				}
			} else {
				display7SEGEN(GreenDura--);
				if (GreenDura == 0) {
					GreenDura = tmp_GreenDura;
				}
			}
			EN = 1 - EN;
		}
		break;
	case LED_YELLOW_AND_RED:
		led_yellow_and_red();
		if (timer1_flag == 1) {
			setTimer1(GreenDura * 100);
			status = LED_RED_AND_GREEN;
		}
		if (isButtonPressed(0) == 1) {
			status = MAN_INIT;
			setTimer1(200);
		}
		if (timer3_flag == 1) {
			setTimer3(50);
			if (EN == 0) {
				display7SEGEN(RedDura--);
				if (RedDura == 0) {
					RedDura = tmp_RedDura;
				}
			} else {
				display7SEGEN(YellowDura--);
				if (YellowDura == 0) {
					YellowDura = tmp_YellowDura;
				}
			}
			EN = 1 - EN;
		}
		break;
	}
}


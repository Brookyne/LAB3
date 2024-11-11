/*
 * global.h
 *
 *  Created on: Oct 26, 2024
 *      Author: USER
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_


#include "software_timer.h"
#include "button.h"
#include "led7_segment.h"
#include "traffic_light.h"

#define INIT 1
#define LED_RED_AND_GREEN 2
#define LED_RED_AND_YELLOW 3
#define LED_GREEN_AND_RED 4
#define LED_YELLOW_AND_RED 5

#define MAN_RED 12
#define MAN_GREEN 13
#define MAN_YELLOW 14
#define MAN_INIT 15

#define MAX_DURA 99

extern int RedDura;
extern int GreenDura;
extern int YellowDura;

extern int tmp_RedDura;
extern int tmp_GreenDura;
extern int tmp_YellowDura;

extern int RedDura7SEG;
extern int GreenDura7SEG;
extern int YellowDura7SEG;

extern int status;
extern int status1;
extern int status2;


// Traffic light



#endif /* INC_GLOBAL_H_ */

/*
 * software_timer.h
 *
 *  Created on: Oct 26, 2024
 *      Author: USER
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

//MAX LED TIME
#define maxduration 99

//MAX NUMBER OF TIMERS
#define maxtimer_counter 3
#define maxtimer_flag 3

//bien
extern int timer1_counter;
extern int timer1_flag;
extern int timer2_counter;
extern int timer2_flag;
extern int timer3_counter;
extern int timer3_flag;

//LED BINKY
void setTimer1(int duration);

void setTimer2(int duration);
//BUTTONS
void setTimer3(int duration);

void timerRun();


#endif /* INC_SOFTWARE_TIMER_H_ */

/*
 * light_traffic.h
 *
 *  Created on: Oct 27, 2024
 *      Author: USER
 */

#ifndef INC_LED7_SEGMENT_H_
#define INC_LED7_SEGMENT_H_


typedef enum {
	redhorizontal_state, yellowhorizontal_state, greenhorizontal_state,
} LEDhorizontalstate;
typedef enum {
	redvertical_state, yellowvertical_state, greenvertical_state,
} LEDverticalstate;
typedef enum {
	horizontal_state, vertical_state,
} Waystate;



extern int EN;

void display7SEG1(int num);
void display7SEG2(int num);
void display7SEGEN();


void fourwaylight();



#endif /* INC_LED7_SEGMENT_H_ */

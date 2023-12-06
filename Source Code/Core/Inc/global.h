/*
 * global.h
 *
 *  Created on: Dec 6, 2023
 *      Author: Admin
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include<stdio.h>
#include<main.h>

#define INIT			1
#define RED-GREEN		2
#define RED-YELLOW		3
#define GREEN-RED		4
#define YELLOW-RED		5

#define MAN-RED			13
#define MAN-YELLOW		14
#define MAN-GREEN		15

extern int status;
extern int index_led;
extern int horizontal_number;
extern int vertical_number;

void updateClockBuffer();
void countDown();
void setInitialValue(int horizontal, int vertical);
void setHorizontalLeds(int red, int green, int yellow);
void setHorizontalLeds(int red, int green, int yellow);
void setHorizontalLeds(int red, int green, int yellow);

extern int red_duration;
extern int green_duration;
extern int yellow_duration;

UART_HandleTypeDef huart2;


#endif /* INC_GLOBAL_H_ */

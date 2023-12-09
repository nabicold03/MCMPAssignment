/*
 * fsm_automatic.c
 *
 *  Created on: Dec 6, 2023
 *      Author: Admin
 */

#include"fsm_automatic.h"
//int pedeson=0;
int pedesduration;
void fsm_automatic_run(){
	switch(status){
		case INIT:
			//change state
			status=RED_GREEN;
			setInitialValue(red_duration, green_duration);
			setTimer(green_duration*100,0);
			setTimer(100,1);
			break;
		case RED_GREEN:
			setHorizontalLeds(SET,RESET,RESET);	//D4-5 horizontal
			setVerticalLeds(RESET,SET, RESET);
			if(timer_flag[9]==1){
				pedeson=0;
				setPedesLeds(RESET, RESET, RESET);	//enough time for 2 cycles, turnoff pedeslight
			}
			if(pedeson==1){
				setPedesLeds(RESET,SET,RESET);
			}
			if(timer_flag[0] == 1){
//				setPedesLeds(RESET,RESET,RESET);
				setTimer(yellow_duration*100, 0);
//				setHorizontalLeds(RESET,RESET,RESET); //D4-5 horizontal
//				setVerticalLeds(RESET,RESET, RESET);
				status = RED_YELLOW;
				setInitialValue(yellow_duration, yellow_duration);
			}
			if(timer_flag[1] == 1){
				countDown();
				setTimer(100, 1);
			}
			if(isButtonPressed(1) == 1){ //change mode
				setHorizontalLeds(RESET,RESET,RESET);	//turn off all leds
				setVerticalLeds(RESET,RESET, RESET);	//turn off all leds
				setPedesLeds(RESET,RESET,RESET);		//turn off all leds
				setTimer(100, 3);
				status = MAN_RED;
			}
			if(isButtonPressed(0) == 1){
				setPedesLeds(RESET,SET,RESET);
				pedeson=1;
				pedesduration = (red_duration+green_duration+yellow_duration)*200;
				setTimer(pedesduration,9);
			}
			break;
		case RED_YELLOW:
			setHorizontalLeds(SET,RESET,RESET);
			setVerticalLeds(RESET,RESET, SET);
			if(timer_flag[9]==1){
				pedeson=0;
				setPedesLeds(RESET, RESET, RESET);
			}
			if(pedeson==1){
				setPedesLeds(RESET, SET, RESET);
			}
			if(timer_flag[0] == 1){
//				setPedesLeds(RESET,RESET,RESET);
				setTimer(green_duration*100, 0);
				status = GREEN_RED;
				setInitialValue(green_duration, red_duration);
//				setHorizontalLeds(RESET,RESET,RESET); //D4-5 horizontal
//				setVerticalLeds(RESET,RESET, RESET);
			}
			if(timer_flag[1] == 1){
				countDown();
				setTimer(100, 1);
			}
			if(isButtonPressed(0) == 1){
				setPedesLeds(RESET,SET,RESET);
				pedeson=1;
				pedesduration = (red_duration+green_duration+yellow_duration)*200;
				setTimer(pedesduration,9);
			}
			break;
		case GREEN_RED:
			setHorizontalLeds(RESET,SET,RESET);
			setVerticalLeds(SET,RESET,RESET);
			if(timer_flag[9]==1){
				pedeson=0;
				setPedesLeds(RESET, RESET, RESET);
			}
			if(pedeson==1){
				setPedesLeds(SET, RESET, RESET);
			}
			if(timer_flag[0] == 1){
//				setPedesLeds(RESET,RESET,RESET);
				setTimer(yellow_duration*100, 0);
				status = YELLOW_RED;
				setInitialValue(yellow_duration, yellow_duration);
//				setHorizontalLeds(RESET,RESET,RESET); //D4-5 horizontal
//				setVerticalLeds(RESET,RESET, RESET);
			}
			if(timer_flag[1] == 1){
				countDown();
				setTimer(100, 1);
			}
			if(isButtonPressed(0) == 1){
				setPedesLeds(SET,RESET,RESET);
				pedeson=1;
				pedesduration = (red_duration+green_duration+yellow_duration)*200;
				setTimer(pedesduration,9);
			}
			break;
		case YELLOW_RED:
			setHorizontalLeds(RESET,RESET,SET);
			setVerticalLeds(SET,RESET,RESET);
			if(timer_flag[9]==1){
				pedeson=0;
				setPedesLeds(RESET, RESET, RESET);
			}
			if(pedeson==1){
				setPedesLeds(SET, RESET, RESET);
			}
			if(timer_flag[0] == 1){
//				setPedesLeds(RESET,RESET,RESET);
				setTimer(green_duration*100, 0);
				status = RED_GREEN;
				setInitialValue(red_duration, green_duration);
//				setHorizontalLeds(RESET,RESET,RESET); //D4-5 horizontal
//				setVerticalLeds(RESET,RESET, RESET);
			}
			if(timer_flag[1] == 1){
				countDown();
				setTimer(100, 1);
			}
			if(isButtonPressed(0) == 1){
				setPedesLeds(SET,RESET,RESET);
				pedeson=1;
				pedesduration = (red_duration+green_duration+yellow_duration)*200;
				setTimer(pedesduration,9);
			}
			break;
		default:
			break;
	}
}

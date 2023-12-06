/*
 * global.c
 *
 *  Created on: Dec 6, 2023
 *      Author: Admin
 */

#include"global.h"

int status=0;
int horizontal_number=0;
int vertical_number=0;

//time counting down
void countDown(){
	horizontal_number--;
	vertical_number--;
}

void setHorizontalLeds(int red, int green, int yellow){
    if(red == SET){
        HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, SET);
        HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, RESET);
    }
    if(green == SET){
        HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, RESET);
        HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, SET);
    }
    if(yellow == SET){
        HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, SET);
        HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, SET);
    }
    if(red==RESET && green==RESET && yellow==RESET){
        HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, RESET);
        HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, RESET);
    }
}
void setVerticalLeds(int red, int green, int yellow){
    if(red == SET){
        HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, SET);
        HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, RESET);
    }
    if(green == SET){
        HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, RESET);
        HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, SET);
    }
    if(yellow == SET){
        HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, SET);
        HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, SET);
    }
    if(red==RESET && green==RESET && yellow==RESET){
        HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, RESET);
        HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, RESET);
    }
}

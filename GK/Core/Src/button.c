/*
 * button.c
 *
 *  Created on: Oct 24, 2022
 *      Author: ntdat
 */

#include "button.h"
#define TIME_FOR_KEY_PRESS 300
#define TIME_FOR_DOUBLE_CLICK 50


int KeyReg0[MAX_BUTTON] = {[0 ... MAX_BUTTON - 1] = NORMAL_STATE};
int KeyReg1[MAX_BUTTON] = {[0 ... MAX_BUTTON - 1] = NORMAL_STATE};
int KeyReg2[MAX_BUTTON] = {[0 ... MAX_BUTTON - 1] = NORMAL_STATE};
int KeyReg3[MAX_BUTTON] = {[0 ... MAX_BUTTON - 1] = NORMAL_STATE};

int counterButton[MAX_BUTTON] = {0};
int counterDoubleClick[MAX_BUTTON] ={0};

int flagButton_1s[MAX_BUTTON] = {0};
int flagButton[MAX_BUTTON] = {0};
int flagButton_Double_Click[MAX_BUTTON] = {[0 ... MAX_BUTTON - 1] = 0};
int stillPress[MAX_BUTTON] = {0};

int isButtonPRESS(int index){
	if(index >= MAX_BUTTON) return 0;
	if(flagButton[index] == 1){
		flagButton[index] = 0;
		return 1;
	}
	return 0;
}
int isButtonPRESS3s(int index){
	if(index >= MAX_BUTTON) return 0;
	if(flagButton_1s[index] == 1){
		flagButton_1s[index] = 0;
		return 1;
	}
	return 0;
}
int stillPRESS(int index){
	return stillPress[index];
}

void getKeyInput(){
	for(int i = 0 ; i < MAX_BUTTON; ++i)
	{
		KeyReg0[i] = KeyReg1[i];
		KeyReg1[i] = KeyReg2[i];
		if(i == 0){
			KeyReg2[i] = HAL_GPIO_ReadPin(BUTTON1_GPIO_Port, BUTTON1_Pin);
		}else if(i == 1){
			KeyReg2[i] = HAL_GPIO_ReadPin(BUTTON2_GPIO_Port, BUTTON2_Pin);
		}else if(i == 2){
			KeyReg2[i] = HAL_GPIO_ReadPin(BUTTON3_GPIO_Port, BUTTON3_Pin);
		}
		if((KeyReg0[i] == KeyReg1[i]) && (KeyReg1[i] == KeyReg2[i])){
			if(KeyReg3[i] != KeyReg2[i]){
				KeyReg3[i] = KeyReg2[i];
				if(KeyReg2[i] == PRESS_STATE){
					flagButton[i] = 1;
					stillPress[i] = 1;
					counterButton[i] = TIME_FOR_KEY_PRESS;
				}else{
					stillPress[i] = 0;
				}
			}else{
				counterButton[i]--;
				if(counterButton[i] == 0){
					flagButton_1s[i] = 1;
				}
			}
		}
	 }
}



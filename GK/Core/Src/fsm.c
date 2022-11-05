/*
 * fsm.c
 *
 *  Created on: Nov 4, 2022
 *      Author: ntdat
 */


#include "main.h"
#include "fsm.h"

int temp = 0;
int isPress_over3s = 0;
#define TIME_RUN 50
#define TIME_COUNTER 100

void fsm_run(){
	display7SEG(counter);
	switch(status){
		case INIT:
			if(isButtonPRESS(0)){
				status = MODE_RESET;
				setTimer(0, TIME_RUN);
			}
			if(isButtonPRESS(1)){
				status = MODE_INC;
				setTimer(0, TIME_RUN);
				counter ++;
			}
			if(isButtonPRESS(2)){
				status = MODE_DEC;
				setTimer(0, TIME_RUN);
				counter --;
			}
			break;
		case MODE_RESET:
			counter = 0;
			if(isTimer_timeout(0)){
				status = MODE_RUN;
				setTimer(1, TIME_COUNTER);
				temp = counter;
			}
			if(isButtonPRESS(1)){
				status = MODE_INC;
				setTimer(0, TIME_RUN);
				counter ++;
			}else if(isButtonPRESS(2)){
				status = MODE_DEC;
				setTimer(0, TIME_RUN);
				counter --;
			}
			break;
		case MODE_INC:
			if(counter > 9){
				counter = 0;
			}
			if(isTimer_timeout(0)){
				status = MODE_RUN;
				setTimer(1, TIME_COUNTER);
				temp = counter;
			}
			if(stillPRESS(1)){
				setTimer(0, TIME_RUN);
				if(isButtonPRESS3s(1)){
					counter ++;
					isPress_over3s = 1;
					setTimer(4, 100);
				}
				if(isTimer_timeout(4) && isPress_over3s == 1){
					counter ++;
					setTimer(4, 100);
				}
			}else{
				isPress_over3s = 0;
			}
			if(isButtonPRESS(1)){
				counter ++;
			}else if(isButtonPRESS(0)){
				status = MODE_RESET;
				setTimer(0, TIME_RUN);
			}else if(isButtonPRESS(2)){
				status = MODE_DEC;
				setTimer(0, TIME_RUN);
				counter --;
				if(counter < 0){
					counter = 9;
				}
			}
			break;
		case MODE_DEC:
			if(counter < 0){
				counter = 9;
			}
			if(isTimer_timeout(0)){
				status = MODE_RUN;
				setTimer(1, TIME_COUNTER);
				temp = counter;
			}
			if(stillPRESS(2)){
				setTimer(0, TIME_RUN);
				if(isButtonPRESS3s(2)){
					counter --;
					isPress_over3s = 1;
					setTimer(4, 100);
				}
				if(isTimer_timeout(4) && isPress_over3s == 1){
					counter --;
					setTimer(4, 100);
				}
			}else{
				isPress_over3s = 0;
			}
			if(isButtonPRESS(2)){
				counter --;
			}else if(isButtonPRESS(0)){
				status = MODE_RESET;
				setTimer(0, TIME_RUN);
			}else if(isButtonPRESS(1)){
				status = MODE_INC;
				setTimer(0, TIME_RUN);
				counter ++;
				if(counter > 9){
					counter = 0;
				}
			}
			break;
		case MODE_RUN:
			if(counter > 0){
				if(isTimer_timeout(1)){
					counter --;
					setTimer(1, TIME_COUNTER);
				}
			}else{
				status = INIT;
			}
			if(isButtonPRESS(0)){
				status = MODE_RESET;
				setTimer(0, TIME_RUN);
				counter = temp;
			}else if(isButtonPRESS(1)){
				status = MODE_INC;
				setTimer(0, TIME_RUN);
				counter = temp;
			}else if(isButtonPRESS(2)){
				status = MODE_DEC;
				setTimer(0, TIME_RUN);
				counter = temp;
			}
			break;
		default:
			break;
	}
}

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
				setTimer(0, TIME_RUN);
				status = MODE_RESET;
			}
			if(isButtonPRESS(1)){
				setTimer(0, TIME_RUN);
				counter ++;
				status = MODE_INC;
			}
			if(isButtonPRESS(2)){
				setTimer(0, TIME_RUN);
				counter --;
				status = MODE_DEC;
			}
			break;
		case MODE_RESET:
			counter = 0;
			temp = 0;
			setTimer(0, 0);
			setTimer(1, 0);
			if(isButtonPRESS(1)){
				setTimer(0, TIME_RUN);
				status = MODE_INC;
			}else if(isButtonPRESS(2)){
				setTimer(0, TIME_RUN);
				status = MODE_DEC;
			}
			break;
		case MODE_INC:
			if(counter > 9){
				counter = 0;
			}
			if(isTimer_timeout(0)){
				setTimer(1, TIME_COUNTER);
				temp = counter;
				status = MODE_RUN;
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
				setTimer(0, TIME_RUN);
				status = MODE_RESET;
			}else if(isButtonPRESS(2)){
				setTimer(0, TIME_RUN);
				status = MODE_DEC;
			}
			break;
		case MODE_DEC:
			if(counter < 0){
				counter = 9;
			}
			if(isTimer_timeout(0)){
				setTimer(1, TIME_COUNTER);
				temp = counter;
				status = MODE_RUN;
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
				setTimer(0, TIME_RUN);
				status = MODE_RESET;
			}else if(isButtonPRESS(1)){
				setTimer(0, TIME_RUN);
				status = MODE_INC;
			}
			break;
		case MODE_RUN:
			if(counter > 0){
				if(isTimer_timeout(1)){
					counter --;
					setTimer(1, TIME_COUNTER);
				}
			}
			if(isButtonPRESS(0)){
				setTimer(0, TIME_RUN);
				counter = temp;
				status = MODE_RESET;
			}else if(isButtonPRESS(1)){
				setTimer(0, TIME_RUN);
				counter = temp;
				status = MODE_INC;
			}else if(isButtonPRESS(2)){
				setTimer(0, TIME_RUN);
				counter = temp;
				status = MODE_DEC;
			}
			break;
		default:
			break;
	}
}

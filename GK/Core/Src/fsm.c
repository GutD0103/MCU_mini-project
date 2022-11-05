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
#define TIME_RUN 1000
#define TIME_COUNTER 100

void fsm_run(){
	display7SEG(counter);
	switch(status){
		case INIT:
			// thay doi trang thai
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
			// thay doi trang thai
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
			// khong an nut trong 10s
			if(isTimer_timeout(0)){
				setTimer(1, TIME_COUNTER);
				status = MODE_RUN;
			}
			// kiem tra an nut hay khong
			if(stillPRESS(1)){
				setTimer(0, TIME_RUN);
				// an nut trong 3s
				if(isButtonPRESS3s(1)){
					counter ++;
					isPress_over3s = 1;
					setTimer(4, 100);
				}
				// sau an nut trong 3s moi 1s
				// gia tri tang 1
				if(isTimer_timeout(4) && isPress_over3s == 1){
					counter ++;
					setTimer(4, 100);
				}
			}else{
				// khong an nut
				isPress_over3s = 0;
			}
			// chuyen trang thai
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
			// khong an nut 10s
			if(isTimer_timeout(0)){
				setTimer(1, TIME_COUNTER);
				status = MODE_RUN;
			}
			// kiem tra nut an hay khong
			if(stillPRESS(2)){
				setTimer(0, TIME_RUN);
				// nut an trong vong 3s
				if(isButtonPRESS3s(2)){
					counter --;
					isPress_over3s = 1;
					setTimer(4, 100);
				}
				// sau an nut trong 3s moi 1s
			    // gia tri giam 1
				if(isTimer_timeout(4) && isPress_over3s == 1){
					counter --;
					setTimer(4, 100);
				}
			}else{
				// khong an nut
				isPress_over3s = 0;
			}
			// chuyen trang thai
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
			// dem nguoc
			if(counter > 0){
				if(isTimer_timeout(1)){
					counter --;
					setTimer(1, TIME_COUNTER);
				}
			}
			//chuyen trang thai
			if(isButtonPRESS(0)){
				setTimer(0, TIME_RUN);
				status = MODE_RESET;
			}else if(isButtonPRESS(1)){
				setTimer(0, TIME_RUN);
				status = MODE_INC;
			}else if(isButtonPRESS(2)){
				setTimer(0, TIME_RUN);
				status = MODE_DEC;
			}
			break;
		default:
			break;
	}
}

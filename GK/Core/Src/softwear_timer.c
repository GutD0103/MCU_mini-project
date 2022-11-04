/*
 * softwear.c
 *
 *  Created on: Oct 24, 2022
 *      Author: ntdat
 */

#include <softwear_timer.h>
#define TICK 10


int timer_counter[MAX_TIMER] = {0};
int timer_flag[MAX_TIMER] = {0};

void setTimer(int index, int duration){
	timer_counter[index] = duration;
	timer_flag[index] = 0;
};

int isTimer_timeout(int index){
	if(timer_flag[index]){
		timer_flag[index] = 0;
		return 1;
	}
	return 0;
}

void timerRun(){
	for(int i = 0; i < MAX_TIMER ; i++)
	{
		if(timer_counter[i] > 0){
			timer_counter[i] -- ;
			if(timer_counter [i] == 0){
				timer_flag[i] = 1;
			}
		}
	}
};

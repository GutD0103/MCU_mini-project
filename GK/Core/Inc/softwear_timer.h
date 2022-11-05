/*
 * softwear.h
 *
 *  Created on: Oct 24, 2022
 *      Author: ntdat
 */

#ifndef INC_SOFTWEAR_TIMER_H_
#define INC_SOFTWEAR_TIMER_H_

#define MAX_TIMER 5

extern int timer_flag[MAX_TIMER];

void setTimer(int index, int duration);
int isTimer_timeout(int index);
void timerRun();


#endif /* INC_SOFTWEAR_TIMER_H_ */

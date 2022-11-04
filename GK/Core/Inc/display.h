/*
 * display.h
 *
 *  Created on: Oct 26, 2022
 *      Author: ntdat
 */

#ifndef INC_DISPLAY_H_
#define INC_DISPLAY_H_

#include "main.h"
#define MAX_LED 4

void display7SEG(int num);
void update7SEG ( int index ) ;
void updateClockBuffer (int index, int value);


#endif /* INC_DISPLAY_H_ */

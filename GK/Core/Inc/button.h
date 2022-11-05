/*
 * button.h
 *
 *  Created on: Oct 24, 2022
 *      Author: ntdat
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#define NORMAL_STATE GPIO_PIN_SET
#define PRESS_STATE GPIO_PIN_RESET
#define MAX_BUTTON 3

#include "main.h"


int isButtonPRESS(int index);
int isButtonPRESS3s(int index);
int stillPRESS(int index);
int isButtonDoubleClick(int index);
void getKeyInput();

#endif /* INC_BUTTON_H_ */

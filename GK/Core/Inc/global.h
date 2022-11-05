/*
 * global.h
 *
 *  Created on: Oct 24, 2022
 *      Author: ntdat
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "softwear_timer.h"
#include "button.h"
#include "main.h"
#include "display.h"

#define INIT 0
#define MODE_RESET 1
#define MODE_INC 2
#define MODE_DEC 3
#define MODE_RUN 4

extern int status;
extern int counter;

#endif /* INC_GLOBAL_H_ */

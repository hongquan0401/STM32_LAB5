/*
 * global.h
 *
 *  Created on: 20 thg 12, 2023
 *      Author: DELL F89F
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"
 #include "softwareTimer.h"


# define MAX_BUFFER_SIZE 10

#define RST_CMD 10
#define OK_CMD 20
#define INIT_CMD 30

#define INIT 1
#define WAIT 2

extern uint8_t data_cmd;

uint8_t temp;
uint8_t buffer [ MAX_BUFFER_SIZE ];
uint8_t index_buffer;
uint8_t buffer_flag;

extern int uart_status;

void clear_buffer();
#endif /* INC_GLOBAL_H_ */

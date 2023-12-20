/*
 * global.c
 *
 *  Created on: 20 thg 12, 2023
 *      Author: DELL F89F
 */

#include "global.h"

uint8_t temp = 0;
uint8_t index_buffer = 0;
uint8_t buffer_flag = 0;

void clear_buffer(){
	for (int i = 0; i < MAX_BUFFER_SIZE; i++){
		buffer[i] = 0;
	}
	index_buffer = 0;
}

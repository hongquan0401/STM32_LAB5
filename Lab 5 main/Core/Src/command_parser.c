/*
 * command_parser.c
 *
 *  Created on: 20 thg 12, 2023
 *      Author: DELL F89F
 */
#include "command_parser.h"

void command_parser_fsm(){
	uint8_t letter = 0, status = 0;
	for (int i = 0; i < index_buffer; i++){
		if (status == 100) break;
		letter = buffer[i];
		switch (letter) {
			case 'R':
				if (status == 0) status = 1;
				else status = 100;
				break;
			case 'S':
				if(status == 1) status++;
				else status = 100;
				break;
			case 'T':
				if(status == 2) status++;
				else status = 100;
				break;
			case 'O':
				if (status == 0) status = 10;
				else status = 100;
				break;
			case 'K':
				if(status == 10) status*=2;
				else status = 100;
				break;
			default:
				status = 100;
				break;
		}
	}
	if (status == 3){
		data_cmd = RST_CMD;
	}
	if (status == 20){
		data_cmd = OK_CMD;
	}
	clear_buffer();
}


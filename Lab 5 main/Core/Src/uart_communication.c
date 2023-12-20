/*
 * uart_communication.c
 *
 *  Created on: Dec 20, 2023
 *      Author: DELL F89F
 */

#include "uart_communication.h"
uint16_t ADC_value;
void uart_communication_fsm(){
	int st = INIT;
	void* str;
	switch (st) {
		case INIT:
		    if (data_cmd == RST_CMD){
		        ADC_value = HAL_ADC_GetValue(&hadc1);
		        HAL_UART_Transmit(&huart2, (void*) str, sprintf(str,"\r!ADC=%d#\r",ADC_value), 50); // send ADC data
		        data_cmd = 0; // set =0 for change state to WAIT
		    }else{
		        st = WAIT;
		        setTimer1(300); //set timer 3s
		    }
			break;
		case WAIT:
		    while(data_cmd != OK_CMD)
		    if(timer1_flag == 1){
		        HAL_UART_Transmit(&huart2, (void*) str, sprintf(str,"\r!ADC=%d#\r",ADC_value), 50); // send ADC data
		        timer1_flag = 0;
		        setTimer1(300);
		    }
		    st = INIT;
		    data_cmd = 0;
			break;
		default:
			break;
	}
}

/*
 * get_distance.h
 *
 *  Created on: Nov 15, 2024
 *      Author: Roberto_Hernandez
 */

#ifndef SRC_GET_DISTANCE_H_
#define SRC_GET_DISTANCE_H_

typedef struct {
	GPIO_TypeDef* trig_port;
	uint16_t trigger_pin;
	GPIO_TypeDef* echo_port;
	uint16_t echo_pin;
	uint32_t distance;
	uint32_t start_time;
	uint32_t end_time;
} sensor;



#endif /* SRC_GET_DISTANCE_H_ */

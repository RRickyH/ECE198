#include "get_distance.h"

// prompts the ultrasonic sensor to get the distance by setting the trigger pin to HIGH for 10 millis
void get_distance( sensor* s_sensor ){
	// sets distance and counter values to zero to prevent previous values from being used
	s_sensor->distance = 0;
	s_sensor->start_time = 0;
	s_sensor->end_time = 0;

	HAL_GPIO_WritePin(s_sensor->trig_port, s_sensor->trigger_pin, GPIO_PIN_SET);
	HAL_Delay(1);
	HAL_GPIO_WritePin(s_sensor->trig_port, s_sensor->trigger_pin, GPIO_PIN_RESET);
	HAL_Delay(5);
	return;
}

// is called back when the echo pin changes value
void calc_distance( sensor* s_sensor ){
	if (s_sensor->start_time == 0){
		s_sensor->start_time = __HAL_TIM_GET_COUNTER(&htim2);
	} else {
		s_sensor->end_time = __HAL_TIM_GET_COUNTER(&htim2);

		uint32_t dt = s_sensor->end_time - s_sensor->start_time;
		s_sensor->distance = 172 * dt / 1000;
		__HAL_TIM_SET_COUNTER(&htim2, 0);
	}
}
#include <iostream>

int number_of_cars = 0;
int previous_sign_percentage = 0;
double current_distance = 0;
_Bool car_present = 0;
_Bool previously_car_present = 0;
double total_capacity = 4;

void update_sign(int percentage){

	//Resets all pins to make sure the incorrect one is off
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, GPIO_PIN_RESET);

	//Finds the correct one and activates the pin
			if(percentage == 25){
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);
	} else if (percentage == 50){
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET);
	} else if (percentage == 75){
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
	} else if (percentage == 100){
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, GPIO_PIN_SET);
	}
}


  /* USER CODE END 2 */
int main(){
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {

	  //Function retrieves and stores current distance of object in front of the sensor
	  current_distance = get_distance();

	  //If there is a car present within the specified range in cm, sets car_present to true
	  if(current_distance > 10 && current_distance < 200){
	 	car_present = 1;
	  } else {
		car_present = 0;
	  }

	  //Checks if there was a car the previous time it ran
	  if(previously_car_present == 1){
		  //If yes but there's no car now, add one to count and reset the previous car indicator
		  if(car_present == 0){
			  number_of_cars += 1;
			  previously_car_present = 0;
		  }
	  } else {
		  //If not, and there is now, set previous car to true
		  if(car_present == 1){
			  previously_car_present = 1;
		  }
	  }

	  //Check if the exit sensor detected a passing car, will run if true
	  // Write code here

	  //Calculates the percentage based on current cars and capacity
	  double current_percentage = 100.0*number_of_cars/total_capacity;

	  //Checks which sign LED to light up
	  	  	 if(current_percentage <= 25.0){
	  	  		 if(previous_sign_percentage != 25){
	  	  			update_sign(25);
	  	  			previous_sign_percentage = 25;
	  	  		 }
	  } else if (25.0 < current_percentage && current_percentage <= 50.0){
		  	  	 if(previous_sign_percentage != 50){
		  	  		update_sign(50);
		  	  		previous_sign_percentage = 50;
		  	  	 }
	  } else if (50.0 < current_percentage && current_percentage <= 75.0){
		  	  	 if(previous_sign_percentage != 75){
		  	  		update_sign(75);
		  		  	 previous_sign_percentage = 75;
		  		 }
	  } else if (75.0 < current_percentage){
		  	  	 if(previous_sign_percentage != 100){
		  	  		update_sign(100);
		  	  		 previous_sign_percentage = 100;
		  		 }
	  }

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
}
#include <stdio.h>
#include <stdint.h>

//Constants
#define DATA_POINTS_THIRTEEN            13
#define DATA_POINTS_TWENTYONE           21

//Local Variables
static uint8_t coefficient_array[DATA_POINTS_THIRTEEN] = {64,32,16,8,4,2,1};

//Local Functions
void coefficient_array_init(uint8_t (*ptr)[]);
//void coefficient_array_init_value(uint8_t ptr);

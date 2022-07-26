#include <stdio.h>
#include <stdint.h>

//Constants
#define DATA_POINTS                     13 //interchangable between 13 and 21

//Local Variables
static uint8_t coefficient_array[DATA_POINTS] = {64,32,16,8,4,2,1};
static uint32_t speed[DATA_POINTS] = {};
static uint8_t voltage_motor[DATA_POINTS] = {};
static uint8_t current_motor[DATA_POINTS] = {};


//Local Functions
void coefficient_array_init(uint8_t (*ptr)[]);
void all_array_init(void );
void all_array_deinit(uint32_t (*ptr)[] );


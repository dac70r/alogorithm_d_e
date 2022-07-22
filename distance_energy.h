#include <stdio.h>
#include <stdint.h>

//Constants
#define DATA_POINTS_THIRTEEN            13
#define DATA_POINTS_TWENTYONE           21

//
static uint8_t coefficient_array[DATA_POINTS_THIRTEEN] = {0,1,2,3};
//uint8_t coefficient_array_contructor(uint8_t* []);
/*
static uint8_t coefficient_matrix_a[13] = {1, 4, 2,            // Array for coefficient matrix of Simpson's Rule (calculate every 13 seconds)
                                         4, 2, 4, 
                                         2, 4, 2, 
                                         4, 2, 4, 1};

/*
static uint8_t coefficient_matrix_a[13] = {1, 4, 2,            // Array for coefficient matrix of Simpson's Rule (calculate every 13 seconds)
                                         4, 2, 4, 
                                         2, 4, 2, 
                                         4, 2, 4, 1};
*/

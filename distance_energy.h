#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

//Constants
#define DATA_POINTS                     13          //interchangable between 13 and 21
#define TIME_INTERVAL                   0.5         //change as necessary

//Local Variables
static uint8_t coefficient_array[DATA_POINTS] = {}; // this array is used to store the coefficient used in Simpson's rule
static uint32_t speed[DATA_POINTS] = {};            // this array is used to store speed values collected from MCU
static uint8_t voltage_motor[DATA_POINTS] = {};     // this array is used to store voltage values collected from MCU
static uint8_t current_motor[DATA_POINTS] = {};     // this array is used to store current values collected from MCU

static uint8_t (*ptr)[DATA_POINTS] = &coefficient_array;        // pointer to coefficient array 8bits
static uint32_t (*ptr32)[DATA_POINTS] = &speed;                 // pointer to speed array 32bits
static uint8_t (*ptrvm)[DATA_POINTS] = &voltage_motor;          // pointer to voltage motor array 8bits
static uint8_t (*ptrcm)[DATA_POINTS] = &current_motor;          // pointer to current motor array 8bits

//Local Functions

void coefficient_array_init(uint8_t (*ptr)[]);
void all_array_deinit(uint32_t (*ptr32)[] ,uint8_t (*ptrcm)[] ,uint8_t (*ptrvm)[]);
void all_array_init(void );
uint32_t compute_energy_consumption(uint8_t (*ptr)[] ,uint8_t (*ptrcm)[] ,uint8_t(*ptrvm)[]);
//void all(void);
//void all_pointer_init(void );

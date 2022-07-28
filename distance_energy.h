#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

//Constants
#define DATA_POINTS                     13          //interchangable between 13 and 21
#define TIME_INTERVAL                   0.5         //change as necessary

//Local Variables
extern uint8_t coefficient_array[DATA_POINTS]; // this array is used to store the coefficient used in Simpson's rule
extern uint32_t speed[DATA_POINTS];            // this array is used to store speed values collected from MCU
extern uint8_t voltage_motor[DATA_POINTS];     // this array is used to store voltage values collected from MCU
extern uint8_t current_motor[DATA_POINTS];     // this array is used to store current values collected from MCU

extern uint8_t (*ptr)[DATA_POINTS];            // pointer to coefficient array 8bits
extern uint32_t (*ptr32)[DATA_POINTS];         // pointer to speed array 32bits
extern uint8_t (*ptrvm)[DATA_POINTS];          // pointer to voltage motor array 8bits
extern uint8_t (*ptrcm)[DATA_POINTS];          // pointer to current motor array 8bits

//Local Functions
void coefficient_array_init();
void all_array_deinit();
void all_array_init();
void all_all_array_init ();
void collect_mcu_data (uint32_t (*rpm_ptr)[] ,uint8_t (*cm_ptrcm)[] ,uint8_t(*vm_ptrvm)[]);
uint32_t compute_energy_consumption();

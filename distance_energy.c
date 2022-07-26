/*
 * battery.c
 *
 *  Created on: 21 Jul 2022
 *      Author: Dennis
 */
/******************************************************************************
@file  battery.c

@brief This file contains the Code to send the battery status to phone via BLE protocol


*****************************************************************************/

/*********************************************************************
* INCLUDES
*/
#include <stdlib.h>
#include <stdint.h>
#include "distance_energy.h"
/*********************************************************************
* LOCAL VARIABLES
*/

/*********************************************************************
* LOCAL FUNCTIONS
*/
/*
 * @fn      coefficient_array_init
 *
 * @brief   It is used to initialize the coefficient_array used in Simpson's rule
 *
 * @param   battery_reading             A floating point value of the battery
 *
 * @return  ((battery_reading-30))* 100 /(42-30)        an integer value of the battery percentage
 * 
*/

void coefficient_array_init(uint8_t (*ptr)[]){ //change data points if necessary

    for(uint8_t x=0; x<DATA_POINTS; x++){

        if(x==0 || x == DATA_POINTS-1){
            //*(coefficient_array+x) = 1;
            *((*ptr)+ x) = 1;
        }
        
        else
            {if(x%2==1){*((*ptr)+ x)=4;}else{*((*ptr)+ x)=2;}}
    }

}

/*
 * @fn      all_array_init
 *
 * @brief   It is used to initialize all arrays to zero arrays
 *
 * @param   none             
 *
 * @return  none
 * 
*/

void all_array_init(void ){

    for(uint8_t x=0; x<DATA_POINTS; x++){
        speed[x] = 0; 
        current_motor[x] = 0;
        voltage_motor[x] = 0; 
    }
}

/*
 * @fn      all_array_deinit
 *
 * @brief   It is used to deinitialize all arrays when the number of data points reach maximum
 *
 * @param   none             
 *
 * @return  none
 * 
*/

void all_array_deinit(uint32_t (*ptr)[] ){

    for(uint8_t x=0; x<DATA_POINTS; x++){
        if(x == 0){
            *(*(ptr)) = *(*(ptr)+DATA_POINTS-1); 
            current_motor[0] = current_motor[DATA_POINTS-1];
            voltage_motor[0] = voltage_motor[DATA_POINTS-1];
        }
        else
            {
                *(*(ptr)+x) = 0; 
                current_motor[x] = 0;
                voltage_motor[x] = 0; 
        }

    }
}   



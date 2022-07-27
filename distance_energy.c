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
 *          All "first" elements are updated with the "last" element of the array and the rest are
 *          updated with zeros. eg. speed[0] = speed[12], speed[1] = 0, speed[2] = 0......
 *
 * @param   none             
 *
 * @return  none
 * 
*/

void all_array_deinit(uint32_t (*ptr32)[] ,uint8_t (*ptrcm)[] ,uint8_t(*ptrvm)[]){

    for(uint8_t x=0; x<DATA_POINTS; x++){
        if(x == 0){
            *(*(ptr32)) = *(*(ptr32)+DATA_POINTS-1); 
            *(*(ptrvm)) = *(*(ptrvm)+DATA_POINTS-1); 
            *(*(ptrcm)) = *(*(ptrcm)+DATA_POINTS-1); 
        }
        else
            {
                *(*(ptr32)+x) = 0; 
                *(*(ptrvm)+x) = 0; 
                *(*(ptrcm)+x) = 0; 
        }

    }
}

/*
 * @fn      compute_energy_consumption
 *
 * @brief   This function calculates the average energy consumption of the e_scooter 
 *          over a period using Simpson's Rule
 *
 * @param   none             
 *
 * @return  uint32_t 
 * 
*/

uint32_t compute_energy_consumption(uint8_t (*ptr)[] ,uint8_t (*ptrcm)[] ,uint8_t(*ptrvm)[]){

    uint32_t sum = 0;
    for(uint8_t x=0; x<DATA_POINTS; x++){
        
        sum = sum + (*((*ptr)+ x)) * (*((*ptrcm)+ x)) * (*((*ptrvm)+ x));

    }
    return sum;
}






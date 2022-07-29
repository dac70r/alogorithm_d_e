/*
 * distance_energy.c
 *
 *  Created on: 21 Jul 2022
 *      Author: Dennis
 */
/******************************************************************************
@file  distance_energy.c

@brief This file contains the Code to calculate the distance travelled and energy consumed by the e-scooter
*****************************************************************************/

/*********************************************************************
* INCLUDES
*/
#include "distance_energy.h"
/*********************************************************************
* LOCAL VARIABLES
*/
uint8_t coefficient_array[DATA_POINTS] = {1,2,3};       //depending on the size of the array, could increase up to 21 elements
uint32_t rpm[DATA_POINTS] = {4,5,6};                    //revolutions per minute data collected every time interval
uint8_t current_motor[DATA_POINTS] = {7,8,9};           //current_motor data collected every time interval       
uint8_t voltage_motor[DATA_POINTS] = {10,11,12};        //voltage_motor data collected every time interval 

//Pointers to various arrays 
uint8_t (*ptr)[DATA_POINTS] = &coefficient_array;
uint32_t (*ptr32)[DATA_POINTS] = &rpm;                 
uint8_t (*ptrvm)[DATA_POINTS] = &voltage_motor;
uint8_t (*ptrcm)[DATA_POINTS] = &current_motor; 

//Other Variables
uint16_t energy_consumed = 0;
uint8_t status = 0;
time_t t;


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

void coefficient_array_init(){ //change data points if necessary

    for(uint8_t x=0; x<DATA_POINTS; x++){

        if(x==0 || x == DATA_POINTS-1){           
            *((*ptr)+ x) = 1;
        }
        
        else
            {if(x%2==1){*((*ptr)+ x)=4;}else{*((*ptr)+ x)=2;}}
    }

}

/*
 * @fn      all_array_deinit
 *
 * @brief   It is used to deinitialize all arrays when the number of data points reach maximum (13/21)
 *          All "first" elements are updated with the "last" element of the array and the rest are
 *          updated with zeros. eg. speed[0] = speed[12], speed[1] = 0, speed[2] = 0......
 *          Before deinitiliazation, the average energy consumption for that interval is computed and 
 *          stored in a global variable named energy_consumed. 
 *
 * @param   none          
 *
 * @return  none
 * 
*/

void all_array_deinit(){
    energy_consumed = compute_energy_consumption();
    printf("Average energy consumption in this interval is %d joules\n",compute_energy_consumption());
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
 * @return  energy consumption value (unit joules) in type: uint32_t 
 * 
*/

uint32_t compute_energy_consumption(){

    uint32_t energy_consumption = 0;
    float mean;

    for(uint8_t x=0; x<DATA_POINTS; x++){
        
        energy_consumption = energy_consumption + ((*((*ptr)+ x)) * (*((*ptrcm)+ x)) * (*((*ptrvm)+ x)));

    }
    mean = (float)energy_consumption/3*TIME_INTERVAL;
    energy_consumption = (uint32_t)mean;
    return energy_consumption;
}


void print_log(){
    printf("------------------------------------------------NEXT----------------------------------------------------\n");
    for(uint8_t x=0; x<DATA_POINTS; x++){
            printf(" %d\t",*((*ptr)+ x));     
    }

    printf("coefficient array\n");

    for(uint8_t x=0; x<DATA_POINTS; x++){
            printf(" %d\t",*((*ptr32)+ x));     
    }

    printf("speed array\n");

    for(uint8_t x=0; x<DATA_POINTS; x++){
            printf(" %d\t",*((*ptrcm)+ x));     
    }

    printf("current_motor array\n");

    for(uint8_t x=0; x<DATA_POINTS; x++){
            printf(" %d\t",*((*ptrvm)+ x));     
    }

    printf("voltage_motor array\n");

}

void program(){
    uint8_t x = 0;  
    /* Intializes random number generator */
    srand((unsigned) time(&t));
    if(status == 1){x = 1;}
    while(x<DATA_POINTS){
            
            *((*ptrcm)+ x) = rand()%50;
            *((*ptr32)+ x) = rand()%50;
            *((*ptrvm)+ x) = rand()%50; 

            if( x == DATA_POINTS-1){
                    status = 1;
                    break;
            }
        x++;
    }
}

//////////////////Unused functions/////////////////////////////
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
        rpm[x] = 0; 
        current_motor[x] = 0;
        voltage_motor[x] = 0; 
    }
}

/*
 * @fn      all_all_array_init

 * @brief   This function calls coefficient_array_init and all_array_init functions which initializes the coefficient array and other declared arrays.
            Use this function at the start of the program. 
 *
 * @param   none         
 *
 * @return  none
 * 
*/

void all_all_array_init(){

    coefficient_array_init();
    all_array_init();
    
}

/*
 * @fn      collect_mcu_data

 * @brief   This function collects the voltage, rpm, current values from the MCU and append it into the 
 *          arrays declared. Replace ptr with actual data from MCU when implementing this function in CCS.
 *
 * @param   ptr, ptrcm, ptrvm           pointer to coefficient array, voltage_motor and current_motor array            
 *
 * @return  none 
 * 
*/

void collect_mcu_data (uint32_t (*rpm_ptr)[] ,uint8_t (*cm_ptrcm)[] ,uint8_t(*vm_ptrvm)[]){

    uint8_t x = 0;
    for(x; x<DATA_POINTS; x++){
        
        //printf("%f\n",((*((*rpm_ptr)+ x))*RADIUS*2*M_PI/60)*3600/1000);
        *((*ptr32)+ x) = (uint32_t)(((*((*rpm_ptr)+ x))*RADIUS*2*M_PI/60)*3600/1000); //radius * 2 * pi / 60;
        *((*ptrcm)+ x) = *((*cm_ptrcm)+ x);
        *((*ptrvm)+ x) = *((*vm_ptrvm)+ x);

    }
    energy_consumed = compute_energy_consumption();
}




#include "distance_energy.h"
// uint8_t size is 1 byte (1-255)

int main(){
 
    all_array_init();
    coefficient_array_init(ptr);

    //to simulate the reception of data from MCU
    uint32_t data1[DATA_POINTS] = {1,1,1,1,1,1,1,1,1,1,1,1,1};
    uint8_t data2[DATA_POINTS] = {2,2,2,2,2,2,2,2,2,2,2,2,2};
    uint8_t data3[DATA_POINTS] = {3,3,3,3,3,3,3,3,3,3,3,3,3};
    
    collect_mcu_data(&data1, &data2, &data3, ptr32, ptrcm, ptrvm);
    //all_array_deinit(ptr32, ptrcm, ptrvm);

    printf("Energy consumption is : %d joules\n",compute_energy_consumption(ptr,ptrcm,ptrvm));
    return 0;
}














/*
    for(uint8_t x=0; x<DATA_POINTS; x++){
        speed[x] = data1[x];
        current_motor[x] = data2[x];
        voltage_motor[x] = data3[x];    
    }

    for(uint8_t x=0; x<DATA_POINTS; x++){
            printf("%d\n",*((*ptr)+ x));     
    }

    printf("next-----------------------\n"); 

    for(uint8_t x=0; x<DATA_POINTS; x++){
        printf("%d\n",speed[x]);
        //printf("%d\n",current_motor[x]); 
        //printf("%d\n",voltage_motor[x]);    
    }
    printf("next-----------------------\n");
    for(uint8_t x=0; x<DATA_POINTS; x++){
        //printf("%d\n",speed[x]);
        printf("%d\n",current_motor[x]); 
        //printf("%d\n",voltage_motor[x]);    
    }
    printf("next-----------------------\n");
    for(uint8_t x=0; x<DATA_POINTS; x++){
        //printf("%d\n",speed[x]);
        //printf("%d\n",current_motor[x]); 
        printf("%d\n",voltage_motor[x]);    
    }

*/



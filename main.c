#include "distance_energy.h"
// uint8_t size is 1 byte (1-255)

int main(){

    
    all_array_init();
    coefficient_array_init(ptr);

    //to simulate the reception of data from MCU
    uint8_t dennis[DATA_POINTS] = {1,1,1,1,1};
    for(uint8_t x=0; x<DATA_POINTS; x++){
        speed[x] = dennis[x];
        current_motor[x] = dennis[x];
        voltage_motor[x] = dennis[x];    
    }


    for(uint8_t x=0; x<DATA_POINTS; x++){
        printf("%d\n",*((*ptr)+ x));     
    }

    

    //all_array_deinit(ptr32, ptrcm, ptrvm);

    printf("Dennis: %d",compute_energy_consumption(ptr,ptrcm,ptrvm));

    return 0;
}

/*
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



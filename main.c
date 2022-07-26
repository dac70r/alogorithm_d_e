#include "distance_energy.h"
#include <stdio.h>
// uint8_t size is 1 byte (1-255)

int main(){
    uint8_t dennis[DATA_POINTS] = {1,2,3,4,5,6,7,8,9,10,11,12,13};

    uint8_t (*ptr)[DATA_POINTS] = NULL;
    uint32_t (*ptr32)[DATA_POINTS] = NULL;
    ptr = &coefficient_array;

    coefficient_array_init(ptr);

    for(uint8_t x=0; x<DATA_POINTS; x++){
        printf("%d\n",*((*ptr)+ x));     
    }

    printf("next-----------------------\n"); 
    ptr32 = &speed;

    for(uint8_t x=0; x<DATA_POINTS; x++){
        speed[x] = dennis[x];    
    }

    all_array_deinit(ptr32);

    for(uint8_t x=0; x<DATA_POINTS; x++){
        printf("%d",speed[x]);   
    }
    

    return 0;
}



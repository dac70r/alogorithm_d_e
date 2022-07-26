#include "distance_energy.h"
#include <stdio.h>
// uint8_t size is 1 byte (1-255)

int main(){

    uint8_t (*ptr)[DATA_POINTS_THIRTEEN] = NULL;
    ptr = &coefficient_array;

    coefficient_array_init(ptr);

    for(uint8_t x=0; x<DATA_POINTS_THIRTEEN; x++){
        printf("%d\n",*((*ptr)+ x)); 
    }


    return 0;
}


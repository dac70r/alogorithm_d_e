#include "distance_energy.h"
// uint8_t size is 1 byte (1-255)

int main(){

     for(uint8_t x=0; x<DATA_POINTS; x++){
            printf("%d\n",*((*ptr)+ x));     
    }

    all_all_array_init();

    for(uint8_t x=0; x<DATA_POINTS; x++){
            printf("%d\n",*((*ptr)+ x));     
    }

    printf("next----------------------\n");

    for(uint8_t x=0; x<DATA_POINTS; x++){
            printf("%d\n",*((*ptr32)+ x));     
    }

    printf("next----------------------\n");

    for(uint8_t x=0; x<DATA_POINTS; x++){
            printf("%d\n",*((*ptrvm)+ x));     
    }

    printf("next----------------------\n");

    for(uint8_t x=0; x<DATA_POINTS; x++){
            printf("%d\n",*((*ptrcm)+ x));     
    }

    all_array_deinit();

    printf("next----------------------\n");

    for(uint8_t x=0; x<DATA_POINTS; x++){
            printf("%d\n",*((*ptr32)+ x));     
    }

    printf("next----------------------\n");

    for(uint8_t x=0; x<DATA_POINTS; x++){
            printf("%d\n",*((*ptrvm)+ x));     
    }

    printf("next----------------------\n");

    for(uint8_t x=0; x<DATA_POINTS; x++){
            printf("%d\n",*((*ptrcm)+ x));     
    }

    //to simulate the reception of data from MCU
    uint32_t data1[DATA_POINTS] = {1,1,1,1,1,1,1,1,1,1,1,1,1};
    uint8_t data2[DATA_POINTS] = {2,2,2,2,2,2,2,2,2,2,2,2,2};
    uint8_t data3[DATA_POINTS] = {3,3,3,3,3,3,3,3,3,3,3,3,3};
    
    collect_mcu_data(&data1, &data2, &data3);

    printf("next----------------------\n");

    for(uint8_t x=0; x<DATA_POINTS; x++){
            printf("%d\n",*((*ptr32)+ x));     
    }

    printf("next----------------------\n");

    for(uint8_t x=0; x<DATA_POINTS; x++){
            printf("%d\n",*((*ptrcm)+ x));     
    }

    printf("next----------------------\n");

    for(uint8_t x=0; x<DATA_POINTS; x++){
            printf("%d\n",*((*ptrvm)+ x));     
    }
    //all_array_deinit(ptr32, ptrcm, ptrvm);
    //printf("Power consumption is: %d\n",compute_energy_consumption());
    printf("Energy consumption is : %d joules\n",compute_energy_consumption());
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



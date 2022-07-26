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

    /*
    static uint8_t coefficient_array[DATA_POINTS_THIRTEEN] = {64,32,16,8,4,2,1};
    //p is a integer pointer that points to the first element in the coefficient_array
    uint8_t *p = coefficient_array;  

    //ptr is an integer array pointer that points to an array     
    uint8_t (*ptr)[DATA_POINTS_THIRTEEN] = NULL;

    //ptr is pointing to the base address (address of 1st element) of array
    ptr = &coefficient_array;

    //printing the elements in an array 
    //*p = value, p = address of value, ptr=array, *p = *array = base address of array
    //printf("0x%x = %d\n",*(*(ptr)),*p);
    printf("%d\n",*p);
    coefficient_array_init(p);
    coefficient_array_init_value(coefficient_array[0]);

    //printf("0x%x = %d\n",*(*(ptr)),*p);
    printf("%d\n",*p);
    printf("%d\n",(*(*ptr)));
    */

    //coefficient_array_contructor(ptr);
    //printf("%d\n",**ptr);

    //for(int x=0; x<DATA_POINTS_THIRTEEN; x++){printf("%d\n",coefficient_array[x]);}

#include "distance_energy.h"

// uint8_t size is 1 byte (1-255)

int main(){

    uint8_t array[13] = {0,1,2,3,4,5,6};
    int x = 0;
    printf("Size of x is: %d\n", sizeof(x));
    printf("Size of x is: %d\n", sizeof(array[0]));
    printf("Size of x is: %d\n", sizeof(array));

    return 0;
}
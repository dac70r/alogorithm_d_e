#include "distance_energy.h"

// uint8_t size is 1 byte (1-255)

int main(){

    //uint8_t (*ptr)[DATA_POINTS_THIRTEEN] = &coefficient_array;
    //uint8_t coefficient_array_contructor(uint8_t* coefficient_array[]){

    for(int x=0; x<DATA_POINTS_THIRTEEN; x++){
        if(x==0 || x == DATA_POINTS_THIRTEEN-1){
            //*(coefficient_array+x) = 1;
            coefficient_array[x] = 1;
        }
        
        else
            {if(x%2==1){coefficient_array[x]=4;}else{coefficient_array[x]=2;}}
        printf("%d\n",coefficient_array[x]); 
    }


    return 0;
}

    //coefficient_array_contructor(ptr);
    //printf("%d\n",**ptr);

    //for(int x=0; x<DATA_POINTS_THIRTEEN; x++){printf("%d\n",coefficient_array[x]);}

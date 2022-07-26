#include "distance_energy.h"

//Constants
//Functions
void coefficient_array_init(uint8_t (*ptr)[]){

    for(uint8_t x=0; x<DATA_POINTS_THIRTEEN; x++){
        if(x==0 || x == DATA_POINTS_THIRTEEN-1){
            //*(coefficient_array+x) = 1;
            *((*ptr)+ x) = 1;
        }
        
        else
            {if(x%2==1){*((*ptr)+ x)=4;}else{*((*ptr)+ x)=2;}}
        //printf("%d\n",*((*ptr)+ x)); 
    }

}



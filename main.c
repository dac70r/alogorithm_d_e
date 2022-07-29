#include "distance_energy.h"
// uint8_t size is 1 byte (1-255)

int main(){

        //verify the array contents
        print_log();

        //initialize the coefficient_array
        coefficient_array_init();

        //simulate adding data into array
        program();

        //verify the array contents
        print_log();

        //deinitializing array
        all_array_deinit();

        //verify the array contents
        print_log();

        //simulate adding data into array
        program();

        //verify the array contents
        print_log();

        //deinitializing array
        all_array_deinit();

        //verify the array contents
        print_log();

        //simulate adding data into array
        program();

        //verify the array contents
        print_log();

        //deinitializing array
        all_array_deinit();

        //verify the array contents
        print_log();
        
              
































    

    return 0;
}

/*
        
        printf("Printf initial values for all arrays\n");
        print_log();
        all_all_array_init();

    //to simulate the reception of data from MCU
    uint32_t data1[DATA_POINTS] = {666,654,623,642,635,612,633,655,666,661,662,665,644};
    uint8_t data2[DATA_POINTS] = {42,42,42,41,41,40,40,40,40,39,40,40,39};
    uint8_t data3[DATA_POINTS] = {13,13,13,12,12,13,12,12,11,12,12,11,12};
    
        collect_mcu_data(&data1, &data2, &data3);
        printf("Values for all arrays after collecting data from MCU----1\n");
        print_log();
        printf("Energy consumption is : %d joules\n",energy_consumed);

        all_all_array_init();
        printf("Values for all arrays after deinitializing the arrays----1\n");
        print_log();


        printf("New data coming in......");
        //to simulate the reception of data from MCU
        uint32_t data11[DATA_POINTS] = {456,454,399,445,388,335,363,389,400,345,378,365,355};
        uint8_t data21[DATA_POINTS] = {4,4,3,3,4,3,4,3,3,3,4,4,4};
        uint8_t data31[DATA_POINTS] = {23,23,23,22,24,23,22,24,22,20,21,23,23};

        collect_mcu_data(&data11, &data21, &data31);
        printf("Values for all arrays after collecting data from MCU----2\n");
        print_log();
        printf("Energy consumption is : %d joules\n",energy_consumed);

        all_all_array_init();
        printf("Values for all arrays after deinitializing the arrays----2\n");
        print_log();

*/













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



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "print_generals.h"


void take_data(char **argv){
    void *data_p = NULL;
    size_t size;
    if (strcmp(argv[1], "int") == 0){
        size = sizeof(int);
        data_p = malloc(size);
        *(int*)data_p = atoi(argv[2]); 
    } else if (strcmp(argv[1], "float") == 0){
        size = sizeof(float);
        data_p = malloc(size);
        *(float*)data_p = atof(argv[2]);
        print_float_informations((float*) data_p, size);
    } else if (strcmp(argv[1], "char") == 0){
        size = sizeof(char);
        data_p = malloc(size);
        *(char*)data_p = *(argv[2]);
    } else if (strcmp(argv[1], "string") == 0){
        size = strlen(argv[2]) + 1;
        data_p = malloc(size + 1);
        strcpy((char*)data_p, argv[2]);
    } else if (strcmp(argv[1], "arr") == 0){
        if (strcmp(argv[2], "int") == 0) size = sizeof(int);
        else if (strcmp(argv[2], "float") == 0) size = sizeof(float);
        else if (strcmp(argv[2], "char") == 0) size = sizeof(char);
        else if (strcmp(argv[2], "string") == 0) size = sizeof(data_p);
        int num_of_elements = atoi(argv[3]);
        data_p = malloc(size * num_of_elements);
        for (int i = 0; i < num_of_elements; i++){
            if (strcmp(argv[2], "int") == 0){
                ((int*)data_p)[i] = atoi(argv[4 + i]);
            } else if (strcmp(argv[2], "float") == 0){
                ((float*)data_p)[i] = atof(argv[4 + i]);
            } else if (strcmp(argv[2], "char") == 0){
                ((char*)data_p)[i] = *(argv[4 + i]);
            } else if (strcmp(argv[2], "string") == 0){
                ((char**)data_p)[i] = malloc(size);
                strcpy(((char **)data_p)[i], argv[4 + i]);
            }
        }
        print_bits_arr(data_p, size, num_of_elements);
        print_arr_addresses(data_p, num_of_elements, size);
        return;
    }


    print_bits(data_p, size);
    print_hex(data_p, size);
    print_addresses(data_p, size);
}

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
        size = strlen(argv[2]);
        data_p = malloc(size) + 1;
        strcpy((char*)data_p, argv[2]);
    }
    print_bits(data_p, size);
    print_hex(data_p, size);
    print_addresses(data_p, size);
}

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "take_data.h"

void take_data(char **argv);
void print_bits(void *data, size_t size);
void print_hex(void *data, size_t size);
void print_addresses(void *data, size_t size);
void print_float_informations(float *data, size_t size);

int main(int argc, char **argv){
    if (strcmp(argv[1], "arr") != 0 && argc < 3){
        printf("not valid request\n");
    }
    if (strcmp(argv[1], "int") != 0 && strcmp(argv[1], "float") != 0 && strcmp(argv[1], "char") != 0 && strcmp(argv[1], "string") != 0 && 
    (strcmp(argv[1], "arr") != 0 && (strcmp(argv[2], "int") != 0 && strcmp(argv[2], "float") != 0 && strcmp(argv[2], "char") != 0 && strcmp(argv[2], "string") != 0))){
        printf("invalid type\n");
        exit(0);
    }
    take_data(argv);
}



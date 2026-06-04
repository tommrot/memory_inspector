#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void *analyze(char **argv);
void print_bits(void *value_ptr, size_t size);
void print_hex(void *value_ptr, size_t size);
void print_address(void *value_ptr, size_t size);

int main(int argc, char **argv){
    if (strcmp(argv[1], "int") != 0 && strcmp(argv[1], "float") != 0 && strcmp(argv[1], "char") != 0 && strcmp(argv[1], "string") != 0){
        printf("invalid type");
        exit(0);
    }
    char *p = analyze(argv);  
}


void *analyze(char **argv){
    int i;
    float f;
    char c;
    char *string;
    void *value_ptr;
    size_t size;
    if (strcmp(argv[1], "int") == 0){
        size = sizeof(int);
        value_ptr = malloc(size);
        *(int*)(value_ptr) = atoi(argv[2]);  //casting is valid only for expression, it says to compiler to threat it as pointer to int, and with external * we deferenciate it
    } else if (strcmp(argv[1], "float") == 0){
        size = sizeof(float);
        value_ptr = malloc(sizeof(float));
        *(float*)(value_ptr) = atof(argv[1]);
    } else if (strcmp(argv[1], "char") == 0){
        size = sizeof(char);
        value_ptr = malloc(sizeof(char));
        *(char*)(value_ptr) = *argv[2];
    }
    print_bits(value_ptr, size);
    print_hex(value_ptr, size);
    print_address(value_ptr, size);
    return value_ptr;
}


void print_bits(void *value_ptr, size_t size){
    printf("in binary:\n");
    char *p = (unsigned char*) value_ptr;
    for (int i = size - 1; i >= 0; i--){
        for (int j = 7; j >= 0; j--){
            int bit = (p[i] >> j) & 1;
            printf("%d", bit);
        }
        printf("\n");
    }
    printf("\n");
}

void print_hex(void *value_ptr, size_t size){
    printf("in hex:\n");
    char *p = (unsigned char*) value_ptr;
    printf("0x");
    for (int i = size - 1; i >= 0; i--){
        printf("%02x", p[i]);
    }
    printf("\n\n");
}


void print_address(void *value_ptr, size_t size){
    printf("address of data: \n");
    char *p = (char *)value_ptr;
    for (int i = 0; i < size; i++){
        printf("%p\n", (void*)(&p[i]));
    }
}

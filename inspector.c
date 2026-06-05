#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void take_data(char **argv);
void print_bits(void *data, size_t size);
void print_hex(void *data, size_t size);
void print_addresses(void *data, size_t size);
void print_float_informations(float *data, size_t size);

int main(int argc, char **argv){
    if (strcmp(argv[1], "int") != 0 && strcmp(argv[1], "float") != 0 && strcmp(argv[1], "char") != 0 && strcmp(argv[1], "string") != 0){
        printf("invalid type\n");
        exit(0);
    }
    take_data(argv);
}


void take_data(char **argv){
    void *data_p;
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


void print_bits(void *data, size_t size){
    printf("bit representation:\n");
    char *p = (char*) data;
    for (int i = size - 1; i >= 0; i--){
        for (int j = 7; j >= 0; j--){
            int bit = (p[i] >> j) & 1; 
            printf("%d", bit);
        }
        printf("\n");
    }
    printf("\n");
}


void print_hex(void *data, size_t size){
    char *p = (char*) data;
    printf("hex representation:\n");
    for (int i = size - 1; i >= 0; i--){
        printf("%02x\n", p[i]);
    }
    printf("\n");
}


void print_addresses(void *data, size_t size){
    char *p = (char*) data;
    printf("addresses:\n");
    for (int i = 0; i < size; i++){
        printf("%p\n", (void*)&p[i]); // or (void*)(p + 1). we use (void*) because %p is pointer placeholder and it expects generic pointer
    }
    printf("\n");
}


void print_float_informations(float *data, size_t size){
    char *p = (char *) data;
    for (int i = size - 1; i >= 0; i--){
        if (i == size - 1){
            for (int j = 7; j >= 0; j--){
                int bit = (p[i] >> j) & 1;
                if (j == 7){
                    printf("sign: %d\n\nexponent:\n", bit);
                } else {
                    printf("%d", bit);
                }
            }
        } else if (i == size - 2){
            for (int j = 7; j >= 0; j--){
                int bit = (p[i] >> j) & 1;
                if (j == 7){
                    printf("%d\n\nmantix:\n", bit);
                } else {
                    printf("%d", bit);
                }
            }
        } else {
            for (int j = 7; j >= 0; j--){
                int bit = (p[i] >> j) & 1;
                printf("%d", bit);
            }
        }
    }
    printf("\n\n");
}
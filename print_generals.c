#include <stdlib.h>
#include <stdio.h>

void print_bits(void *data, size_t size){
    printf("bit representation:\n");
    char *p = (char*) data;
    for (int i = (int) size - 1; i >= 0; i--){
        for (int j = 7; j >= 0; j--){
            int bit = (p[i] >> j) & 1; 
            printf("%d", bit);
        }
        printf("\n");
    }
    printf("\n");
}

void print_bits_arr(void *arr, size_t size, int num_el){
    char *p = (char *) arr;
    for (int i = 0; i < num_el; i++){
        for (int j = (int) size - 1; j >= 0; j--){
            for (int k = 7; k >= 0; k--){
                int bit = (p[i * size + j] >> k) & 1;
                printf("%d", bit);
            }
            printf(" ");
        }
        printf("\n");
    }
}


void print_hex(void *data, size_t size){
    char *p = (char*) data;
    printf("hex representation:\n");
    for (int i = (int) size - 1; i >= 0; i--){
        printf("%02x\n", p[i]);
    }
    printf("\n");
}


void print_addresses(void *data, size_t size){
    char *p = (char*) data;
    printf("addresses:\n");
    for (int i = 0; i < (int)size; i++){
        printf("%p\n", (void*)&p[i]); // or (void*)(p + 1). we use (void*) because %p is pointer placeholder and it expects generic pointer
    }
    printf("\n");
}

void print_float_informations(float *data, size_t size){
    char *p = (char *) data;
    for (int i = (int)size - 1; i >= 0; i--){
        if (i == (int)size - 1){
            for (int j = 7; j >= 0; j--){
                int bit = (p[i] >> j) & 1;
                if (j == 7){
                    printf("sign: %d\n\nexponent:\n", bit);
                } else {
                    printf("%d", bit);
                }
            }
        } else if (i == (int)size - 2){
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


void print_arr_addresses(void *arr, int len, size_t element_size){
    char *p = arr;
    for (int i = 0; i < len * (int)element_size; i++){
        printf("%p ", (void*)(p + i));
    }
    printf("\n");
}

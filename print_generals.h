#ifndef PRINT_GENERALS_H
#define PRINT_GENERALS_H

#include <stdio.h>
#include <stdlib.h>

void print_bits(void *data, size_t size);
void print_hex(void *data, size_t size);
void print_addresses(void *data, size_t size);
void print_float_informations(float *data, size_t size);
void print_arr_addresses(void *arr, int len, size_t element_size);
void print_bits_arr(void *arr, size_t size, int num_el);

#endif
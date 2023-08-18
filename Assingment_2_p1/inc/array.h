#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>
#include <ctype.h> 
#include <string.h>

int *initialize_array(int size);

void print_array(int *array, int size);

void get_array_size(int *size);

void get_array_data(int *array, int size);

float calculate_average_value(int *array, int size);
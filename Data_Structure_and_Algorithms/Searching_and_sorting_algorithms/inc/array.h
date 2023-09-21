#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_MIN 0
#define ARRAY_MAX 50

void print_array(int *array, int size);

void get_array_size(int *size);

void get_array_data(int *array, int size);

float calculate_average_value(int *array, int size);

int count_elements_less_than_average(int *array, int size, float average);

int count_elements_more_than_average(int *array, int size, float average);

void move_elements_array(int *array, int size);

void free_array(int *array);

#endif
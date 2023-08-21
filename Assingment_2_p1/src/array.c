#include "array.h"

#define SWAP(x, y) \
  do { \
    int tmp = (x); \
    (x) = (y); \
    (y) = tmp; } \
  while (0)

#define ARRAY_MIN 0
#define ARRAY_MAX 50

static int clean_stdin()
{
    while (getchar() != '\n');
    return 1;
}

static int get_input_size() 
{
    float input;

    while ((scanf("%f", &input) != 1 || input < ARRAY_MIN || input > ARRAY_MAX || input - (int)input != 0) && clean_stdin()) {
        printf("\n*Warning:Failed! Please enter an interger between 0 and 50.\nEnter again:  ");
    }

    return (int)input;
}

static int get_input_int() 
{
    float input;

    while ((scanf("%f", &input) != 1 || input - (int)input != 0) && clean_stdin()) {
        printf("\n*Warning:Failed! Please enter an interger.\nEnter again:  ");
    }

    return (int)input;
}

void get_array_size(int *size)
{
    *size = get_input_size();
}

int *initialize_array(int size)
{
    return malloc(size * sizeof(int));
}

void print_array(int *array, int size)
{
    for (int i = 0; i < size; i++) {
        printf("%i ", array[i]);
    }
    printf("\n");
}

void get_array_data(int *array, int size)
{
    for (int i = 0; i < size; i++) {
        printf("Enter element %d of the array: ", i);
        array[i] = get_input_int();
    }
    printf("\n");
}

float calculate_average_value(int *array, int size)
{
    float average = 0;
    int array_index = 0;

    for (array_index; array_index < size; array_index++) {
        average += array[array_index];
    }

    if (average == 0)
    {
        return 0;
    }
    return average/size;
}

int count_elements_less_than_average(int *array, int size, float average)
{
    int count = 0;
    int array_index = 0;

    for (array_index; array_index < size; array_index++) {
        if (array[array_index] < average) {
            count++;
        }
    }

    return count;
}

int count_elements_more_than_average(int *array, int size, float average)
{
    int count = 0;
    int array_index = 0;

    for (array_index; array_index < size; array_index++) {
        if (array[array_index] > average) {
            count++;
        }
    }

    return count;
}

void move_elements_array(int *array, int size)
{
    int left_index = 0;
    int right_index = size - 1;

    while (left_index < right_index) {
        while (array[left_index] % 2 != 0 && left_index < right_index) {
            left_index++;            
        }
        while (array[right_index] % 2 == 0 && left_index < right_index) {
            right_index--;
        }

        if (left_index < right_index) {
            SWAP(array[left_index], array[right_index]);
        } 
    }
}

void free_array(int *array)
{
    free(array);
    array = NULL;
}
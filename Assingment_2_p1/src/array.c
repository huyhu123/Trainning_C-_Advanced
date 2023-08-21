#include "array.h"

#define SWAP(x, y) \
  do { \
    int tmp = (x); \
    (x) = (y); \
    (y) = tmp; } \
  while (0)

#define ARRAY_MAX 50

static int Clean_stdin()
{
    while (getchar() != '\n');
    return 1;
}

static int Get_input_size() 
{
    int input;

    while ((scanf("%d", &input) != 1 || input < 1 || input >50) && Clean_stdin()) {
        printf("\n*Warning:Failed! Please enter an interger between 0 and 50.\nEnter again:  ");
    }

    return input;
}

static int Get_input_int() 
{
    int input;

    while ((scanf("%d", &input) != 1) && Clean_stdin()) {
        printf("\n*Warning:Failed! Please enter an interger.\nEnter again:  ");
    }

    return input;
}

static void Swap(int *value_1, int *value_2)
{
    int temp = *value_1;
    *value_1 = *value_2;
    *value_2 = temp;
}

void get_array_size(int *size)
{
    *size = Get_input_size();
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
        array[i] = Get_input_int();
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
        while (abs(array[left_index]) % 2 == 1 && left_index < right_index) {
            left_index++;            
        }
        while (abs(array[right_index]) % 2 == 0 && left_index < right_index) {
            right_index--;
        }

        if (left_index < right_index) {
            //Swap(&array[left_index], &array[right_index]);
            SWAP(array[left_index], array[right_index]);
        } 
    }
}
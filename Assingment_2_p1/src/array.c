#include "array.h"

#define SWAP(a, b) int temp = a; a = b; b = temp  

#define ARRAY_MAX 50

static int Clean_stdin()
{
    while(getchar() != '\n')
    {

    }
    return 1;
}

static int get_input_int() 
{
    int input;
    unsigned int i =0 ;
    char c;

    while ((scanf("%d", &input) != 1 || input < 1) && Clean_stdin())
    {
        printf("\n*Warning:Failed! The amount of the row and column must be a positive integer.\nEnter again:  ");
    }
    return input;
}

void get_array_size(int *size)
{
    *size = get_input_int();
}

int *initialize_array(int size)
{
    return malloc(size * sizeof(int));
}

void print_array(int *array, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%i ", array[i]);
    }
    printf("\n");
}

void get_array_data(int *array, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("Enter element %d of the array: ", i);
        array[i] = get_input_int();
    }
    printf("\n");
}

float calculate_average_value(int *array, int size)
{
    float average = 0;

    for(int i = 0; i < size; i++)
    {
        average += array[i];
    }

    return average/size;
}

int count_elements_less_than_average(int *array, int size, float average)
{
    int count = 0;

    for(int i = 0; i < size; i++)
    {
        if(array[i] < average)
        {
            count++;
        }
    }

    return count;
}

int count_elements_more_than_average(int *array, int size, float average)
{
    int count = 0;

    for(int i = 0; i < size; i++)
    {
        if(array[i] > average)
        {
            count++;
        }
    }

    return count;
}

void reorder_array(int *array, int size)
{
    int index = 0;

    for(int i = 0; i < size; i++)
    {
        if(array[i] % 2 == 1)
        {
            SWAP(array[i], array[index]);
            index++;
        }
    }
}
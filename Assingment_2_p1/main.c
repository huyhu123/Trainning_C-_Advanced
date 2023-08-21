#include <array.h>

int main()
{
    int *array;
    int size = 0;

    //Get array size
    printf("Enter array size: ");
    get_array_size(&size);

    //Initialize_array
    array = initialize_array(size);

    //Get array data
    get_array_data(array, size);

    //Print array
    printf("Array: ");
    print_array(array, size);

    //Calculate the average value of the elements of the array, the number of elements less and more than this average value
    float average = calculate_average_value(array, size);
    int num_less = count_elements_less_than_average(array, size, average);
    int num_more = count_elements_more_than_average(array, size, average);
    printf("Average value of the elements of the array: %.2f\nNumber of elements less than average value: %i\nNumber of elements more than average value: %i\n", average, num_less, num_more);

    //Moves even values to the right and odd values to the left of the array
    printf("Array before moves even values to the right and odd values to the left: ");
    print_array(array, size);
    move_elements_array(array, size);
    printf("Array after moves even values to the right and odd values to the left: ");
    print_array(array, size);

    //Free allocated memory
    free_array(array);

    return 0;
}
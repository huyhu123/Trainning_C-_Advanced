#include <array.h>

int main()
{
    int *array;
    int size = 0;

    printf("Array size: ");
    get_array_size(&size);

    array = initialize_array(size);

    get_array_data(array, size);

    printf("Array: ");
    print_array(array, size);

    float average = calculate_average_value(array, size);
    int num_less = count_elements_less_than_average(array, size, average);
    int num_more = count_elements_less_than_average(array, size, average);
    printf("Average value of the elements of the array: %f\nNumber of elements less than average value: %i\nNumber of elements more than average value: %i\n", average, num_less, num_more);

    printf("Array before moves even values to the right and odd values to the left: ");
    print_array(array, size);
    reorder_array(array, size);
    printf("Array after moves even values to the right and odd values to the left: ");
    print_array(array, size);

    return 0;
}
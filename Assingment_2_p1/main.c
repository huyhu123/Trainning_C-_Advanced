#include <array.h>

int main()
{
    int *array;
    int size = 0;

    printf("Array size: ");
    get_array_size(&size);

    array = initialize_array(size);

    get_array_data(array, size);

    print_array(array, size);

    return 0;
}
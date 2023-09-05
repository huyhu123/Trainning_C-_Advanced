#include "gemtek_lib.h"

int main() 
{
    int input;
    get_input_int(&input);

    printf("Cube of x: %.0f\n", cube(input));
    printf("Square of x: %.0f\n", square(input));
    if (is_fibonacci(input)) {
        printf("%i is a fibonacci number\n", input);
    } else {
        printf("%i is not a fibonacci number\n", input);
    }

    return 0;
}





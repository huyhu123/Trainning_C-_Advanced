#include "gemtek_lib.h"

int main() 
{
    float input;
    get_input_float(&input);

    printf("Cube of x: %.2f\n", cube(input));
    printf("Square of x: %.2f\n", square(input));
    if (is_fibonacci(input)) {
        printf("%.2f is a fibonacci number\n", input);
    } else {
        printf("%.2f is not a fibonacci number\n", input);
    }

    return 0;
}





#include "gemtek_lib.h"

int main() {
    int input;
    get_input_int(&input);
    printf("Cube of x: %.0f\n", cube(input));
    printf("Square of x: %.0f\n", square(input));

    return 0;
}





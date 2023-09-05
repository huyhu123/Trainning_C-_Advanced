#include "gemtek_lib.h"

// Get input
void get_input_float(float *input)
{
    // Check if input is valid
    printf("Enter x: ");
    while (scanf("%f", input) != 1) {
        // Handle invalid input
        printf("Please enter a real number: ");
        
        // Clear stdin buffer
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
}

int main() {
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





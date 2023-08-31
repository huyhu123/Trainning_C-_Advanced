#include "gemtek_lib.h"

int main() {
    float input;
    // Check if input is valid
    printf("Enter x: ");
    while ((scanf("%f", &input) != 1 )) {
        printf("Please enter a real number: ");
        //clear stdin
        int c;
        while (c = getchar() != '\n' && c != EOF);
    }

    printf("Cube of x: %.2f\n", cube(input));
    printf("Square of x: %.2f\n", square(input));

    return 0;
}





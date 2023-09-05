#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define BUFFER_LENGTH 100

bool is_float(const char *buffer, float *dest) 
{
    if (buffer == NULL) {
        return false;
    }

    char *endptr;
    *dest = (float) strtod(buffer, &endptr);
    if (buffer == endptr) {
        return false; // no conversion;
    }

    // Look at trailing text
    while (isspace((unsigned char ) *endptr))
        endptr++;

    return *endptr == '\0';
}

void get_input_float(float *value) 
{
    char buffer[BUFFER_LENGTH];
    char *endptr;

    // Get input
    printf("Enter x: ");
    fgets(buffer, sizeof(buffer), stdin);
    while(!is_float(buffer, value)) {
        //Handle invalid input
        printf("Please enter a real number: ");
        fgets(buffer, sizeof(buffer), stdin);
    }
}

float cube(float x)
{
    return x * x * x;
}

float square(float x)
{
    return x * x;
}

bool is_perfect_square(float x)
{
    int s = sqrt(x);
    return (s * s == x);
}
 
// Returns true if n is a Fibonacci Number, else false
int is_fibonacci(float n)
{
    // n is Fibonacci if one of 5*n*n + 4 or 5*n*n - 4 or
    // both is a perfect square
    return is_perfect_square(5 * n * n + 4) || is_perfect_square(5 * n * n - 4);
}
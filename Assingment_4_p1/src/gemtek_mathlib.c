#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

#define BUFFER_LENGTH 100

bool is_integer(const char* buffer, int* dest) {
    if (buffer == NULL) {
        return false;
    }

    char* endptr;
    errno = 0; // Reset errno before calling strtol
    long result = strtol(buffer, &endptr, 10);
    
    // Check for conversion errors
    if (buffer == endptr || errno == ERANGE || result > INT_MAX || result < INT_MIN) {
        return false; // Conversion error or overflow
    }

    // Look at trailing text
    while (isspace((unsigned char)*endptr)) {
        endptr++;
    }

    // Check if there is any trailing text after the number
    if (*endptr != '\0') {
        return false; // Trailing text present
    }

    *dest = (int)result; // Assign converted value to the destination variable
    return true; // Successful conversion
}

void get_input_int(int *value) 
{
    char buffer[BUFFER_LENGTH] = {0};
    char *endptr;

    // Get input
    printf("Enter x: ");
    fgets(buffer, sizeof(buffer), stdin);
 
    while(!is_integer(buffer, value)) {
        //Handle invalid input
        printf("Invalid input or input too large: ");
        fgets(buffer, sizeof(buffer), stdin);
    }
}

double cube(int x) {
    double result = (double)x * x * x;
    return result;
}

double square(int x)
{
    double result = (double)x * x;
    return result;
}
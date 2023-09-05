#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

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

int is_fibonacci(float n)
{
    int pre_num = 0;
    int cur_num = 1;
    if (n == pre_num || n == cur_num) {
        return 1;
    } 

    int next_num = pre_num + cur_num;
    while(next_num <= n) {
        if(next_num == n) return 1;
        pre_num = cur_num;
        cur_num = next_num;
        next_num = pre_num + cur_num;
    }

    return 0;
}

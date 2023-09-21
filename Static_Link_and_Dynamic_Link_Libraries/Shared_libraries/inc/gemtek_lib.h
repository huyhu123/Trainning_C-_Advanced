#ifndef _GEMTEK_LIB_H_
#define _GEMTEK_LIB_H_

#include <stdio.h>
#include <stdbool.h>

/**
 * @brief Calculates the square of an integer.
 *
 * This function takes an integer value and returns its square.
 *
 * @param x The integer value to be squared.
 * @return The square of the input integer.
 */
double square(int x);

/**
 * @brief Calculates the cube of an integer.
 *
 * This function takes an integer value and returns its cube.
 *
 * @param x The integer value to be cubed.
 * @return The cube of the input integer.
 */
double cube(int x);

/**
 * @brief Checks if a given number is a Fibonacci number.
 *
 * This function takes a floating-point number and checks if it is a Fibonacci number.
 *
 * @param n The number to be checked.
 * @return 1 if the number is a Fibonacci number, 0 otherwise.
 */
int is_fibonacci(float n);

/**
 * @brief Reads an integer from the user and stores it in the provided memory location.
 *
 * This function prompts the user to enter an integer, which will be stored at the provided memory location.
 *
 * @param value A pointer to the memory location where the input integer will be stored.
 */
void get_input_int(int *value);

#endif

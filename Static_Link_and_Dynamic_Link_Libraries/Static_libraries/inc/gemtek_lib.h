#ifndef _GEMTEK_LIB_H_
#define _GEMTEK_LIB_H_

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

/**
 * @brief Calculates the square of an integer.
 *
 * @param x The integer value to be squared.
 * @return The square of the input integer.
 */
double square(int x);

/**
 * @brief Calculates the cube of an integer.
 *
 * @param x The integer value to be cubed.
 * @return The cube of the input integer.
 */
double cube(int x);

/**
 * @brief Reads an integer from the user and stores it in the provided memory location.
 *
 * @param value A pointer to the memory location where the input integer will be stored.
 */
void get_input_int(int *value);

#endif

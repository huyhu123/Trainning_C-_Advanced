#ifndef _FILE_H_
#define _FILE_H_

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define FILE_NAME_MAX 100

/**
 * @brief Returns the size of the specified file in bytes.
 * 
 * @param file_name The name of the file.
 * @return The size of the file in bytes, or -1 if the file does not exist or cannot be opened.
 */
long get_file_size(char file_name[]);

/**
 * @brief Retrieves a single character from the specified file.
 * 
 * @param file_name The name of the file.
 */
void get_input_char(char file_name[]);

/**
 * @brief Checks if the specified file exists.
 * 
 * @param file_name The name of the file.
 * @return 1 if the file exists, 0 otherwise.
 */
int check_file_exist(const char file_name[]);

#endif

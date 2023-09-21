#ifndef _CAESAR_CIPHER_H_
#define _CAESAR_CIPHER_H_

#ifdef _WIN32
#include <conio.h>
#else
#define clrscr() printf("\e[1;1H\e[2J")
#endif

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <stdlib.h>
#include "file_handling.h"

#define FILE_NAME_MAX 255

typedef enum {
    e_quit = 0x00U,
    e_encode = 0x01U,
    e_decode = 0x02U,
    e_change_file = 0x03U,
    e_change_shift = 0x04U,
    e_change_output_name = 0x05U,
    e_change_output_dir = 0x06U,
} e_main_interface_option;

/**
 * @brief Display the main user interface options.
 * 
 * This function displays the main user interface options and prompts the user to select an option.
 * The selected option is returned as an enumeration value of the e_main_interface_option type.
 *
 * @return The selected main interface option.
 */
e_main_interface_option show_main_interface();

/**
 * @brief Encodes a file using the Caesar cipher.
 * 
 * This function takes a file name, a shift value, an output file name, and an output directory
 * as inputs, and encodes the contents of the input file using the Caesar cipher algorithm.
 * The encoded contents are then written to the output file in the specified output directory.
 * 
 * @param file_name     The name of the input file.
 * @param shift         The shift value used for encoding.
 * @param output_name   The name of the output file.
 * @param output_dir    The directory where the output file will be stored.
 */
void encode_caesar_cipher(char *file_name, int shift, char *output_name, char *output_dir);


/**
 * @brief Decodes a file that was encoded using the Caesar cipher.
 * 
 * This function takes a file name, a shift value, an output file name, and an output directory
 * as inputs, and decodes the contents of the input file using the reverse Caesar cipher algorithm.
 * The decoded contents are then written to the output file in the specified output directory.
 * 
 * @param file_name     The name of the input file.
 * @param shift         The shift value used for decoding (should be the same as the one used for encoding).
 * @param output_name   The name of the output file.
 * @param output_dir    The directory where the output file will be stored.
 */
void decode_caesar_cipher(char *file_name, int shift, char *output_name, char *output_dir);


/**
 * @brief Retrieves the file name from user input.
 * 
 * This function prompts the user to enter a file name and stores it in the provided character array.
 * The size of the character array should be sufficient to hold the file name.
 * 
 * @param file_name     The character array where the file name will be stored.
 */
void get_file_name(char *file_name);

/**
 * @brief Retrieves the shift number.
 *
 * @return The current shift number.
 */
int get_shift_number();

/**
 * @brief Changes the output name to the specified value.
 *
 * @param output_name The new output name.
 */
void change_output_name(char *output_name);

/**
 * @brief Changes the output directory to the specified value.
 *
 * @param output_dir The new output directory.
 */
void change_output_dir(char *output_dir);

#endif

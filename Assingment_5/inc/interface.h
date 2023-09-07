#ifndef _INTERFACE_H_
#define _INTERFACE_H_

#include <errno.h>
#include "cryptography.h"
#include "file_handling.h"

#define BUFFER_LENGTH       100
#define FILE_NAME_MAX       255

typedef enum {
    e_quit = 0x00U,
    e_encode = 0x01U,
    e_decode = 0x02U,
    e_encode_file = 0x03U,
    e_decode_file = 0x04U,
    e_change_output_name = 0x05U,
    e_change_output_dir = 0x06U,
} e_main_interface_option;

e_main_interface_option show_main_UI(char *out_dir, char *out_name);

/**
 * @brief Shows the main user interface and returns the selected option.
 *
 * @param out_dir The output directory.
 * @param out_name The output file name.
 * @return The selected option from the main interface.
 */
e_main_interface_option show_main_UI(char *out_dir, char *out_name);

/**
 * @brief Prompts the user to choose an option for text encoding.
 *
 * @param out_dir The output directory.
 * @param out_name The output file name.
 */
void choose_encode_text_option(char *out_dir, char *out_name);

/**
 * @brief Prompts the user to choose an option for text decoding.
 *
 * @param out_dir The output directory.
 * @param out_name The output file name.
 */
void choose_decode_text_option(char *out_dir, char *out_name);

/**
 * @brief Prompts the user to choose an option for file encoding.
 *
 * @param out_dir The output directory.
 * @param out_name The output file name.
 */
void choose_encode_file_option(char *out_dir, char *out_name);

/**
 * @brief Prompts the user to choose an option for file decoding.
 *
 * @param out_dir The output directory.
 * @param out_name The output file name.
 */
void choose_decode_file_option(char *out_dir, char *out_name);

/**
 * @brief Changes the output directory.
 *
 * @param output_dir The new output directory.
 */
void change_output_dir(char *output_dir);

/**
 * @brief Changes the output file name.
 *
 * @param output_name The new output file name.
 */
void change_output_name(char *output_name);

#endif

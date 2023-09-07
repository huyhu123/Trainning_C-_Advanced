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

void choose_encode_text_option(char *out_dir, char *out_name);

void choose_decode_text_option(char *out_dir, char *out_name);

void choose_encode_file_option(char *out_dir, char *out_name);

void choose_decode_file_option(char *out_dir, char *out_name);

void change_output_dir(char *output_dir);

void change_output_name(char *output_name);

#endif

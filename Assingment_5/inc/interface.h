#ifndef _INTERFACE_H_
#define _INTERFACE_H_

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <stdlib.h>
#include "binary_tree.h"
#include "cryptography.h"

#define FILE_NAME_MAX       255

typedef enum {
    e_quit = 0x00U,
    e_encode = 0x01U,
    e_decode = 0x02U,
    e_change_file = 0x03U,
    e_change_shift = 0x04U,
    e_change_output_name = 0x05U,
    e_change_output_dir = 0x06U,
} e_main_interface_option;

void write_to_file(char *dir, char *text);

#endif

#ifndef _CRYPTOGRAPHY_H_
#define _CRYPTOGRAPHY_H_

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
#include "binary_tree.h"

#define FILE_NAME_MAX 255
#define COUNT 5

typedef enum {
    e_quit = 0x00U,
    e_encode = 0x01U,
    e_decode = 0x02U,
    e_change_file = 0x03U,
    e_change_shift = 0x04U,
    e_change_output_name = 0x05U,
    e_change_output_dir = 0x06U,
} e_main_interface_option;

void build_morse_tree(tree_node_t **root);

void encode_morse(tree_node_t *root, char *input);

#endif

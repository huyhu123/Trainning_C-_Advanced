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

#define FILE_NAME_MAX       255
#define COUNT               5
#define MAX_STRING_SIZE     500

typedef enum {
    e_quit = 0x00U,
    e_encode = 0x01U,
    e_decode = 0x02U,
    e_change_file = 0x03U,
    e_change_shift = 0x04U,
    e_change_output_name = 0x05U,
    e_change_output_dir = 0x06U,
} e_main_interface_option;

void build_morse_tree(tree_node_t **g_root);

char* decode_morse(char *morse);

tree_node_t *get_node_by_data(tree_node_t *g_root, char data);

void encode_morse(char *text, char *decode_text);

void clean_up(); 

void initialize_binary_tree();

#endif

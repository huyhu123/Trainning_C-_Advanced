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

#define COUNT               5
#define MAX_STRING_SIZE     500

void build_morse_tree(tree_node_t **g_root);

char* decode_morse(char *morse);

tree_node_t *get_node_by_data(tree_node_t *g_root, char data);

void encode_morse(char *text, char *decode_text);

void clean_up(); 

void initialize_binary_tree();

#endif

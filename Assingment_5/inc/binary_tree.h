#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <stdlib.h>

#define COUNT 5

typedef struct tree_node {
    char data;
    struct tree_node *left;
    struct tree_node *right;
} tree_node_t;

tree_node_t *create_node(char data);

void insert(tree_node_t **root, char data, char *morse_code);

void print_2d(tree_node_t *root);

#endif

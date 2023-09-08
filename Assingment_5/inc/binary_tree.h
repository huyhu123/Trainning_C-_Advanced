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

/**
 * @brief Creates a new tree node with the given data.
 *
 * @param data The data to be stored in the node.
 * @return A pointer to the newly created tree node.
 */
tree_node_t *create_node(char data);

/**
 * @brief Inserts a new node into the binary tree based on the given Morse code.
 *
 * @param[in,out] g_root The pointer to the root of the binary tree.
 * @param data The data to be stored in the new node.
 * @param morse_code The Morse code associated with the data.
 */
void insert(tree_node_t **root, char data, char *morse_code);

/**
 * @brief Prints the binary tree in a 2D format.
 *
 * @param g_root The root of the binary tree to be printed.
 */
void print_2d(tree_node_t *root);

/**
 * @brief Deallocate tree.
 *
 * @param g_root The root of the binary tree to be printed.
 */
void free_tree(tree_node_t *root);

#endif

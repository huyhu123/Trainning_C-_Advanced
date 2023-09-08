#include "binary_tree.h"

tree_node_t *create_node(char data) 
{
    tree_node_t *new_node = (tree_node_t *) malloc(sizeof(tree_node_t));

    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

void insert(tree_node_t **root, char data, char *morse_code) 
{
    if (*root == NULL) {
        *root = create_node('\0');
    }

    tree_node_t *curr = *root;
    for (int i = 0; i < strlen(morse_code); i++) {
        if (morse_code[i] == '.') {
            if (curr->left == NULL) {
                curr->left = create_node('\0');
            }
            curr = curr->left;
        } else if (morse_code[i] == '-') {
            if (curr->right == NULL) {
                curr->right = create_node('\0');
            }
            curr = curr->right;
        }
    }
    curr->data = data;
}

// Function to print binary tree in 2D
// It does reverse inorder traversal
void print2d_util(tree_node_t *root, int space)
{
    // Base case
    if (root == NULL)
        return;
 
    // Increase distance between levels
    space += COUNT;
 
    // Process right child first
    print2d_util(root->right, space);
 
    // Print current node after space
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%c\n", root->data);
 
    // Process left child
    print2d_util(root->left, space);
}
 
// print tree
void print_2d(tree_node_t *root)
{
    // Pass initial space count as 0
    print2d_util(root, 0);
}

// Free binary tree
void free_tree(tree_node_t *root)
{
    // If tree is empty
    if (root == NULL) {
        return;
    }

    // Free left subtree
    free_tree(root->left);
    // Free right subtree
    free_tree(root->right);
    // Free current node
    free(root);
}

#include "cryptography.h"

// Clear stdin
static int clean_stdin()
{
    int c;
    while (c = getchar() != '\n' && c != EOF);
    return 1;
}

// Check if buffer if overflow
static bool check_input_buffer(char input[])
{
    if (strcspn(input, "\n") == FILE_NAME_MAX - 1) {
        clean_stdin();
        return true;
    }
    return false;
}

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
        *root = create_node(data);
    } else {
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
}

void build_morse_tree(tree_node_t **root) {
    insert(root, 'E', ".");
    insert(root, 'T', "-");
    insert(root, 'I', "..");
    insert(root, 'A', ".-");
    insert(root, 'N', "-.");
    insert(root, 'M', "--");
    insert(root, 'S', "...");
    insert(root, 'U', "..-");
    insert(root, 'R', ".-.");
    insert(root, 'W', ".--");
    insert(root, 'D', "-..");
    insert(root, 'K', "-.-");
    insert(root, 'G', "--.");
    insert(root, 'O', "---");
}

// Function to print binary tree in 2D
// It does reverse inorder traversal
void print2d_util(tree_node_t* root, int space)
{
    // Base case
    if (root == NULL)
        return;
 
    // Increase distance between levels
    space += COUNT;
 
    // Process right child first
    print2d_util(root->right, space);
 
    // Print current node after space
    // count
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

void encode_morse(tree_node_t *root, char *input) 
{
    int len = strlen(input);
    int index = 0;

    for (int i = 0; i < len; i++) {
        if (input[i] == ' ') {
            printf(" / ");
        } else {
            tree_node_t* curr = root;
            index = 0;

            while (curr != NULL && input[i] != curr->data) {
                if (input[i] == '.') {
                    curr = curr->left;
                } else if (input[i] == '-') {
                    curr = curr->right;
                }
                index++;
            }
            if (curr != NULL) {
                printf("%c", curr->data);
            }
            i--;
        }
    }
    printf("\n");
}


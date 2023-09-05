#include "cryptography.h"
#include "binary_tree.h"

void build_morse_tree(tree_node_t **root) 
{
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
    insert(root, 'Z', "-----");
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


#include "cryptography.h"
#include "binary_tree.h"

tree_node_t *g_root = NULL;

bool create_morse_tree(const char *filename, tree_node_t **root) 
{
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open morse_code_key.txt (Make sure file morse_code_key.txt is in the same directory as the program).\n");
        return false;
    }

    printf("Read key from morse_code_key.txt.\n");
    char line[MAX_STRING_SIZE] = {0};
    while (fgets(line, sizeof(line), file)) {
        if (strlen(line) <= 1) {
            continue;  // Skip empty lines
        }

        // Extract the character and Morse code from the line
        char *character= strtok(line, " ");
        char *morse_code = strtok(NULL, " ");

        printf("%s %s", character, morse_code);

        // Remove trailing newline character
        int len = strlen(character);
        if (character[len - 1] == '\n') {
            character[len - 1] = '\0';
        }

        insert(&g_root, character[0], morse_code);
    }

    // Print binary tree
    printf("\nBuliding binary tree: \n");
    print_2d(g_root);

    fclose(file);

    return true;
}

bool init_cryptography(char *morse_code_key) 
{
    return create_morse_tree(morse_code_key , &g_root);
}

char* decode_morse(char* morse)
{
    if (morse == NULL) {
        return NULL;
    }

    char* decode_string = malloc(strlen(morse) + 1);
    if (decode_string == NULL) {
        return NULL;
    }

    char* token = strtok(morse, " ");
    int index = 0;
    while (token != NULL) {
        if (strcmp(token, "/") == 0) {
            decode_string[index++] = ' '; // Indicates a new word
        } else if (strcmp(token, "|") == 0)
        {
            decode_string[index++] = '\n';
        }
        else {
            tree_node_t* curr_node = g_root;
            int len = strlen(token);
            int error = 0; // Flag to indicate if there was an error in decoding

            for (int i = 0; i < len; i++) {
                if (token[i] == '.') {
                    if (curr_node->left != NULL) {
                        curr_node = curr_node->left;
                    } else {
                        error = 1; // Error: Invalid Morse code sequence
                        break;
                    }
                }
                else if (token[i] == '-') {
                    if (curr_node->right != NULL) {
                        curr_node = curr_node->right;
                    } else {
                        error = 1; // Error: Invalid Morse code sequence
                        break;
                    }
                }
                else {
                    error = 1; // Error: Invalid Morse code character
                    break;
                }
            }

            if (error) {
                decode_string[index++] = '?'; // Indicates an error in decoding
            }
            else {
                decode_string[index++] = curr_node->data;
            }
        }

        token = strtok(NULL, " ");
    }

    decode_string[index] = '\0'; // Null-terminate the string
    return decode_string;
}

tree_node_t *get_node_by_data(tree_node_t *root, char data)
{
    // Base case: If the g_root is NULL or the data matches, return the g_root
    if (root == NULL || root->data == data) {
        return root;
    }

    // Recursively search in the left and right subtrees
    tree_node_t *left_node = get_node_by_data(root->left, data);
    if (left_node != NULL) {
        return left_node;
    }

    tree_node_t *right_node = get_node_by_data(root->right, data);
    if (right_node != NULL) {
        return right_node;
    }

    // Node not found
    return NULL;
}

void get_path_to_node(tree_node_t *root, tree_node_t *node, char *buffer)
{
    // Base case: If the g_root is NULL or the node is not found
    if (root == NULL || node == NULL) {
        return;
    }

    // Create a pointer to g_root
    int index = 0;
    tree_node_t *curr_node = root;

    while (curr_node != node) {
        // Check if node is on the left
        if (curr_node->left != NULL && get_node_by_data(curr_node->left, node->data) != NULL) {
            buffer[index] = '.';
            curr_node = curr_node->left;
        }
        // Check if node is on the right
        else if (curr_node->right != NULL && get_node_by_data(curr_node->right, node->data) != NULL) {
            buffer[index] = '-';
            curr_node = curr_node->right;
        }
        else {
            // Clear the buffer to avoid appending invalid characters
            memset(buffer, 0, MAX_STRING_SIZE);
            return;
        }

        index++;
    }

    return;
}

void encode_morse(char *text, char *decode_text)
{
    tree_node_t *node_temp;
    char s_temp[MAX_STRING_SIZE] = {0};

    // Clear decode_text
    memset(decode_text, 0, sizeof(decode_text));

    for (int i = 0; i < strlen(text); i++) {
        if (text[i] == '|') {
            strcat(decode_text, "\n");
            i++;
            continue;
        }
        if (text[i] == ' ') {
            strcat(decode_text, "/ ");
            continue;
        }

        // Clear s_temp before using it
        memset(s_temp, 0, sizeof(s_temp));

        node_temp = get_node_by_data(g_root, text[i]);
        if (node_temp != NULL) {
            get_path_to_node(g_root, node_temp, s_temp);
            strcat(decode_text, s_temp);
            strcat(decode_text, " ");
        }
    }
}

// Function wrap around free_tree
void destroy_cryptography() 
{
    free_tree(g_root);
    g_root = NULL;
}
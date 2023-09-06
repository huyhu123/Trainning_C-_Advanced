#include "cryptography.h"
#include "binary_tree.h"

tree_node_t *g_root = NULL;

char *get_morse_code(char c)
{
    switch (c){
        case 'A':
            return ".-";
        case 'B':
            return "-...";
        case 'C':
            return "-.-.";
        case 'D':
            return "-..";
        case 'E':
            return ".";
        case 'F':
            return "..-.";
        case 'G':
            return "--.";
        case 'H':
            return "....";
        case 'I':
            return "..";
        case 'J':
            return ".---";
        case 'K':
            return "-.-";
        case 'L':
            return ".-..";
        case 'M':
            return "--";
        case 'N':
            return "-.";
        case 'O':
            return "---";
        case 'P':
            return ".--.";
        case 'Q':
            return "--.-";
        case 'R':
            return ".-.";
        case 'S':
            return "...";
        case 'T':
            return "-";
        case 'U':
            return "..-";
        case 'V':
            return "...-";
        case 'W':
            return ".--";
        case 'X':
            return "-..-";
        case 'Y':
            return "-.--";
        case 'Z':
            return "--..";
        case '1':
            return ".----";
        case '2':
            return "..---";
        case '3':
            return "...--";
        case '4':
            return "....-";
        case '5':
            return ".....";
        case '6':
            return "-....";
        case '7':
            return "--...";
        case '8':
            return "---..";
        case '9':
            return "----.";
        case '0':
            return "-----";
        default:
            return "";
    }
}

void build_morse_tree(tree_node_t **g_root) 
{
    insert(g_root, 'A', get_morse_code('A'));
    insert(g_root, 'B', get_morse_code('B'));
    insert(g_root, 'C', get_morse_code('C'));
    insert(g_root, 'D', get_morse_code('D'));
    insert(g_root, 'E', get_morse_code('E'));
    insert(g_root, 'F', get_morse_code('F'));
    insert(g_root, 'G', get_morse_code('G'));
    insert(g_root, 'H', get_morse_code('H'));
    insert(g_root, 'I', get_morse_code('I'));
    insert(g_root, 'J', get_morse_code('J'));
    insert(g_root, 'K', get_morse_code('K'));
    insert(g_root, 'L', get_morse_code('L'));
    insert(g_root, 'M', get_morse_code('M'));
    insert(g_root, 'N', get_morse_code('N'));
    insert(g_root, 'O', get_morse_code('O'));
    insert(g_root, 'P', get_morse_code('P'));
    insert(g_root, 'Q', get_morse_code('Q'));
    insert(g_root, 'R', get_morse_code('R'));
    insert(g_root, 'S', get_morse_code('S'));
    insert(g_root, 'T', get_morse_code('T'));
    insert(g_root, 'U', get_morse_code('U'));
    insert(g_root, 'V', get_morse_code('V'));
    insert(g_root, 'W', get_morse_code('W'));
    insert(g_root, 'X', get_morse_code('X'));
    insert(g_root, 'Y', get_morse_code('Y'));
    insert(g_root, 'Z', get_morse_code('Z'));
    insert(g_root, '1', get_morse_code('1'));
    insert(g_root, '2', get_morse_code('2'));
    insert(g_root, '3', get_morse_code('3'));
    insert(g_root, '4', get_morse_code('4'));
    insert(g_root, '5', get_morse_code('5'));
    insert(g_root, '6', get_morse_code('6'));
    insert(g_root, '7', get_morse_code('7'));
    insert(g_root, '8', get_morse_code('8'));
    insert(g_root, '9', get_morse_code('9'));
    insert(g_root, '0', get_morse_code('0'));
}

void initialize_binary_tree() {
    build_morse_tree(&g_root);
}

char* decode_morse(char *morse) 
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
        } else {
            tree_node_t *curr_node = g_root;
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
                } else if (token[i] == '-') {
                    if (curr_node->right != NULL) {
                        curr_node = curr_node->right;
                    } else {
                        error = 1; // Error: Invalid Morse code sequence
                        break;
                    }
                } else {
                    error = 1; // Error: Invalid Morse code character
                    break;
                }
            }

            if (error) {
                decode_string[index++] = '?'; // Indicates an error in decoding
            } else {
                decode_string[index++] = curr_node->data;
            }
        }

        token = strtok(NULL, " ");
    }

    decode_string[index] = '\0'; // Null-terminate the string
    return decode_string;
}

tree_node_t *get_node_by_data(tree_node_t *g_root, char data)
{
    // Base case: If the g_root is NULL or the data matches, return the g_root
    if (g_root == NULL || g_root->data == data) {
        return g_root;
    }

    // Recursively search in the left and right subtrees
    tree_node_t *left_node = get_node_by_data(g_root->left, data);
    if (left_node != NULL) {
        return left_node;
    }

    tree_node_t *right_node = get_node_by_data(g_root->right, data);
    if (right_node != NULL) {
        return right_node;
    }

    // Node not found
    return NULL;
}

void reverse_string(char *str)
{
	char temp[MAX_STRING_SIZE];
	
	// copy the string into temp
	strcpy(temp, str);
	int length = strlen(str);
	int start = 0, end = length - 1;
   
	while (start < end) {
		char c = str[start];
		str[start] = str[end];
		str[end] = c;
		start++;
		end--;
	}
}

void get_path_to_node(tree_node_t *g_root, tree_node_t *node, char *buffer)
{
    // Base case: If the g_root is NULL or the node is not found
    if (g_root == NULL || node == NULL) {
        return;
    }

    // Create a pointer to g_root
    int index = 0;
    tree_node_t *curr_node = g_root;

    while (curr_node != node) {
        // Check if node is on the left
        if (get_node_by_data(curr_node->left, node->data) != NULL) {
            if (curr_node->left == node) {
                buffer[index] = '.';
                return;
            }

            buffer[index] = '.';
            curr_node = curr_node->left;
            index++;
        }

        // Check if node is on the right
        if (get_node_by_data(curr_node->right, node->data) != NULL) {
            if (curr_node->right == node) {
                buffer[index] = '-';
                return;
            }

            buffer[index] = '-';
            curr_node = curr_node->right;
            index++;
        }
    }

    // Reverse string
    reverse_string(buffer);

    return;
}

void encode_morse(char *text, char *decode_text)
{
    tree_node_t *node_temp;
    char s_temp[MAX_STRING_SIZE];

    for(int i = 0; i < strlen(text); i++) {
        if (text[i] == ' ') {
            strcat(decode_text, "/ ");
            continue;
        }

        node_temp = get_node_by_data(g_root, text[i]);
        if (node_temp != NULL) {
            get_path_to_node(g_root, node_temp, s_temp);
            strcat(decode_text, s_temp);
            strcat(decode_text, " ");
        }
    }
}

// Free binary tree
void free_tree(tree_node_t *g_root)
{
    // If tree is empty
    if (g_root == NULL) {
        return;
    }

    // Free left subtree
    free_tree(g_root->left);
    // Free right subtree
    free_tree(g_root->right);
    // Free current node
    free(g_root);
}

// Function wrap around free_tree
void clean_up() 
{
    free_tree(g_root);
}





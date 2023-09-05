#include "cryptography.h"
#include "binary_tree.h"

int main() {
    tree_node_t* root = NULL;
    build_morse_tree(&root);
    
    char input[100];
    printf("Enter Morse code: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
    
    print_2d(root);

    printf("Decoded message: ");
    //encode_morse(root, input);
    
    return 0;
}





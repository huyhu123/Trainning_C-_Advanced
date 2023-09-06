#include "cryptography.h"
#include "binary_tree.h"

int main() {
    char input[100];
    printf("Enter Morse code: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
    
    initialize_binary_tree();

    //print_2d(g_root);

    printf("Decoded message: ");
    char *encode = decode_morse(input);
    printf("%s\n", encode);
    
    //char decode_text[MAX_STRING_SIZE];
    //encode_morse(input, decode_text);
    //printf("%s\n", decode_text);

    clean_up();

    return 0;
}





#include "cryptography.h"
#include "binary_tree.h"
#include "interface.h"

int main() {
    char input[100];
    printf("Enter Morse code: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
    
    initialize_binary_tree();

    //print_2d(g_root);

    char encode_text[MAX_STRING_SIZE];
    encode_morse(input, encode_text);
    printf("Encode message: %s\n", encode_text);
    //write_to_file("test.txt", decode_text);

    printf("Decoded message: ");
    char *decode = decode_morse(encode_text);
    printf("%s\n", decode);
    write_to_file("test.txt", decode);
    
    clean_up();

    return 0;
}





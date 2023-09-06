#include "interface.h"

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

bool is_integer(const char* buffer, int* dest, int min, int max) {
    if (buffer == NULL) {
        return false;
    }

    char* endptr;
    errno = 0; // Reset errno before calling strtol
    long result = strtol(buffer, &endptr, 10);
    
    // Check for conversion errors
    if (buffer == endptr || errno == ERANGE || result > max || result < min) {
        return false; // Conversion error or invalid
    }

    // Look at trailing text
    while (isspace((unsigned char)*endptr)) {
        endptr++;
    }

    // Check if there is any trailing text after the number
    if (*endptr != '\0') {
        return false; // Trailing text present
    }

    *dest = (int)result; // Assign converted value to the destination variable
    return true; // Successful conversion
}

void get_input_int(int *value, int min, int max) 
{
    char buffer[BUFFER_LENGTH];
    char *endptr;

    // Get input
    fgets(buffer, sizeof(buffer), stdin);
 
    while(!is_integer(buffer, value, min, max)) {
        //Handle invalid input
        printf("Invalid input or input too large: ");
        fgets(buffer, sizeof(buffer), stdin);
    }
}

// Get input for main UI
e_main_interface_option get_input_main_interface() 
{
    int input = 0;
    get_input_int(&input, 0, 4);

    return (e_main_interface_option)input;
}

void get_input_char(char *input) 
{
    fgets(input, FILE_NAME_MAX, stdin);

    // Check if input is valid
    while (check_input_buffer(input) == 1) {
        printf("\tInput too long, enter again (or e to exit): ");
        fgets(input, FILE_NAME_MAX, stdin);
    }
    // Strip line break at the end of input
    input[strcspn(input, "\n")] = 0;
}


void get_text(char *text)
{
    // Get file name
    printf("Enter encode text (or e to exit): ");
    get_input_char(text);
}

e_main_interface_option show_main_UI() 
{
    printf("Choose an option:\n");
    printf("1. Encode text\n");
    printf("2. Decode text\n");
    printf("3. Encode file\n");
    printf("4. Encode file\n");
    printf("0. Quit\n");
    printf("Your option: ");
    e_main_interface_option option = get_input_main_interface();

    return option;
}

void choose_encode_text_option()
{
    char text[MAX_STRING_SIZE];
    char input[MAX_STRING_SIZE];
    get_text(input);
    if (strcmp(input, "e") == 0) {
        return;
    }
    encode_morse(input, text);
    printf("Encode message: %s\n", text);
    write_to_file("test.txt", text);
}

void choose_decode_text_option()
{
    char input[MAX_STRING_SIZE];
    get_text(input);
    if (strcmp(input, "e") == 0) {
        return;
    }
    printf("Decoded message: ");
    char *text = decode_morse(input);
    printf("%s\n", text);
    write_to_file("test.txt", text);
}
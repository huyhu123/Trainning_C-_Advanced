#include "interface.h"

// Clear stdin
static int clean_stdin()
{
    int c = 0;
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

bool is_integer(const char* buffer, int* dest, int min, int max) 
{
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
    char buffer[BUFFER_LENGTH] = {0};
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
    get_input_int(&input, 0, 6);

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
    // Get text
    get_input_char(text);
}

// Get file name input from keybroad and check if file name is valid 
// If press e return false
bool get_file_name(char *file_name)
{
    char pre_file_name[MAX_FILE_SIZE] = {0};
    strcpy(pre_file_name, file_name);

    // Get file name
    printf("Enter file name (or e to exit): ");
    get_input_char(file_name);
    if (strcmp(file_name, "e") == 0) {
        strcpy(file_name, pre_file_name);
        return false;
    }

    // Check if file exist
    while (!check_file_exist(file_name)) {
        printf("File not exist, enter again (or e to exit): ");
        get_input_char(file_name);
        if (strcmp(file_name, "e") == 0) {
            strcpy(file_name, pre_file_name);
            return false;
        }
    }

    return true;
}

// Change name of a char * and check if name is a valid file name
void change_output_name(char *output_name)
{
    clrscr();

    char pre_file_name[FILE_NAME_MAX] = {0};
    strcpy(pre_file_name, output_name);

    // Get output file name
    printf("Enter new output file name (or e to exit): ");
    get_input_char(output_name);
    if (strcmp(output_name, "e") == 0) {
        strcpy(output_name, pre_file_name);
        return;
    }

    // Check if name valid
    while (!is_validfile_name(output_name)) {
        printf("Invalid file name (contain '\\/:*?\"<>|', too long or have space, '.' at start or end)\n Enter again (or e to exit): ");
        get_input_char(output_name);
        if (strcmp(output_name, "e") == 0) {
            strcpy(output_name, pre_file_name);
            return;
        }
    }
}

// Change directory and check if dir is exist
void change_output_dir(char *output_dir)
{
    clrscr();

    char pre_output_name[FILE_NAME_MAX] = {0};
    strcpy(pre_output_name, output_dir);

    // Get output dir
    printf("Enter new output dir (or e to exit): ");
    get_input_char(output_dir);
    if (strcmp(output_dir, "e") == 0) {
        strcpy(output_dir, pre_output_name);
        return;
    }

    // Check if dir exist
    while (!directory_exists(output_dir)) {
        printf("Directory not exist, enter again (or e to exit): ");
        get_input_char(output_dir);
        if (strcmp(output_dir, "e") == 0) {
            strcpy(output_dir, pre_output_name);
            return;
        }
    }
}

e_main_interface_option show_main_UI(char *out_dir, char *out_name) 
{
    printf("--------------------------------------------------\n");
    printf("Output file name: %s\n", out_name);
    printf("Output file directory: %s\n", out_dir);
    printf("--------------------------------------------------\n");

    printf("Choose an option:\n");
    printf("1. Encode text\n");
    printf("2. Decode text\n");
    printf("3. Encode file\n");
    printf("4. Decode file\n");
    printf("5. Change output file name\n");
    printf("6. Change output file directory\n");
    printf("0. Quit\n");
    printf("Your option: ");
    e_main_interface_option option = get_input_main_interface();

    return option;
}

void choose_encode_text_option(char *out_dir, char *out_name)
{
    char text[MAX_STRING_SIZE] = {0};
    char input[MAX_STRING_SIZE] = {0};

    // Get encode text
    printf("Enter encode text (or e to exit): ");
    get_text(input);
    if (strcmp(input, "e") == 0) { // Handle exit
        return;
    }

    // Get new file name and extension
    char new_file_name[FILE_NAME_MAX] = {0}; 
    create_new_file_name(new_file_name, ".txt", out_name, out_dir);

    // Check if file already exixted
    if (check_file_exist(new_file_name)) {
        char input[FILE_NAME_MAX] = {0};
        printf("File %s already exixted, overwrite file (y/n)? : ", new_file_name);
        get_input_char(input);

        while (!strcmp(input, "y") == 0) {
            if (strcmp(input, "n") == 0) {
                return;
            }
            printf("Please type 'y' or 'n': ");
            get_input_char(input);
        }
    }

    // Encode text
    encode_morse(input, text);
    printf("Encode message: %s\n", text);

    // Write to file
    write_to_file(new_file_name, text);
}

void choose_decode_text_option(char *out_dir, char *out_name)
{
    char input[MAX_STRING_SIZE] = {0};

    // Get decode text
    printf("Enter decode text (or e to exit): ");
    get_text(input);
    if (strcmp(input, "e") == 0) { // Handle exit
        return;
    }
    
    // Decode text
    char *text = decode_morse(input);
    printf("Decoded message: ");
    printf("%s\n", text);

    // Get new file name and extension
    char new_file_name[FILE_NAME_MAX] = {0}; 
    create_new_file_name(new_file_name, ".txt", out_name, out_dir);

    // Check if file already exixted
    if (check_file_exist(new_file_name)) {
        char input[FILE_NAME_MAX] = {0};
        printf("File %s already exixted, overwrite file (y/n)? : ", new_file_name);
        get_input_char(input);

        while (!strcmp(input, "y") == 0) {
            if (strcmp(input, "n") == 0) {
                free(text);
                return;
            }
            printf("Please type 'y' or 'n': ");
            get_input_char(input);
        }
    }

    // Write to file
    write_to_file(new_file_name, text);

    // Free allocated memory
    free(text);
}

void choose_encode_file_option(char *out_dir, char *out_name)
{
    char input[MAX_STRING_SIZE] = {0};
    if(!get_file_name(input)) { // Handle exit
        return;
    }

    char text[MAX_STRING_SIZE] = {0};
    char encode_text[MAX_STRING_SIZE] = {0};

    // Read from file
    read_from_file(input, text);

    // Encode text
    encode_morse(text, encode_text);

    printf("Encoded message: \n");
    printf("%s\n", encode_text);

    // Get new file name and extension
    char new_file_name[FILE_NAME_MAX] = {0}; 
    create_new_file_name(new_file_name, input, out_name, out_dir);

    // Check if file already exixted
    if (check_file_exist(new_file_name)) {
        char input[FILE_NAME_MAX] = {0};
        printf("File %s already exixted, overwrite file (y/n)? : ", new_file_name);
        get_input_char(input);

        while (!strcmp(input, "y") == 0) {
            if (strcmp(input, "n") == 0) {
                return;
            }
            printf("Please type 'y' or 'n': ");
            get_input_char(input);
        }
    }

    // Write to file
    write_to_file(new_file_name, encode_text);
}

void choose_decode_file_option(char *out_dir, char *out_name)
{
    char input[MAX_STRING_SIZE] = {0};
    if(!get_file_name(input)) { // Handle exit
        return;
    }

    char text[MAX_STRING_SIZE] = {0};
    char *decode_text;

    // Read from file
    read_from_file(input, text);
    printf("%s\n", text);

    // Decode text
    decode_text = decode_morse(text);

    printf("Decoded message: \n");
    printf("%s\n", decode_text);

    // Get new file name and extension
    char new_file_name[FILE_NAME_MAX] = {0}; 
    create_new_file_name(new_file_name, input, out_name, out_dir);

    // Check if file already exixted
    if (check_file_exist(new_file_name)) {
        char input[FILE_NAME_MAX] = {0};
        printf("File %s already exixted, overwrite file (y/n)? : ", new_file_name);
        get_input_char(input);

        while (!strcmp(input, "y") == 0) {
            if (strcmp(input, "n") == 0) {
                free(decode_text); // Free allocated memory
                return;
            }
            printf("Please type 'y' or 'n': ");
            get_input_char(input);
        }
    }

    // Write to file
    write_to_file(new_file_name, decode_text);

    // Free allocated memory
    free(decode_text);
}
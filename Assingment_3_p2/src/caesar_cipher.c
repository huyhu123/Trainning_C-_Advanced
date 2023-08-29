#include "caesar_cipher.h"

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

// Check if file exist
int check_file_exist(const char file_name[])
{
    FILE *file;
    if ((file = fopen(file_name, "r"))) {
        fclose(file);
        return 1;
    }
    return 0;
}

// Get input file name
void get_input_char(char input[]) 
{
    fgets(input, FILE_NAME_MAX, stdin);

    // Check if input is valid
    while (check_input_buffer(input) == 1) {
        printf("\tInput too long, enter again: ");
        fgets(input, FILE_NAME_MAX, stdin);
    }
    // Strip line break at the end of input
    input[strcspn(input, "\n")] = 0;
}

// Get input for main UI
e_main_interface_option get_input_main_interface() 
{
    float input;
    // Check if input is valid
    while ((scanf("%f", &input) != 1 || input < 0 || input > 2 || input - (int)input != 0) && clean_stdin()) {
        printf("  *Warning:Failed! Please enter a number from 0 to 2. Enter again:  ");
    }
    clean_stdin();

    return (e_main_interface_option)input;
}

// Show main UI
e_main_interface_option show_main_interface() 
{
    printf("Choose an option:\n");
    printf("0. Quit\n");
    printf("1. Encode file\n");
    printf("2. Decode file\n");
    printf("Your option: ");
    e_main_interface_option option = get_input_main_interface();

    return option;
}

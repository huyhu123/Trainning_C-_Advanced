#include "caesar_cipher.h"

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

// Get positive interger input
static int get_input_int() {
    float input;
    int num_scanned;  // variable to store the number of values successfully scanned

    // Check if input is valid
    while (((num_scanned = scanf("%f", &input)) != 1) || input < 0 || input - (int)input != 0 || getchar() != '\n') {
        // If scanning for a float fails or the input has extra characters, print a warning message and prompt again
        printf("*Warning: Failed! Please enter a positive integer. Enter again: ");
        clean_stdin();
    }

    return (int)input;
}

// Get input file name
void get_input_char(char input[]) 
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

// Get input for main UI
e_main_interface_option get_input_main_interface() 
{
    float input;
    // Check if input is valid
    while ((scanf("%f", &input) != 1 || input < 0 || input > 6 || input - (int)input != 0) && clean_stdin()) {
        printf("  *Warning:Failed! Please enter a number from 0 to 6. Enter again:  ");
    }
    clean_stdin();

    return (e_main_interface_option)input;
}

// Show main UI
e_main_interface_option show_main_interface() 
{
    printf("Choose an option:\n");
    printf("1. Encode file\n");
    printf("2. Decode file\n");
    printf("3. Change file\n");
    printf("4. Change shift number\n");
    printf("5. Change output file name\n");
    printf("6. Change output directory\n");
    printf("0. Quit\n");
    printf("Your option: ");
    e_main_interface_option option = get_input_main_interface();

    return option;
}

char encode_character_caesar_cipher(char ch, int shift)
{
    if (isalnum(ch)) {
        // Lowercase characters.
        if (islower(ch)) {
            ch = (ch - 'a' + shift) % 26 + 'a';
        }
        // Uppercase characters.
        if (isupper(ch)) {
            ch = (ch - 'A' + shift) % 26 + 'A';
        }
        // Numbers.
        if (isdigit(ch)) {
            ch = (ch - '0' + shift) % 10 + '0';
        }
    } 

    return ch;
}

char decode_character_caesar_cipher(char ch, int shift)
{
    if (isalnum(ch)) {
        // Lowercase characters.
        if (islower(ch)) {
            ch = (ch - 'a' - shift + 26) % 26 + 'a';
        }
        // Uppercase characters.
        if (isupper(ch)) {
            ch = (ch - 'A' - shift + 26) % 26 + 'A';
        }
        // Numbers.
        if (isdigit(ch)) {
            ch = (ch - '0' - shift + 26) % 10 + '0';
        }
    }

    return ch;
}

void encode_caesar_cipher(char *file_name, int shift, char *output_name, char *output_dir)
{
    FILE *file = NULL;
    FILE *temp = NULL;
    char ch;

    // Get new file name and extension
    char new_file_name[FILE_NAME_MAX] = {0}; 
    create_new_file_name(new_file_name, file_name, output_name, output_dir);

    // Check if file already exixted
    if (check_file_exist(new_file_name)) {
        char input[FILE_NAME_MAX];
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

    // Open file
    file = fopen(file_name, "r");
    temp = fopen(new_file_name, "w");

    clrscr();

    // Read charactor from file 
    ch = fgetc(file);
    printf("\nEncrypt file %s to %s sucessful: \n", file_name, new_file_name);
    while(ch != EOF) {
        ch = encode_character_caesar_cipher(ch, shift); // encrypt character
        fputc(ch, temp); // put to temp.txt
        printf("%c", ch);
        ch = fgetc(file); // get next character
    }

    // Close file
    fclose(file);
    fclose(temp);

    printf("\n\n");
}

void decode_caesar_cipher(char *file_name, int shift, char *output_name, char *output_dir)
{
    FILE *file = NULL;
    FILE *temp = NULL;
    char ch;
    // Get new file name and extension
    char new_file_name[FILE_NAME_MAX] = {0}; 
    create_new_file_name(new_file_name, file_name, output_name, output_dir);

    // Check if file already exixted
    if (check_file_exist(new_file_name)) {
        char input[FILE_NAME_MAX];
        printf("File %s already exixted, overwrite file (y/n)? : ", new_file_name);
        get_input_char(input);

        // Check if user want to overwrite file
        while (!strcmp(input, "y") == 0) {
            if (strcmp(input, "n") == 0) {
                return;
            }
            printf("Please type 'y' or 'n': ");
            get_input_char(input);
        }
    }

    clrscr();

    // Open file
    file = fopen(file_name, "r");
    temp = fopen(new_file_name, "w");

    // Read charactor from file 
    printf("\nDecrypt file %s to %s sucessful: \n", file_name, new_file_name);
    ch = fgetc(file);
    while(ch != EOF) {
        ch = decode_character_caesar_cipher(ch, shift); // decrypt character
        fputc(ch, temp); // put to temp.txt
        printf("%c", ch);
        ch = fgetc(file); // get next character
    }

    // Close file
    fclose(file);
    fclose(temp);

    printf("\n\n");
}

// Get file name input from keybroad and check if file name is valid 
void get_file_name(char *file_name)
{
    char pre_file_name[MAX_FILE_SIZE] = {0};
    strcpy(pre_file_name, file_name);

    // Get file name
    printf("Enter file name (or e to exit): ");
    get_input_char(file_name);
    if (strcmp(file_name, "e") == 0) {
        strcpy(file_name, pre_file_name);
        return;
    }

    // Check if file exist
    while (!check_file_exist(file_name)) {
        printf("File not exist, enter again (or e to exit): ");
        get_input_char(file_name);
        if (strcmp(file_name, "e") == 0) {
            strcpy(file_name, pre_file_name);
            return;
        }
    }
}

void change_output_name(char *output_name)
{
    char pre_file_name[FILE_NAME_MAX] = {0};

    clrscr();
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

void change_output_dir(char *output_dir)
{
    char pre_output_name[FILE_NAME_MAX] = {0};

    clrscr();
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

int get_shift_number()
{
    printf("Enter shift number: ");
    return get_input_int();
}
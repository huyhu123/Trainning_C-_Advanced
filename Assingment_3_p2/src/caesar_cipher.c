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

// Get positive interger input
static int get_input_int() 
{
    float input;

    // Check if input is valid
    while ((scanf("%f", &input) != 1 || input < 0 || input - (int)input != 0) && clean_stdin()) {
        printf("*Warning:Failed! Please enter an positive interger.Enter again:  ");
    }
    clean_stdin();

    return (int)input;
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
    while ((scanf("%f", &input) != 1 || input < 0 || input > 4 || input - (int)input != 0) && clean_stdin()) {
        printf("  *Warning:Failed! Please enter a number from 0 to 2. Enter again:  ");
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
    printf("0. Quit\n");
    printf("Your option: ");
    e_main_interface_option option = get_input_main_interface();

    return option;
}


void create_new_file_name_encode(char *new_file_name, char *file_name)
{
    char *ext = strrchr(file_name, '.');
    if (!ext) {
        ext = "";
    } else {
        ext = ext + 1;
    }

    strcpy(new_file_name, "encode_");
    //strcat(new_file_name, file_name);
    strcat(new_file_name, ".");
    strcat(new_file_name, ext);
}

void create_new_file_name_decode(char *new_file_name, char *file_name)
{
    char *ext = strrchr(file_name, '.');
    if (!ext) {
        ext = "";
    } else {
        ext = ext + 1;
    }

    strcpy(new_file_name, "decode_");
    //strcat(new_file_name, file_name);
    strcat(new_file_name, ".");
    strcat(new_file_name, ext);
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

void encode_caesar_cipher(char *file_name, int shift)
{
    FILE *file;
    FILE *temp;
    char ch;

    // Get new file name and extension
    char new_file_name[FILE_NAME_MAX]; 
    create_new_file_name_encode(new_file_name, file_name);

    // Open file
    file = fopen(file_name, "r");
    temp = fopen(new_file_name, "w");

    // Read charactor from file 
    ch = fgetc(file);
    printf("\nEncrypt file: \n");
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

void decode_caesar_cipher(char *file_name, int shift)
{
    FILE *file;
    FILE *temp;
    char ch;

    // Get new file name and extension
    char new_file_name[FILE_NAME_MAX]; 
    create_new_file_name_decode(new_file_name, file_name);

    // Open file
    file = fopen(file_name, "r");
    temp = fopen(new_file_name, "w");

    // Read charactor from file 
    printf("\nDecrypt file: \n");
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

void get_file_name(char *file_name)
{
    printf("Enter file name: ");
    get_input_char(file_name);
    // Check if file exist
    while (!check_file_exist(file_name)) {
        printf("File not exist, enter again: ");
        get_input_char(file_name);
    }
}

int get_shift_number()
{
    printf("Enter shift number: ");
    return get_input_int();
}
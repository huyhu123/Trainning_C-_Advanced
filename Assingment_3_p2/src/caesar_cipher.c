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

// Get current dir
char *get_current_directory() 
{
    char *buffer = (char*)malloc(sizeof(char) * 4096);

    if (getcwd(buffer, 4096) == NULL) {
        perror("Error getting current directory");
        free(buffer);
        return NULL;
    }

    return buffer;
}

// Check if directory exist
bool directory_exists(const char *path) {
    if (access(path, F_OK) != -1) {
        return true; // directory exists
    } else {
        return false; // directory does not exist
    }
}

bool is_validfile_name(const char *file_name) {
    // Check if the file name is empty or exceeds the maximum length
    if (strlen(file_name) == 0 || strlen(file_name) > FILE_NAME_MAX) {
        return false;
    }
    
    // Check if the file name contains any invalid characters
    const char *invalid_chars = "\\/:*?\"<>|";
    for (int i = 0; i < strlen(invalid_chars); i++) {
        if (strchr(file_name, invalid_chars[i]) != NULL) {
            return false;
        }
    }
    
    // Check if the file name starts or ends with a space or a period
    if (file_name[0] == ' ' || file_name[0] == '.' || 
        file_name[strlen(file_name)-1] == ' ' || file_name[strlen(file_name)-1] == '.') {
        return false;
    }
    
    return true;
}

void create_new_file_name(char *new_file_name, char *file_name, char *output_name, char *output_dir)
{
    char *ext = strrchr(file_name, '.');
    if (!ext) {
        ext = "";
    } else {
        ext = ext + 1;
    }

    strcpy(new_file_name, output_dir);
    strcat(new_file_name, "/");
    strcat(new_file_name, output_name);
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

void encode_caesar_cipher(char *file_name, int shift, char *output_name, char *output_dir)
{
    FILE *file;
    FILE *temp;
    char ch;

    // Get new file name and extension
    char new_file_name[FILE_NAME_MAX]; 
    create_new_file_name(new_file_name, file_name, output_name, output_dir);

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

void decode_caesar_cipher(char *file_name, int shift, char *output_name, char *output_dir)
{
    FILE *file;
    FILE *temp;
    char ch;

    // Get new file name and extension
    char new_file_name[FILE_NAME_MAX]; 
    create_new_file_name(new_file_name, file_name, output_name, output_dir);

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
    char pre_file_name[FILE_NAME_MAX];
    strcpy(pre_file_name, file_name);

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
    char pre_file_name[FILE_NAME_MAX];
    strcpy(pre_file_name, output_name);

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
    char pre_output_name[FILE_NAME_MAX];
    strcpy(pre_output_name, output_dir);

    printf("Enter new output dir (or e to exit): ");
    get_input_char(output_dir);
    if (strcmp(output_dir, "e") == 0) {
        strcpy(output_dir, pre_output_name);
        return;
    }

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
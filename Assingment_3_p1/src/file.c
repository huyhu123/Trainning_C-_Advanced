#include "file.h"

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
    FILE *file = NULL;
    if ((file = fopen(file_name, "r"))) {
        fclose(file);
        return 1;
    }
    return 0;
}

// Get file size
long get_file_size(char file_name[]) {
    FILE *fp = fopen(file_name, "r");

    if (fp == NULL)
        return -1;

    if (fseek(fp, 0, SEEK_END) < 0) {
        fclose(fp);
        return -1;
    }

    long size = ftell(fp);
    // release the resources when not required
    fclose(fp);
    return size;
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


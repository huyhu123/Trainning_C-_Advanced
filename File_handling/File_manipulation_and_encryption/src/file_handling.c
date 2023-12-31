#include "file_handling.h"

void read_from_file(char *dir, char *text)
{
    FILE *fp = NULL;
    fp = fopen(dir, "r");
    if (fp != NULL) {
        char ch;
        int index = 0;
        while ((ch = fgetc(fp)) != EOF) {
            if (ch == '\n') {
                text[index++] = '|'; // Use '|' to indicate line breaks
                text[index++] = ' ';
            } else {
                text[index++] = ch;
            }
        }
        text[index] = '\0'; // Null-terminate the string
        fclose(fp);
    }
}

void write_to_file(char *dir, char *text)
{
    FILE *fp = NULL;
    fp = fopen(dir, "w");
    fprintf(fp, "%s", text);
    fclose(fp);
}

// Check empty dir
bool check_empty_dir(const char file_name[])
{
    int index = 0;

    for (index; index < strlen(file_name); index++) {
        if (file_name[index] != '\\' && file_name[index] != '/' && file_name[index] != '.') {
            return true;
        }
    }

    return false;
}

// Check if file exist
int check_file_exist(const char file_name[])
{
    FILE *file = NULL;

    if (file_name == NULL) {
        return 0;
    }

    if (!check_empty_dir(file_name)) {
        return 0;
    }

    if ((file = fopen(file_name, "r"))) {
        fclose(file);
        return 1;
    }
    return 0;
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
bool directory_exists(const char *path) 
{
    if (access(path, F_OK) != -1) {
        return true; // directory exists
    } else {
        return false; // directory does not exist
    }
}

// Check if file name is valid
bool is_validfile_name(const char *file_name) 
{
    const char *invalid_chars = "\\/:*?\"<>|";

    // Check if the file name is empty or exceeds the maximum length
    if (strlen(file_name) == 0 || strlen(file_name) > MAX_FILE_SIZE) {
        return false;
    }
    
    // Check if the file name contains any invalid characters
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

// Create new file name with the directory and extention of old file name 
void create_new_file_name(char *new_file_name, char *file_name, char *output_name, char *output_dir)
{
    // Get file extension
    char *ext = strrchr(file_name, '.');
    if (!ext) {
        ext = "";
    } else {
        ext = ext + 1;
    }

    // Make new file name
    strcpy(new_file_name, output_dir);
    strcat(new_file_name, "/");
    strcat(new_file_name, output_name);
    strcat(new_file_name, ".");
    strcat(new_file_name, ext);
}


#include "file.h"

int main() {
    char file_name[FILE_NAME_MAX] = "";
    printf("Enter file name: ");
    get_input_char(file_name);

    // Check if file exist
    while (!check_file_exist(file_name)) {
        printf("File not exist, enter again: ");
        get_input_char(file_name);
    }

    // Print file size
    printf(
        "Size of file `%s` is %ld byte \n", 
        file_name, 
        get_file_size(file_name)
    );

    return 0;
}





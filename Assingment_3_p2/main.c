#include "caesar_cipher.h"

int main() {
    char file_name[FILE_NAME_MAX];
    printf("Enter file name: ");
    get_input_char(file_name);

    // Check if file exist
    while (!check_file_exist(file_name)) {
        printf("File not exist, enter again: ");
        get_input_char(file_name);
    }

    printf("Open file `%s`\n", file_name);
    FILE *fp = fopen(file_name, "rw");

    e_main_interface_option option = 1;
    while (option != 0)
    {
        option = show_main_interface();
        switch (option)
        {
        case e_quit:
            break;
        case e_encode:
            // Todo
            break;
        case e_decode:
            // Todo
            break;
        }
    }
    
    return 0;
}





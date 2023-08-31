#include "caesar_cipher.h"

int main() {
    char file_name[FILE_NAME_MAX];
    int shift = 0;
    e_main_interface_option option = 1;
    char output_name[FILE_NAME_MAX] = "output";
    char *current_dir = get_current_directory();

    get_file_name(file_name);
    if (!check_file_exist(file_name)) {
        return 0;
    }
    shift = get_shift_number();
    clrscr();

    while (option != 0)
    {
        printf("----------------------------------------\n");
        printf("Open file: `%s`\n", file_name);
        printf("Shift: %i\n", shift);
        printf("Save directory: %s\n", current_dir);
        printf("Output file name: %s\n", output_name);
        printf("----------------------------------------\n");

        option = show_main_interface();
        switch (option)
        {
        case e_quit:
            break;
        case e_encode:
            clrscr();
            encode_caesar_cipher(file_name, shift, output_name, current_dir);
            break;
        case e_decode:
            clrscr();
            decode_caesar_cipher(file_name, shift, output_name, current_dir);
            break;
        case e_change_file:
            get_file_name(file_name);
            clrscr();
            break;
        case e_change_shift:
            shift = get_shift_number();
            clrscr();
            break;
        case e_change_output_name:
            change_output_name(output_name);
            clrscr();
            break;
        case e_change_output_dir:
            change_output_dir(current_dir);
            clrscr();
            break;
        }
    }

    free(current_dir);
    return 0;
}





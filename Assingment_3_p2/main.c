#include "caesar_cipher.h"

int main() {
    char file_name[FILE_NAME_MAX];
    int shift = 0;
    e_main_interface_option option = 1;
    char output_name[FILE_NAME_MAX] = "output";

    get_file_name(file_name);
    shift = get_shift_number();
    clrscr();

    while (option != 0)
    {
        printf("Open file `%s`\n", file_name);
        printf("Shift: `%i`\n", shift);
        option = show_main_interface();
        switch (option)
        {
        case e_quit:
            break;
        case e_encode:
            encode_caesar_cipher(file_name, shift, output_name);
            break;
        case e_decode:
            decode_caesar_cipher(file_name, shift, output_name);
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
            break;
        }
    }

    return 0;
}





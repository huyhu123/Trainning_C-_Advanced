#include "cryptography.h"
#include "interface.h"

int main() {
    char *out_dir = get_current_directory();
    char out_name[MAX_STRING_SIZE] = "out";

    if (!init_cryptography("morse_code_key.txt")) {
        return 0;
    }

    e_main_interface_option option = 1;
    while (option != 0)
    {
        option = show_main_UI(out_dir, out_name);
        switch (option)
        {
            case e_quit:
                break;
            case e_encode:
                clrscr();
                choose_encode_text_option(out_dir, out_name);
                break;
            case e_decode:
                clrscr();
                choose_decode_text_option(out_dir, out_name);
                break;
            case e_encode_file:
                clrscr();
                choose_encode_file_option(out_dir, out_name);
                break;
            case e_decode_file:
                clrscr();
                choose_decode_file_option(out_dir, out_name);
                break;
            case e_change_output_name:
                clrscr();
                change_output_name(out_name);
                break;
            case e_change_output_dir:
                clrscr();
                change_output_dir(out_dir);
                break;
        }
    }

    free(out_dir);
    out_dir = NULL;
    destroy_cryptography();

    return 0;
}





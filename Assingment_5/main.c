#include "cryptography.h"
#include "interface.h"

int main() {
    init_cryptography();
    char out_dir[MAX_STRING_SIZE] = "out.txt";

    e_main_interface_option option = 1;
    while (option != 0)
    {
        option = show_main_UI();
        switch (option)
        {
        case e_quit:
            break;
        case e_encode:
            clrscr();
            choose_encode_text_option(out_dir);
            break;
        case e_decode:
            clrscr();
            choose_decode_text_option(out_dir);
            break;
        case e_encode_file:
            clrscr();
            choose_encode_file_option(out_dir);
            break;
        case e_decode_file:
            clrscr();
            //choose_decode_file_option();
            break;
        }
    }

    destroy_cryptography();

    return 0;
}





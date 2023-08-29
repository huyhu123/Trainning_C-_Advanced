#ifndef _CAESAR_CIPHER_H_
#define _CAESAR_CIPHER_H_

#ifdef _WIN32
#include <conio.h>
#else
#define clrscr() printf("\e[1;1H\e[2J")
#endif

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define FILE_NAME_MAX 50

typedef enum {
    e_quit = 0x00U,
    e_encode = 0x01U,
    e_decode = 0x02U,
} e_main_interface_option;

void get_input_char(char input[]);

int check_file_exist(const char file_name[]);

e_main_interface_option show_main_interface();

#endif

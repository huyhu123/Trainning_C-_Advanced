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
#include <ctype.h>
#include <unistd.h>
#include <stdlib.h>

#define FILE_NAME_MAX 255

typedef enum {
    e_quit = 0x00U,
    e_encode = 0x01U,
    e_decode = 0x02U,
    e_change_file = 0x03U,
    e_change_shift = 0x04U,
    e_change_output_name = 0x05U,
    e_change_output_dir = 0x06U,
} e_main_interface_option;

void get_input_char(char input[]);

int check_file_exist(const char file_name[]);

e_main_interface_option show_main_interface();

void encode_caesar_cipher(char *file_name, int shift, char *output_name, char *output_dir);

void decode_caesar_cipher(char *file_name, int shift, char *output_name, char *output_dir);

void get_file_name(char *file_name);

int get_shift_number();

void change_output_name(char *output_name);

char *get_current_directory();

void change_output_dir(char *output_dir);

#endif

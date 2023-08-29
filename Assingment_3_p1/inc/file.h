#ifndef _FILE_H_
#define _FILE_H_

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define FILE_NAME_MAX 100

long get_file_size(char file_name[]);

void get_input_char(char file_name[]);

int check_file_exist(const char file_name[]);

#endif

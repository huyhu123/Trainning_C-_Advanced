#ifndef _FILE_HANDLING_H_
#define _FILE_HANDLING_H_

#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_FILE_SIZE 255

void read_from_file(char *dir, char *text);

void write_to_file(char *dir, char *text);

bool check_empty_dir(const char file_name[]);

int check_file_exist(const char file_name[]);

char *get_current_directory();

bool directory_exists(const char *path);

bool is_validfile_name(const char *file_name);

void create_new_file_name(char *new_file_name, char *file_name, char *output_name, char *output_dir);

#endif

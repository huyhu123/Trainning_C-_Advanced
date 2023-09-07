#ifndef _CRYPTOGRAPHY_H_
#define _CRYPTOGRAPHY_H_

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
#include "binary_tree.h"

#define COUNT               5
#define MAX_STRING_SIZE     1000

char* decode_morse(char *morse);

void encode_morse(char *text, char *decode_text);

void destroy_cryptography(); 

bool init_cryptography(char *morse_code_key);

#endif

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

/**
 * @brief Decodes a Morse code into plain text.
 *
 * @param morse The Morse code to be decoded.
 * @return A pointer to the decoded plain text.
 */
char* decode_morse(char *morse);

/**
 * @brief Encodes plain text into Morse code.
 *
 * @param text The plain text to be encoded.
 * @param decode_text The output buffer to store the encoded Morse code.
 */
void encode_morse(char *text, char *decode_text);

/**
 * @brief Destroys any resources allocated for the cryptography module.
 */
void destroy_cryptography(); 

/**
 * @brief Initializes the cryptography module with the given Morse code key.
 *
 * @param morse_code_key The Morse code key to be used for encoding and decoding.
 * @return true if the initialization is successful, false otherwise.
 */
bool init_cryptography(char *morse_code_key);

#endif

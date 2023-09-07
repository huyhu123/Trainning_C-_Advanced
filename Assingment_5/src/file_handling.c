#include "file_handling.h"

void read_from_file(char *dir, char *text)
{
    FILE *fp;
    fp = fopen(dir, "r");
    if (fp != NULL) {
        char ch;
        int index = 0;
        while ((ch = fgetc(fp)) != EOF) {
            if (ch == '\n') {
                text[index++] = '|'; // Use '|' to indicate line breaks
                text[index++] = ' ';
            } else {
                text[index++] = ch;
            }
        }
        text[index] = '\0'; // Null-terminate the string
        fclose(fp);
    }
}

void write_to_file(char *dir, char *text)
{
    FILE *fp;
    fp = fopen(dir, "w");
    fprintf(fp, "%s", text);
    fclose(fp);
}

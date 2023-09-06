#include "file_handling.h"

void read_from_file(char *dir, char *text)
{
    FILE *fp;
    fp = fopen(dir, "r");
    fgets(text, MAX_FILE_SIZE, fp);
    fclose(fp);
}

void write_to_file(char *dir, char *text)
{
    FILE *fp;
    fp = fopen(dir, "w");
    fprintf(fp, "%s", text);
    fclose(fp);
}

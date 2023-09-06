#include "interface.h"

void write_to_file(char *dir, char *text)
{
    FILE *fp;
    fp = fopen(dir, "w");
    fprintf(fp, "%s", text);
    fclose(fp);
}
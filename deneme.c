#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
char *ltrim(char *str, const char *seps);
char *trim(char *str, const char *seps);
char *rtrim(char *str, const char *seps);
int main(void)
{
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    char delim[] = "#\n";
    fp = fopen("deneme.txt", "r");
    if (fp == NULL) {
        printf("yunus");
        exit(EXIT_FAILURE);
    }
    int satir=0;
    while ((read = getline(&line, &len, fp)) != -1) {
        char *ptr = strtok(line, delim);
        while(ptr != NULL) {
            printf("%d",satir);

            trim(ptr, NULL);
            printf("'%s'\n", ptr);
            char  *type = ptr;
            if (satir == 0) {
                if (strcmp(ptr, "E") == 0) {
                    printf("Encyclopedia\n");
                    ptr = strtok(NULL, delim);

                } else if (strcmp(ptr, "B") == 0) {
                    printf("Book\n");
                    ptr = strtok(NULL, delim);

                } else if (strcmp(ptr, "P") == 0) {
                    printf("Periodical\n");
                    ptr = strtok(NULL, delim);
                }
            }
            satir++;

        }
        satir=0;
    }

    fclose(fp);
    if (line)
        free(line);
    exit(EXIT_SUCCESS);
}

char *trim(char *str, const char *seps)
{
    return ltrim(rtrim(str, seps), seps);
}


char *ltrim(char *str, const char *seps) {
    size_t totrim;
    if (seps == NULL) {
        seps = "\t\n\v\f\r ";
    }
    totrim = strspn(str, seps);
    if (totrim > 0) {
        size_t len = strlen(str);
        if (totrim == len) {
            str[0] = '\0';
        }
        else {
            memmove(str, str + totrim, len + 1 - totrim);
        }
    }
    return str;
}

char *rtrim(char *str, const char *seps) {
    int i;
    if (seps == NULL) {
        seps = "\t\n\v\f\r ";
    }
    i = strlen(str) - 1;
    while (i >= 0 && strchr(seps, str[i]) != NULL) {
        str[i] = '\0';
        i--;
    }
    return str;
}

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
    char  *inf1;
    char  *inf2;
    char  *inf5;
    char  *inf4;
    char  *inf3;
    char  *inf6;

    while ((read = getline(&line, &len, fp)) != -1) {
        char *ptr = strtok(line, delim);

            trim(ptr, NULL);
            printf("\n");
            inf1 = ptr;

                if (strcmp(inf1, "E") == 0) {
                    printf("Encyclopedia\n");
                    ptr = strtok(NULL, delim);
                    trim(ptr, NULL);
                    inf2=ptr;
                    ptr = strtok(NULL, delim);
                    trim(ptr, NULL);
                    inf3=ptr;
                    ptr = strtok(NULL, delim);
                    trim(ptr, NULL);
                    inf4=ptr;
                    ptr = strtok(NULL, delim);
                    trim(ptr, NULL);
                    inf5=ptr;
                    printf("Type: %s, Name: %s, Publisher: %s, Price: %s, Isinstock: %s",inf1,inf2,inf3,inf4,inf5);

                } else if (strcmp(inf1, "B") == 0) {
                    printf("Book\n");
                    ptr = strtok(NULL, delim);
                    trim(ptr, NULL);
                    inf2=ptr;
                    ptr = strtok(NULL, delim);
                    trim(ptr, NULL);
                    inf3=ptr;
                    ptr = strtok(NULL, delim);
                    trim(ptr, NULL);
                    inf4=ptr;
                    ptr = strtok(NULL, delim);
                    trim(ptr, NULL);
                    inf5=ptr;
                    printf("Type: %s, Name: %s, Author: %s, Price: %s, Isinstock: %s",inf1,inf2,inf3,inf4,inf5);
                } else if (strcmp(inf1, "P") == 0) {
                    printf("Periodical\n");
                    ptr = strtok(NULL, delim);
                    trim(ptr, NULL);
                    inf2=ptr;
                    ptr = strtok(NULL, delim);
                    trim(ptr, NULL);
                    inf3=ptr;
                    ptr = strtok(NULL, delim);
                    trim(ptr, NULL);
                    inf4=ptr;
                    ptr = strtok(NULL, delim);
                    trim(ptr, NULL);
                    inf5=ptr;
                    ptr = strtok(NULL, delim);
                    trim(ptr, NULL);
                    inf6=ptr;
                    printf("Type: %s, Name: %s, Editor: %s, Price: %s, Isinstock: %s, VolNo: %s",inf1,inf2,inf3,inf4,inf5,inf6);
                }

    }
    printf("\n");
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

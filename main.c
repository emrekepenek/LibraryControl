#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include <memory.h>


typedef struct Book
{
    char Name[60];
    char Author[40];
    int Price;
    bool IsInStock;
    union Library_type *next;
}Book;
typedef struct Periodical
{
    char Name[60];
    char Editor[40];
    float Price;
    bool IsInStock;
    int VolNo;
    union Library_type *next;
}Periodical ;
typedef struct Encyclopedia
{
    char Name [60];
    char Publisher[40];
    int Price;
    bool IsInStock;
    union Library_type *next;
}Encyclopedia ;

enum type{boo , encycloped , peripcdica};

union Library_type{
    Book *book;
    Periodical *periodical;
    Encyclopedia *encyclopedia;
    enum type tip;
} ;


union Library_type *head=NULL, *last=NULL;



void print_linked_list();
void insert_at_last(int value);
void insert_at_first(int value);
void insert_after(int key, int value);
void delete_item(int value);
void search_item(int value);

void insert_at_last_Book(char *inf2,char *inf3,char *inf4,char *inf5);
char *ltrim(char *str, const char *seps);
char *trim(char *str, const char *seps);
char *rtrim(char *str, const char *seps);

int main()
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

            printf("Type: %s, Name: %s, Publisher: %s, Price: %s, Isinstock: %s \n",inf1,inf2,inf3,inf4,inf5);

            Encyclopedia *encyclopedia;
            encyclopedia = (Encyclopedia *) malloc(sizeof(Encyclopedia));
            strcpy(encyclopedia->Name,inf2);
            strcpy(encyclopedia->Publisher,inf3);
            int price = atoi(inf4);
            encyclopedia->Price=price;
            if (strcmp(inf5,"F")==0){
                encyclopedia->IsInStock=false;
            }else if (strcmp(inf5,"T")==0){
                encyclopedia->IsInStock=true;
            }

            if(head==NULL){
                head = malloc(sizeof(union Library_type));
                head->encyclopedia=encyclopedia;
                encyclopedia->next=last;
            }

            printf("%s",head->encyclopedia->Name);

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
            printf("Type: %s, Name: %s, Author: %s, Price: %s, Isinstock: %s \n",inf1,inf2,inf3,inf4,inf5);

            insert_at_last_Book(inf2,inf3,inf4,inf5);

            printf("%i",head->book->Price);

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
            printf("Type: %s, Name: %s, Editor: %s, Price: %s, Isinstock: %s, VolNo: %s \n",inf1,inf2,inf3,inf4,inf5,inf6);

            Periodical *periodical;
            periodical = (Periodical *) malloc(sizeof(Periodical));
            strcpy(periodical->Name,inf2);
            strcpy(periodical->Editor,inf3);
            float price = atof(inf4);
            periodical->Price=price;
            if (strcmp(inf5,"F")==0){
                periodical->IsInStock=false;
            }else if (strcmp(inf5,"T")==0){
                periodical->IsInStock=true;
            }
            int volNo = atoi(inf6);
            periodical->VolNo=volNo;

            if(head==NULL){
                head = malloc(sizeof(union Library_type));
                head->periodical=periodical;
                periodical->next=last;
            }

            printf("%.2f",head->periodical->Price);
        }

    }
    printf("\n");
    fclose(fp);
    if (line)
        free(line);

    return 0;
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

void insert_at_last_Book(char *inf2,char *inf3,char *inf4,char *inf5){

    Book *book;
    book = (Book *) malloc(sizeof(Book));
    strcpy(book->Name,inf2);
    strcpy(book->Author,inf3);
    int price = atoi(inf4);
    book->Price=price;
    if (strcmp(inf5,"F")==0){
        book->IsInStock=false;
    }else if (strcmp(inf5,"T")==0){
        book->IsInStock=true;
    }

    if(head==NULL){
        head = malloc(sizeof(union Library_type));
        head->book=book;
        book->next=last;
        head->tip=boo;
    }
    else{

    }
    printf("%s",head->book->Name);

}

/*
    User Defined Functions
*/


#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <stdbool.h>
enum type{bookE , encyclopediaE, periodicalE};
union AutEditPub{
    char Author[40];
    char Editor[40];
    char Publisher[40];
} ;
union Price{
    int iPrice;
    float fPrice;
} ;
typedef struct Type
{
    char Name[60];
    union AutEditPub writer;
    union Price price;
    bool IsInStock;
    struct Type  *next;
    int VolNo;
    enum type tip;
}Type;


char *ltrim(char *str, const char *seps);
char *trim(char *str, const char *seps);
char *rtrim(char *str, const char *seps);
void insert_at_last_Book(char *inf2,char *inf3,char *inf4,char *inf5);
void insert_at_last_Periodical(char *inf2,char *inf3,char *inf4,char *inf5,char *inf6);
void insert_at_last_Encyclopedia(char *inf2,char *inf3,char *inf4,char *inf5);
void printList(int i);
void printSmallestI(int i);
void deleteSmallestI(int i);
void consoleInsertion();
void size();
void save();

Type *head =NULL , *last =NULL;
int sizeList=0;
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
                    //printf("Type: %s, Name: %s, Publisher: %s, Price: %s, Isinstock: %s \n",inf1,inf2,inf3,inf4,inf5);

                    insert_at_last_Encyclopedia(inf2,inf3,inf4,inf5);

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
                    //printf("Type: %s, Name: %s, Author: %s, Price: %s, Isinstock: %s",inf1,inf2,inf3,inf4,inf5);

                    insert_at_last_Book(inf2,inf3,inf4,inf5);

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
                    //printf("Type: %s, Name: %s, Editor: %s, Price: %s, Isinstock: %s, VolNo: %s",inf1,inf2,inf3,inf4,inf5,inf6);

                    insert_at_last_Periodical(inf2,inf3,inf4,inf5,inf6);
                }

    }
    printf("\n");
    printList(sizeList);
    consoleInsertion();
    printf("\n");
    printList(sizeList);

    save();

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

void insert_at_last_Book(char *inf2,char *inf3,char *inf4,char *inf5){

    Type *book;
    book = (Type *) malloc(sizeof(Type));
    book->tip=bookE;
    strcpy(book->Name,inf2);
    strcpy( book->writer.Author,inf3);
    int price = atoi(inf4);
    book->price.iPrice=price;
    if (strcmp(inf5,"F")==0){
        book->IsInStock=false;
    }else if (strcmp(inf5,"T")==0){
        book->IsInStock=true;
    }

    if(head==NULL){
        head = malloc(sizeof(Type));
        head->next=book;
        book->next=last;
    }
    else{
        Type *temp=head;
        while(temp->next!=NULL){
            if(strcmp(temp->next->Name,book->Name)>=0){
                break;
            }
            temp=temp->next;
        }
        Type *next;
        next=temp->next;

        temp->next=book;
        book->next=next;

    }
    sizeList++;

}
void insert_at_last_Encyclopedia(char *inf2,char *inf3,char *inf4,char *inf5){

    Type *encyclopedia;
    encyclopedia = (Type *) malloc(sizeof(Type));
    encyclopedia->tip=encyclopediaE;
    strcpy(encyclopedia->Name,inf2);
    strcpy( encyclopedia->writer.Publisher,inf3);
    int price = atoi(inf4);
    encyclopedia->price.iPrice=price;
    if (strcmp(inf5,"F")==0){
        encyclopedia->IsInStock=false;
    }else if (strcmp(inf5,"T")==0){
        encyclopedia->IsInStock=true;
    }

    if(head==NULL){
        head = malloc(sizeof(Type));
        head->next=encyclopedia;
        encyclopedia->next=last;
    }
    else{
        Type *temp=head;
        while(temp->next!=NULL){
            if(strcmp(temp->next->Name,encyclopedia->Name)>=0){
                break;
            }
            temp=temp->next;
        }
        Type *next;
        next=temp->next;

        temp->next=encyclopedia;
        encyclopedia->next=next;

    }
    sizeList++;

}
void insert_at_last_Periodical(char *inf2,char *inf3,char *inf4,char *inf5,char *inf6){
    Type *periodical;
    periodical = (Type *) malloc(sizeof(Type));
    periodical->tip=periodicalE;
    strcpy(periodical->Name,inf2);
    strcpy( periodical->writer.Editor,inf3);
    float price = atoff(inf4);
    periodical->price.fPrice=price;
    if (strcmp(inf5,"F")==0){
        periodical->IsInStock=false;
    }else if (strcmp(inf5,"T")==0){
        periodical->IsInStock=true;
    }
    periodical->VolNo=atoi(inf6);
    if(head==NULL){
        head = malloc(sizeof(Type));
        head->next=periodical;
        periodical->next=last;
    }
    else{
        Type *temp=head;


        while(temp->next!=NULL){
            if(strcmp(temp->next->Name,periodical->Name)>=0){
                break;
            }
            temp=temp->next;
        }
        Type *next;
        next=temp->next;

        temp->next=periodical;
        periodical->next=next;
    }
    sizeList++;

}
void printList(int i){

    if(head!=NULL) {
        if(head->next!=NULL) {
            Type *temp = head->next;
            while (temp != NULL&&i>0) {
                int which = temp->tip;
                if(which==0){
                    printf("Name:%s ,Author:%s ,Price%i ,Isinstock:%s \n", temp->Name,
                           temp->writer.Author,temp->price.iPrice,temp->IsInStock ? "true" : "false");
                }
                else if(which==1){
                    printf("Name:%s ,Publisher:%s ,Price%i ,Isinstock:%s \n", temp->Name,
                           temp->writer.Publisher,temp->price.iPrice,temp->IsInStock ? "true" : "false");
                }
                else if(which==2){
                    printf("Name:%s ,Editor:%s ,Price%f ,Isinstock:%s ,VolNo:%i \n", temp->Name,
                           temp->writer.Editor,temp->price.fPrice,temp->IsInStock ? "true" : "false",temp->VolNo);
                }
                temp = temp->next;
                i--;
            }
        }
    }
    printf("%i \n",sizeList);
}

void printSmallestI(int i){

    if(sizeList<i){
        printf("There in not %i input in the list.Size of the list is %i",i,sizeList);
        return;
    }
    if(head!=NULL) {
        if(head->next!=NULL) {
            Type *temp = head->next;
            i--;
            while (temp != NULL&&i>0) {

                temp = temp->next;
                i--;
            }

            int which = temp->tip;
            if(which==0){
                printf("Name:%s ,Author:%s ,Price%i ,Isinstock:%s \n", temp->Name,
                       temp->writer.Author,temp->price.iPrice,temp->IsInStock ? "true" : "false");
            }
            else if(which==1){
                printf("Name:%s ,Publisher:%s ,Price%i ,Isinstock:%s \n", temp->Name,
                       temp->writer.Publisher,temp->price.iPrice,temp->IsInStock ? "true" : "false");
            }
            else if(which==2){
                printf("Name:%s ,Editor:%s ,Price%f ,Isinstock:%s ,VolNo:%i \n", temp->Name,
                       temp->writer.Editor,temp->price.fPrice,temp->IsInStock ? "true" : "false",temp->VolNo);
            }
        }
    }
}

void deleteSmallestI(int i){


    if(sizeList<i){
        printf("There in not %i input in the list.Size of the list is %i",i,sizeList);
        return;
    }
    if(head!=NULL) {
        if(head->next!=NULL) {
            Type *temp = head->next;
            i--;
            while (temp != NULL&&i>1) {

                temp = temp->next;
                i--;
            }
            Type *del;
            del=temp->next;
            Type *next;
            next=del->next;
            temp->next=next;
            del->next=NULL;
            free(del);
            sizeList--;
        }
    }
}
void consoleInsertion(){
    printf("Please enter your  insertion as in the inputbookdb.txt \n");
    char  line[200];
    fgets(line, 200, stdin);
    char  *inf1;
    char  *inf2;
    char  *inf5;
    char  *inf4;
    char  *inf3;
    char  *inf6;
    char delim[] = "#\n";
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
        //printf("Type: %s, Name: %s, Publisher: %s, Price: %s, Isinstock: %s \n",inf1,inf2,inf3,inf4,inf5);

        insert_at_last_Encyclopedia(inf2,inf3,inf4,inf5);

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
        //printf("Type: %s, Name: %s, Author: %s, Price: %s, Isinstock: %s",inf1,inf2,inf3,inf4,inf5);

        insert_at_last_Book(inf2,inf3,inf4,inf5);

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
        //printf("Type: %s, Name: %s, Editor: %s, Price: %s, Isinstock: %s, VolNo: %s",inf1,inf2,inf3,inf4,inf5,inf6);

        insert_at_last_Periodical(inf2,inf3,inf4,inf5,inf6);
    }
}
void size(){
    printf("%i",sizeList);
}
void save(){
    FILE * fp;
    int i;
    /* open the file for writing*/
    fp = fopen ("”outputbookdb.txt","w");


    if(head!=NULL) {
        if(head->next!=NULL) {
            Type *temp = head->next;
            while (temp != NULL) {
                int which = temp->tip;
                if(which==0){
                    fprintf(fp,"B # Name:%s ,Author:%s ,Price%i ,Isinstock:%s \n", temp->Name,
                           temp->writer.Author,temp->price.iPrice,temp->IsInStock ? "true" : "false");
                }
                else if(which==1){
                    fprintf(fp,"E # Name:%s ,Publisher:%s ,Price%i ,Isinstock:%s \n", temp->Name,
                           temp->writer.Publisher,temp->price.iPrice,temp->IsInStock ? "true" : "false");
                }
                else if(which==2){
                    fprintf(fp,"P # Name:%s ,Editor:%s ,Price%f ,Isinstock:%s ,VolNo:%i \n", temp->Name,
                           temp->writer.Editor,temp->price.fPrice,temp->IsInStock ? "true" : "false",temp->VolNo);
                }
                temp = temp->next;

            }
        }
    }

    fclose (fp);
}
#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>


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
    int Price;
    bool IsInStock;
    int VolNo;
    union Library_type *next;
}Periodical ;
typedef struct Encyclopedia
{
    char Name[60];
    char Publisher[40];
    int Price;
    bool IsInStock;
    union Library_type *next;
}Encyclopedia ;

union Library_type{
    Book *book;
    Periodical *periodical;
    Encyclopedia *encyclopedia;

} ;



union Library_type *head=NULL, *last=NULL;



void print_linked_list();
void insert_at_last(int value);
void insert_at_first(int value);
void insert_after(int key, int value);
void delete_item(int value);
void search_item(int value);

int main()
{
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen("deneme.txt", "r");
    if (fp == NULL) {
        printf("yunus");
        exit(EXIT_FAILURE);
    }
    while ((read = getline(&line, &len, fp)) != -1) {
        printf("Retrieved line of length %zu:\n", read);
        printf("%s", line);
    }

    int key, value;

    //Insert value at last position to existing Linked List
    printf("\nInsert new item at last\n");
    scanf("%d", &value);
    insert_at_last(value);
    print_linked_list();


    //Insert value at first position to existing Linked List
    printf("\nInsert new item at first\n");
    scanf("%d", &value);
    insert_at_first(value);
    print_linked_list();


    //Insert value after a defined value to existing Linked List
    printf("\nEnter a KEY (existing item of List), after that you want to insert a value\n");
    scanf("%d", &key);
    printf("\nInsert new item after %d KEY\n", key);
    scanf("%d", &value);
    insert_after(key, value);
    print_linked_list();


    //Search an item from Linked List
    printf("\nEnter an item to search it from List\n");
    scanf("%d", &value);
    search_item(value);


    //Delete value from List
    printf("\nEnter a value, which you want to delete from list\n");
    scanf("%d", &value);
    delete_item(value);
    print_linked_list();


    //fclose() is used to close the file
    fclose(fp);

    return 0;
}


/*
    User Defined Functions
*/

void insert_at_last(int value)
{
    node *temp_node;
    temp_node = (node *) malloc(sizeof(node));

    temp_node->number=value;
    temp_node->next=NULL;

    //For the 1st element
    if(head==NULL)
    {
        head=temp_node;
        last=temp_node;
    }
    else
    {
        last->next=temp_node;
        last=temp_node;
    }

}


void insert_at_first(int value)
{
    node *temp_node = (node *) malloc(sizeof(node));

    temp_node->number=value;
    temp_node->next = head;

    head = temp_node;
}

void insert_after(int key, int value)
{
    node *myNode = head;
    int flag = 0;

    while(myNode!=NULL)
    {
        if(myNode->number==key)
        {
            node *newNode = (node *) malloc(sizeof(node));
            newNode->number = value;
            newNode->next = myNode->next;
            myNode->next = newNode;

            printf("%d is inserted after %d\n", value, key);

            flag = 1;


            break;
        }
        else
            myNode = myNode->next;
    }

    if(flag==0)
        printf("Key not found!\n");

}


void delete_item(int value)
{
    node *myNode = head, *previous=NULL;
    int flag = 0;

    while(myNode!=NULL)
    {
        if(myNode->number==value)
        {
            if(previous==NULL)
                head = myNode->next;
            else
                previous->next = myNode->next;

            printf("%d is deleted from list\n", value);

            flag = 1;
            free(myNode); //need to free up the memory to prevent memory leak
            break;
        }

        previous = myNode;
        myNode = myNode->next;
    }

    if(flag==0)
        printf("Key not found!\n");
}


void search_item(int value)
{
    node *searchNode = head;
    int flag = 0;

    while(searchNode!=NULL)
    {
        if(searchNode->number==value)
        {
            printf("%d is present in this list. Memory address is %d\n", value, searchNode);
            flag = 1;
            break;
        }
        else
            searchNode = searchNode->next;
    }

    if(flag==0)
        printf("Item not found\n");

}


void print_linked_list()
{
    printf("\nYour full linked list is\n");

    node *myList;
    myList = head;

    while(myList!=NULL)
    {
        printf("%d ", myList->number);

        myList = myList->next;
    }
    puts("");
}

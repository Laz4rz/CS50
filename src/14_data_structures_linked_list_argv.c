// CS50 Lecture 5 - Linked lists argv

#include <stdio.h>
#include <stdlib.h>

/*
. is used when there is a direct access to a variable in the structure
-> is used when you are accessing a variable of a structure through a pointer to that structure.
*/

typedef struct node
{
    int number;
    struct node* next;
}
node;

// new numbers are added to the end of the list, 
int main(int argc, char* argv[]) // argc is always at least 1 as program name is argv[0]
{
    // initialize list as null 
    node *list = NULL;
    printf("Adress on which the list points after init: %s, %d, %p\n", list, list, list);
    printf("Adress of this pointer: %p\n", &list);

    for (int i = 1; i < argc; i++)
    {
        // allocate memory for a new node
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return 1;
        }

        // new node creation
        n->number = atoi(argv[i]); // atoi - string to int
        n->next = NULL;

        // append new node to list
        n->next = list;
        list = n;
    }

    // print all list values
    node* ptr = list;
    while (ptr != NULL)
    {
        printf("%i", ptr->number);
        ptr = ptr->next;
    }
    printf("\n");

    /*     
    different way of printing

    for (node *ptr = list; ptr != NULL; ptr = ptr->next)
    {
        printf("%i\n", ptr->number);
    } 
    */

    // freeing all allocated memory
    ptr = list;
    while (ptr != NULL)
    {
        node *ptr_next = ptr->next;
        free(ptr);
        ptr = ptr_next;
    } 
}

// CS50 Lecture 5 - Linked lists FIFO argv

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

// new numbers are added to the start of the list - First in first out implementation
int main(int argc, char* argv[]) // argc is always at least 1 as program name is argv[0]
{
    // initialize list as null 
    node *list = NULL;
    printf("Adress on which the list points after init: %s, %d, %p\n", list, list, list);
    printf("Adress of this pointer: %p\n", &list);

    node* ptr;
    int counter;
    for (int i = 1; i < argc; i++)
    {
        // allocate memory for a new node
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return 1;
        }

        // new node creation
        printf("Adress of %i node is: %p\n", i, n);
        n->number = atoi(argv[i]); // atoi - string to int
        n->next = NULL;

        // append new node to list or first if list is empty
        if (list == NULL)
        {
            list = n;
        }
        else
        {
            node* tmp;
            ptr = list;
            if (ptr->number >= n->number)
            {
                tmp = list;
                list = n;
                n->next = tmp;
            }
            else
            {
                for (node* ptr = list; ptr != NULL; ptr = ptr->next)
                {
                    printf("%i here\n", n->number);
                    if (ptr->next->number >= n->number)
                    {
                        tmp = ptr->next;
                        ptr->next = n;
                        n->next = tmp;
                        break;
                    }
                    else if (ptr->next == NULL)
                    {   
                        ptr->next = n;\
                        break;
                    }
                }
            }
            
        }
    }

    // print all list values
    ptr = list;
    printf("Array values: \n");
    while (ptr != NULL)
    {
        printf("%i ", ptr->number);
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

    printf("Freed memory and finished\n");
}


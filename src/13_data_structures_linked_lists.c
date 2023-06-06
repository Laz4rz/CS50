// CS50 Lecture 5 - Linked lists

/*
Linked list is a dynamic structure, consisting of nodes (value, pointer to next)

Linked lists elements are not usually next to each other in memory

Each node of a linked list stores some value and a pointer that points to the next
node

Last node has NULL instead of a pointer

Linked list starts with a one element node - pointer to first value node

They are not fun to read - even knowing index of value we want to retrieve, we still
have to iterate over whole list as we have no idea where in memory it is, so its
pointer has to be found

it has to be linearly searched, to find n-th element we have to go over n-1 elements
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node // alias for "struct node" is "node" thats why inside of declaration whole name is needed
{
    int number;
    struct node *next;
}
node;

int main(void)
{
    // list is initialized with garbage value
    node *list;

    // initializing n node with sizeof(node)
    node *n = malloc(sizeof(node));

    // setting number of node
    n->number = 1;
    n->next = NULL;

    // list
    list = n;

    // new node
    node *n = malloc(sizeof(node)); // allocate memory for node struct
    n->number = 2; // assign 2 to nodes number
    n->next = list; // point the nodes next to the last list element 
    list = n; // update list pointer to second node

}
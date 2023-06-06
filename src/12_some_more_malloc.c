#include <stdio.h>
#include <stdlib.h>

// const int CAPACITY = 50;

// typedef struct 
// {
//     person people[CAPACITY];
//     int size;
// }
// stack;

void print_int_array(int* array, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%i", array[i]);
    }
    printf("\n");
}

int main(void)
{
    // initializing list of size 3
    int *list = malloc(3 * sizeof(int));
    printf("Adress of list  variable after initializing: %p\n", list);
    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    // initializing list2 of size 4
    int *list2 = malloc(4 * sizeof(int));
    printf("Adress of list2 variable after initializing: %p\n", list2);
    if (list2 == NULL) // malloc and other functions may return NULL if something went wrong during the execution, we can check whether variable is NULL to know if everything went ok
    {
        free(list); // for the memory not to leak before crashing
        return 1;
    }

    // Copying values between list and list2
    for (int i = 0; i < 3; i++)
    {
        list2[i] = list[i];
    }

    // freeing and reassigning list to list2
    free(list);
    printf("Adress of list  variable after freeing: %p\n", list);

    list2[3] = 4;

    list = list2;
    printf("Adress of list  variable after list = list2: %p\n", list);

    // print arrays
    printf("list :");
    print_int_array(list, 4);
    printf("list2:");
    print_int_array(list2, 4);
    printf("\n");

    // change value of list2[2]
    list2[2] = 9;
    printf("Value of list has changed, list is also changed as they point to the same adress\n");

    // print arrays again
    printf("list :");
    print_int_array(list, 4);
    printf("list2:");
    print_int_array(list2, 4);
    printf("\n");

    // check size of list before freeing
    printf("Size of list before freeing: %lu\n", sizeof(list));

    // free pointer, only one cause list and list2 have the same adress now
    free(list2);
    list = NULL; // marking freed pointers as NULL is a good practice
    list2 = NULL;

    // check size of list after freeing 
    printf("Size of list after freeing: %lu\n", sizeof(list));
    printf("\n");

    // print arrays after freeing
    printf("Insides of list and list2 after freeing \n");
    printf("list :");
    print_int_array(list, 4);
    printf("list2:");
    print_int_array(list2, 4);

    /*
    realloc can be used to move memory between arrays allocated with different sizes

    having list as above, we can do:
    int* list2 = realloc(list, 4*sizeof(int))

    and all of the above copying is needless 
    */
}

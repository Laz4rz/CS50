// CS50 Lecture 4 - adresses and pointers

#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    int n = 50;
    printf("n = %i\n", n);

    /* 
    & Provides the address of something stored in memory
    * Instructs the compiler to go to a location in memory
    */

    printf("Pointer to n is %p\n", &n);

    /* 
    Adresses are written in hexadecimal form
    pointer is a variable attribute and can be obtained by writing &variable

    pointers are defined by: type *variable_pointer_name = &variable

    pointers are usually stored as 8-byte values (int - 4-byte)
    */

    int *p_n = &n;
    printf("Pointer to n is: %p\n", p_n);
   
    printf("Pointer p_n can be displayed in two ways: *p_n=%i and p_n=%p \n", *p_n, p_n);

    /*
    variable used to define a string is just a pointer to a place where the first
    byte of string exists in memory
    */

    string s = "HI!";
    printf("String s printed as %%s:     %s\n", s);
    printf("String s printed as pointer: %p\n", s);
    printf("s[0] printed as pointer:     %p\n", &s[0]);
    printf("s[1] printed as pointer:     %p\n", &s[1]);
    printf("s[2] printed as pointer:     %p\n", &s[2]);
    printf("s[3] printed as pointer:     %p\n", &s[3]);

    /*
    printf("%p\n", &"HI");
    printf("%p\n", "HI");

    will print the same result

    this however will not work with types that are not defined as pointers, eg. single char

    printf("%p\n", 'c'); -> warning: format specifies type 'void *' but the argument has type 'char' [-Wformat]

    */

    printf("%p\n", &"HI");

    /*
    printf("%p\n", &'c'); funny that this does not work, but below does

    Ok: 
    Arrays: whenever present need to have a memory location, otherwise they would not exist
    Single: types are "hard coded" during compilation, cause when not used outside of for example print, they do not need memory location, they can just be present in binary 
    */
    char c = 'c';
    char *p_c = &c;
    printf("%p\n", p_c);

    printf("\n");


    // Pointer arithmetic
    /*
    pointers can be iterated over as below, intuition would suggest that in order to get to another
    variable the size of current should be added BUT NO

    adding some n to pointer will result in moving by n "taken memory adresses forward" 
    (I think? does it work only for same types, how does one know how to move over differently sized variables? Is 4*n a default move?)
    */
    
    char *s2 = "Dude";
    for (int i = 0; i < 4; i++)
    {
        printf("%c", *(s2+i));
    }
    printf("\n\n");

    printf("What if one moves forward more than the size of array/string?\n");
    printf("Beggining of s2      has value: %c at %p\n", s2[0], &s2);

    int counter = 0;
    while (counter <= 100)
    {
        printf("Beggining of s2 + %i has value: %c at %p\n", counter, *(s2+counter), (s2+counter));
        counter += 25;
    }
    printf("\n");

    // Strings boiled down
    /*
    strings are just arrays of characters, string variable is a pointer to the first string in the array

    comparison using == is not working on strings because it is comparing their adresses (memory locations)
    */

    // String comparison
    // defining same strings -> same memory locations
    char *s3 = "comparison example";
    char *s4 = "comparison example";

    if (s3 == s4)
    {
        printf("Same memory locations\n");
    }
    else
    {
        printf("Different memory locations\n");
    }
    printf("Memory location of s3=%p and s4=%p\n", s3, s4);

    // inputting same strings -> different memory locations
    char *s5 = get_string("s5: ");
    char *s6 = get_string("s6: ");

    if (s5 == s6)
    {
        printf("Same memory locations\n");
    }
    else
    {
        printf("Different memory locations\n");
    }
    printf("Memory location of s5=%p and s6=%p\n", s5, s6);

    printf("\n");

    // Copying
    /*
    Copying arrays by =, as x = y copies only the adress, so if x is changed, then y is changed as well
    */
    { // subscope
        // get string
        printf("Naive copy - copy pointer\n");

        string s = get_string("s: ");

        // copy strings adress
        string t = s;

        printf("t is: %s\n", t);
        printf("s is: %s\n", s);
        if (strlen(t) > 0)
        {
            t[0] = toupper(t[0]); // t[0] - 32 (ASCII)
        }

        printf("After capitalizing the first letter\n");
        printf("t is: %s\n", t);
        printf("s is: %s\n", s);        
        printf("\n");
    }

    // Real copying - malloc and free
    /*
    What to do to make a real copy?

    malloc  - allocate a block of memory of a specific size
    free    - free an allocated block

    NULL is used by various functions to state whether they were succesful, by checking for NULL after error (1) can be returned
    */
    {
        printf("Real copy - copying value\n");

        // get a string 
        char *s = get_string("s: ");
        if (s == NULL)
        {
            return 1;
        }

        // allocate memory for second string (+1 for the null character)
        char *t = malloc(strlen(s) + 1);
        if (t == NULL)
        {
            return 1;
        }

        printf("malloced t is: %s\n", t);
        printf("defined  s is: %s\n", s);
        // copy s to t
        for (int i = 0; i <= strlen(s); i++)
        {
            t[i] = s[i];
        }

        // capitalize copy
        t[0] = t[0] - 32;

        // print strints
        printf("After capitalizing the first letter\n");
        printf("t is: %s\n", t);
        printf("s is: %s\n", s);

        // freeing memory
        printf("t has not been freed yet\n");
        printf("t value: %s, t adress: %p \n", t, t);
        free(t);
        printf("t has been freed\n");
        printf("t value: %s, t adress: %p \n", t, t);
    }
    /*
    free(x) removes the value from memory location, it does not destroy the pointer

    this can also be done more efficiently

    in the for loop above strlen() would be called on every loop, it is better to define variables like this as:
    for (int i = 0, int n = strlen(s); i <= n; i++)
    {
        // code
    }

    also, there is already a function called strcpy to copy string values - it comes from string.h
    */

    // Valgrind
    /*
    valgrind is used to check whether all malloced allocated memory locations have been freed
    
    look at 10_memory.c
    */
}

// CS50 Lecture 4 - Memory leaks, valgrind

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // Memory leaks
    /*
    If this code is built and run as valgrind ./10_memory_leaks it will result in a memory leak report from valgrind
    */
    int *x = malloc(3 * sizeof(int));
    x[0] = 72;
    x[1] = 73;
    x[2] = 33;

    /*
    this is why it is important to free malloced memory
    */

    // free(x);
}
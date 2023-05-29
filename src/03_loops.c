// CS50 Lecture 1 - Loops

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // WHILE

    // increments
    int i = 0;
    while (i < 3)
    {
        printf("MEOOOW\n");
        i++;
    }

    // de(?)crements
    // int i = 3; // variables can not be redeclared like this in the same scope
    i = 3; // value can be changed, but the type is the same as before 
    while (i > 0)
    {
        printf("BARK\n");
        i--;
    }


    // FOR
    for (int i = 0; i < 10; i++)
    {
        printf("BARKbutINfor\n");
    }
}
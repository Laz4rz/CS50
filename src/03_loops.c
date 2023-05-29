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
    for (int j = 0; j < 10; j++)
    {
        printf("BARKbutINfor\n");
    }


    // INFINITE WHILE AND BREAK
    while (true)
    {
        printf("You just got infinilooped\n");
        break;
    }

    printf("Close call\n");


    // CREATING BLOCKS
    const int limit = 5;

    printf("\nImagine this is your canvas\n");
    int demanded_width = get_int("Width of the block:");
    int demanded_height = get_int("Height of the block:");
    printf("\n");

    for (int j = 0; j < demanded_height; j++)
    {
        for (int k = 0; k < demanded_width; k++)
        {
            printf("#");

            if (k >= limit)
            {
                break;
                // print("Max blocks in one direction is %s", ) 
            }
        }
        printf("\n");

        if (j >= limit)
            {
                break;
            }
    }

    printf("\nCool block dude\n");

    // DO-WHILE UNTILL CORRECT SIZE IS GIVEN
    int l;
    do
    {
        l = get_int("Size: ");
    } 
    while (l < 1); // this also works for wrong types
}
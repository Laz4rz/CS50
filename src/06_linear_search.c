// CS50 Lecture 4 - Linear search

#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    // Define an array of integers
    int numbers[] = {168, 1000, 1, 25, 337, 50};

    // Search for user defined number (linear)
    int n = get_int("Enter a number: ");
    for (int i = 0; i < 6; i++)
    {
        if (numbers[i] == n)
        {
            printf("Found %i at position %i\n", n, i);
            // return 0;
        }
    }
    printf("Couldn't find %i\n", n);
    // return 1;

    // Search for user defined string (linear)
    string strings[] = {"abba", "baba", "tata", "armata"};

    string s = get_string("Enter a string: ");
    for (int i = 0; i < 4; i++)
    {
        if (strcmp(strings[i], s) == 0) // strings cannot be compared by using ==, instead strcmp has to be used 
        {
            printf("Found %s at position %i\n", s, i);
            // return 0;
        }
    }
    // return 1;
}
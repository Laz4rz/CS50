// CS50 Lecture 1 - compare numbers

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("Gimmmee some numbers: \n");
    int x = get_int("x: \n");
    int y = get_int("y: \n");

    if (x < y)
    {
        printf("x is less than y\n");
    }
    else if (y > x)
    {
        printf("x is greater than y\n");
    }
    else
    {
        printf("x is equal y\n");
    }

    char response = get_char("Agreed? [Y/N]\n");

    if (response == 'Y' || response == 'y') // chars are defined with single quotes 'char', strings with double "string"
    {
        printf("You agreed, cool\n");
    }
    else if (response == 'N' || response == 'n')
    {
        printf("You did not agree, also cool\n");
    }
    else
    {
        printf("You can't read\n");
    }
}
// CS50 Lecture 3 - recursion

#include <stdio.h>
#include <cs50.h>

void draw(int n);

int main(void)
{
    // Get user input
    int input = get_int("Height of the pyramid: ");

    // Draw pyramid of given height
    draw(input);
}

void draw(int n)
{
    // Return void if nothing to draw
    if (n <= 0)
    {
        return;
    }

    // Draw n-1 piramid height
    draw(n-1);

    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");
}

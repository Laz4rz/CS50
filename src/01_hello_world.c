// CS50 Lecture 1 - hello world

// compiler: source code -> machine code

#include <stdio.h>
#include <cs50.h>

int main (void)
{
    printf("Hello world \n");

    string user_input = get_string("Tell me something pretty boy \n");
    printf("Did you really just write: %s?\n", user_input);
}
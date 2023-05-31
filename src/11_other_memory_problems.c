// CS50 Lecture 4 - Garbage values, swapping values and scanf

#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b);

int main(void)
{
    // Garbage values
    {
        // define variables
        int scores_length = 1024;
        int scores[scores_length];
        int empty_counter = 0;

        // Print values at each memory location assigned to scores array and count empty
        for (int i = 0; i < scores_length; i++)
        {
            if (scores[i] == 0)
            {
                empty_counter += 1;
            }
            printf("%i\n", scores[i]);
        }
        printf("Empty memory locations: %i/%i - %f%%\n", empty_counter, scores_length, (float)empty_counter/scores_length);
    }
    printf("\n");
    
    // Swapping values
    /*
    while swapping values between 2 variables, an additional variable has to be initialized -> swap()
    */
    {
        int a = 3;
        int b = 1;
        printf("a=%i and b=%i\n", a, b);

        swap(&a, &b);
        printf("Swap(a, b)\n");
        printf("a=%i and b=%i\n", a, b);
    }
    printf("\n");

    // Scanf
    /*
    Can be used to getting user input
    */
    {
        // Getting int type input
        int x;
        printf("Gimme number, whole: ");
        scanf("%i", &x);
        printf("Saved x: \n-value: %i\n-adress: %p\n", x, &x);
    }
    printf("\n");
    
    {
        // Getting string type input, fairly easy to get a constant size input
        /*
        array needs to be defined with some length, otherwise compiler would not know how much space it needs to reserve

        strings shorter than the limit  -> cool
        string longer than the limit    -> buffer overflow, not cool, will corrupot adjacent memory, may give error, may give some random results later 

        to limit the input to some n first input characters -> scanf("%4s", s);
        */
        char input[4];
        printf("Gimme a 4 char word: ");
        scanf("%4s", input);
        printf("Saved input: \n-value: %s\n-adress: %p\n", input, input);
    }

}

/*
This naive implementation will not work as this way only copies are provided, as these variables live in main scope
for the interscope availability the pointers have to be provided

void swap(int a, int b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

functions are stored in the stack part of memory

there are two types of buffer overflows:
heap overflow   - touching part of memory the program is not supposed to
stack overflow  - too many functions are called and overflow the amount of available memory 
*/

// variables here are passed by REFERENCE not by VALUE
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}



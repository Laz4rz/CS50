// CS50 Lecture 2 - arrays

/* 
Memory size of types:
bool 1 byte
int 4 bytes
long 8 bytes
float 4 bytes
double 8 bytes
char 1 byte
string ? bytes-> string_length*1bit as it is just a bunch of chars
*/

#include <stdio.h>

int main(void)
{
    int score1 = 10;
    int score2 = 20;
    int score3 = 30;

    printf("Average is: %f\n", (score1 + score2 + score3) / 3.0);

    // Creation of arrays in C
    int scores[3];
    scores[0] = 10;
    scores[1] = 20;
    scores[2] = 30;
    
    printf("Average is: %f\n", (scores[0] + scores[1] + scores[2]) / 3.0);

    // "Random" values
    /* 
    When array is initialized, there will most probably some random values assigned to the memory adresses reserved for it,
    so if one forgets to assign specific value to each, he may end up with some seemingly random thing appearing when working
    with it
    */
    int array[2];
    array[0] = 1;

    printf("Array consists of: %i and %i\n", array[0], array[1]);
}
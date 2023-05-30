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
#include <cs50.h>
#include <string.h>

// Constant
const int N = 3;

// Prototype
float average(int length, int array[]);
int string_length(char array[]);

int main(int argc, string argv[])
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

    printf("Average using average() is: %f\n", average(N, scores));

    // "Random" values
    /* 
    When array is initialized, there will most probably some random values assigned to the memory adresses reserved for it,
    so if one forgets to assign specific value to each, he may end up with some seemingly random thing appearing when working
    with it
    */
    int array[2];
    array[0] = 1;

    printf("\nArray consists of: %i and %i\n", array[0], array[1]);

    // String
    /*
    Strings are arrays of chars, their last element is a NUL character
    */
    char c1 = 'H';
    char c2 = 'I';
    char c3 = '!';
    printf("\nChars\n");
    printf("%i %i %i\n", c1, c2, c3);

    string s = "HI!";
    printf("\nArray:\n");
    printf("Print as ints: %i %i %i\n", s[0], s[1], s[2]);
    printf("Print as chars: %c %c %c\n", s[0], s[1], s[2]);
    printf("Printed as string: %s\n", s);

    // Array of strings
    string words[2];
    words[0] = "HI!";
    words[1] = "BYE!";
    printf("\nArray of strings:\n");
    printf("%s %s\n", words[0], words[1]);

    // Discovering the length of string
    char word[] = "HI!";
    printf("\nLength of dynamic string is: %i\n", string_length(word));

    char word2[10];
    printf("\nLength of empty char word2[10]; string is: %i\n", string_length(word2));

    // Using strlen() from string.h
    char word3[] = "HI!";
    printf("\nLength of dynamic string using strlen() from string.h is: %lu\n", strlen(word3));

    char word4[10];
    printf("\nLength of empty char word4[10]; string using strlen() from string.h is: %lu\n", strlen(word4));

    // String lowercasing
    string input = get_string("\nInput for lowercasing: ");
    for(int i=0; i<strlen(input); i++)
    {
        if(input[i] >= 'A' && input[i] <= 'Z')
        {
            input[i] += 32;
        }
    }
    printf("Lowercased string is: %s\n", input);

    // Command line arguments
    /*
    add int argc, string argv[] to main
    */
    if (argc == 2)
    {
        printf("\nCommand line arguments is: %s\n", argv[1]);
    }
    else
    {
        printf("There was not command line argument\n");
    }

    // Exit status
    return 0; // - ok
    // return 1; - error 
}

float average(int length, int array[])
{
    // Calculate average
    int sum = 0;
    for (int i =0; i < length; i++)
    {
        sum += array[i];
    }

    return sum / (float) length;
}

int string_length(char array[])
{
    int n = 0;
    while (array[n] != '\0')
    {
        n++;
    }
    return n;
}

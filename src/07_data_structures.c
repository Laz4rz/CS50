// CS50 Lecture 4 - Data Structures

#include <stdio.h>
#include <cs50.h>
#include <string.h>

typedef struct
{
    string name;
    string number;
}
person;

int main(void)
{
    // Create an array of two person data structues called people
    person people[2];

    // Populate people with data
    people[0].name = "Pawel";
    people[0].number = "600 100 700";

    people[0].name = "Jan";
    people[0].number = "200 100 307";

    // Search for name
    string name = get_string("Find: ");

    for (int i = 0; i < 2; i++)
    {
        if (strcmp(people[i].name, name) == 0)
        {
            printf("Found %s with %s\n", people[i].name, people[i].number);
            return 0;
        }
    }
    return 1;
}
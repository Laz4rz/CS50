// Cool string functions from stdio - sprintf and sscanf

#define new(dtype,length) (dtype *)malloc(sizeof(dtype)*(length))

#include <stdio.h>
#include <stdlib.h>

const int SCANF_LIMIT = 20;

int main(){
    // sprintf makes it insanely easy to create a string from different types
    // you have to however predict or limit the output string to some predefined number of chars

    // concatenate str to str with arbitrary chars in between
    char *name = "Jan";
    char *surname = "Pawel";

    char *fullname = new(char, SCANF_LIMIT);
    if (fullname == NULL){
        printf("Couldn't allocate memory");
        return 1;
    }
    sprintf(fullname, "%s %s", name, surname);
    printf("Full name is: %s\n", fullname);

    // concatenate str to str with arbitrary chars in between
    char *name2 = "Adam";
    int age = 17;

    char *desc_person = new(char, SCANF_LIMIT);
    if (desc_person == NULL){
        printf("Couldn't allocate memory");
        return 1;
    }
    sprintf(desc_person, "%s is %i years old\n", name2, age); // this may be a bead example, but you get a gist
    printf("%s", desc_person);

    // freeing mallocs
    free(desc_person);
    free(fullname);
}
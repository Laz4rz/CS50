#include <stdio.h>
#include <stdlib.h>

// arrays different than string arrays have no null char at the end

// Create array with size as attribute
typedef struct Int{
    int *val;
    int length;
} Int;

// Initializer
Int newInt(int length){
    Int A = {NULL, length};
    A.val = (int *)malloc(sizeof(int) * length);
    A.length = length;
    return A;
}

int main(void){
    Int array = newInt(4);
    if (array.val == NULL){
        printf("Couldn't allocate memory");
        return 1;
    }
    for (int i=0; i<4; i++){
        array.val[i] = i;
    }

    for (int i=0; i<4; i++){
        printf("%i: %i\n", i, array.val[i]);
    }
}
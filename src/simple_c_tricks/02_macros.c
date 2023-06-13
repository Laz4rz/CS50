#define new(dtype,length) (dtype *)malloc(sizeof(dtype)*(length))

#include <stdio.h>
#include <stdlib.h>

// Create array with size as attribute
typedef struct Int{
    int *val;
    int length;
} Int;

// Initializer
Int newInt(int length){
    Int A = {NULL, length};
    A.val = new(int, length); // new can be used to allocate memory for any type with any length without writing whole malloc formula everytime
    A.length = length;
    return A;
}

int main(){
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
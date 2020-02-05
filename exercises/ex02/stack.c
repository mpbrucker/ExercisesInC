/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int *foo() {
    int i;
    int array[SIZE];

    // printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
        array[i] = 42;
    }
    return array;
}

void bar() {
    int i;
    int array[SIZE];

    // printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
        array[i] = i;
    }
}

int main()
{
    int i;
    int *array = foo();
    bar();

    for (i=0; i<SIZE; i++) {
        printf("%d\n", array[i]);
    }

    return 0;
}

/*

EXPERIMENTS:

1. stack.c should create two arrays of size 5, fills one with 42, and one with 1-5. The output should be "42 42 42 42 42"

2. The warning says "function returns address of local variable." It means that the function returns an address of a variable that was locally allocated, which will exist in that particular function's stack frame.

3. The arrays allocated in foo() and bar() exist at the same location, which makes sense because once foo() finishes executing its stack frame is unallocated. Then, it segfaults, probably because foo() returned a pointer to an address that now exists in bar's stack frame.

4. It segfaults.

*/
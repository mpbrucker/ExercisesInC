/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

int var1;

void print_var() {
    int var3;
    printf ("Address of var3 is %p\n", &var3);
}

int main ()
{
    int var2 = 5;
    void *p = malloc(128);
    void *q = malloc(23);
    void *r = malloc(23);
    char *s = "Hello, World";
    print_var();


    printf ("Address of main is %p\n", main);
    printf ("Address of var1 is %p\n", &var1);
    printf ("Address of var2 is %p\n", &var2);
    printf ("Address of p is %p\n", &p);
    printf ("Address of s is %p\n", &s);
    printf ("p points to %p\n", p);
    printf ("q points to %p\n", q);
    printf ("r points to %p\n", r);
    printf ("s points to %p\n", s);

    return 0;
}

/*

EXPERIMENTS:

4. The additional malloc does allocate a higher memory address, showing that the heap grows upward.

5. The new local var is allocated at a lower address, showing that the stack grows down.

6. The two malloc(20) calls allocate memory that is 0x20=20 bytes of data apart.

*/
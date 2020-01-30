#include <stdio.h>

int main() {
    int x = 5;
    int y = x + 1;
    printf("Hello, %d World!\n", y);
    return 0;
}

/*

1. It apears to be the line movl    $5, -4(%rbp)

2. That line, along with the four lines above it, is removed from the assembly code.

3. In both the optimized and unoptimized versions, it adds several movl statements. However, in the optimized version, there are fewer movl statements.

4. In the unoptimized version, it appears that an additional memory is allocated for y, containing x + 1. In the optimized version, just one allocation is made, since x is never used. 
Based on the optimizations it performs, it seems to condense down allocations to use the fewest memory locations possible.


*/
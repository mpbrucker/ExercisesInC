#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int input_to_int(char * input) {
    
}

/*
    Sums thhe elements of an int array, and returns the total

    array: an integer array containing the numbers to sum
    array_len: the length of the array
*/
int sum_array(int * array, int array_len) {
    int total = 0;
    for (int i=0; i<array_len; i++) {
        total += array[i];
    }
    return total;
}

int main() {
    int nums[20] = {0};
    char user_input[13]; // TODO: Determine actual maximum length
    int i = 0;
    void * input_success;

    do {
        puts("Enter an integer: ");
        input_success = fgets(user_input, 13, stdin);
        if (strlen(user_input) == 12 && user_input[11] != '\n') {
            printf("Error: input is too long");
            break; // TODO: Should it keep going?
        }
        int input_int = atoi(user_input);
    } while (input_success != NULL);
    printf("Total: %d", sum_array(nums, sizeof(nums)));
}
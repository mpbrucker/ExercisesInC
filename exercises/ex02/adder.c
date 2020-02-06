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

/* 
    Checks to see whether the input buffer is "overfull" (i.e., if the array 
    is full and the second to last character isn't \n.)
    Returns 1 if full, 0 otheriwse

    array: The input buffer
    size: the expected max input size
*/
int check_input_full(char * array, int size) {
    if (strlen(array) == (size-1) && array[size-2] != '\n') {
            return 1; // TODO: Should it keep going?
    }
    return 0;
}

/*
    Takes input from user in the form of integers, stores the integers, and prints the sum.
*/
int main() {
    int nums[20] = {0};
    
    char user_input[13];
    int i = 0;
    void * input_success;

    do {
        puts("Enter an integer: ");
        input_success = fgets(user_input, 13, stdin);
        if (check_input_full(user_input, 13)) {
            puts("Error: input is too long");
            do {
                fgets(user_input, 13, stdin);
                
            } while (check_input_full(user_input, 13));
            continue;
        }

        int input_int = atoi(user_input);
        if (input_int == 0) {
            puts("Error: zero value or non-integer entered.");
            continue;
        }

        nums[i] = input_int;
        i++;
        if (i >= sizeof(nums)/4) {
            puts("Maximum number of integers entered.");
            break;
        }
    } while (input_success != NULL);
    printf("Total: %d", sum_array(nums, sizeof(nums)/4));
}
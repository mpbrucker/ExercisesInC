/*
    Exercise 1
    Matt Brucker
    Due 1/31/20
    Takes input in the form of 
*/

#include <stdio.h>
#include <stdlib.h>

/* 
    Takes as input a char representing a card, and returns the corresponding numerical value of the card. Returns -1 if the input is invalid. 

    card: the char array containing the name of the card 
*/ 
int card_value(char * card) {
    int val;
    switch(card[0]) {
        case 'K':
        case 'Q':
        case 'J':
            val = 10;
            break;
        case 'A':
            val = 11;
            break;
        default:
            val = atoi(card);
            if ((val < 1) || (val > 10)) {
                puts("I don't understand that value!");
                val = 0;
            }
    }
    return val;
}

/*
    Checks the card value, and returns the updated card count variable

    cur_count: the current count of cards in range
    card_val: the integer value of the current card
*/
int update_count(int cur_count, int card_val) {
    if ((card_val > 2) && (card_val < 7)) {
        return cur_count + 1;
    } else if (card_val == 10) {
        return cur_count - 1;
    }
    return cur_count;
}


/*
    Handles user input and updates the card count variable based on it.
*/
void handle_input() {
    char card_name[3];
    int count = 0;
    do {
        puts("Enter the card_name: ");
        scanf("%2s", card_name);
        int card_val = 0;
        if (card_name[0] != 'X') 
            card_val = card_value(card_name);

        count = update_count(count, card_val);
        printf("Current count: %i\n", count);
    } while (card_name[0] != 'X');
}

int main()
{
    handle_input();
    return 0;
}
/* Example code for Exercises in C.

Based on an example from http://www.learn-c.org/en/Linked_lists

Copyright 2016 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} Node;


/* Makes a new node structure.
*
* val: value to store in the node.
* next: pointer to the next node
*
* returns: pointer to a new node
*/
Node *make_node(int val, Node *next) {
    Node *node = malloc(sizeof(Node));
    node->val = val;
    node->next = next;
    return node;
}


/* Prints the values in a list.
*
* list: pointer to pointer to Node
*/
void print_list(Node **list) {
    Node *current = *list;

    printf("[ ");
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("]\n");
}


/* Removes and returns the first element of a list.
*
* list: pointer to pointer to Node
*
* returns: int or -1 if the list is empty
*/
int pop(Node **list) {
    if (*list == NULL) {
        return -1;
    }
    int ret = (*list)->val;
    Node * old = *list;
    Node * old_next = (*list)->next;
    *list = old_next;

    free(old);

    return ret;
}


/* Adds a new element to the beginning of the list.
*
* list: pointer to pointer to Node
* val: value to add
*/
void push(Node **list, int val) {
    Node * new_head = make_node(val, *list);
    *list = new_head;
}


/* Removes the first element with the given value
*
* Frees the removed node.
*
* list: pointer to pointer to Node
* val: value to remove
*
* returns: number of nodes removed
*/
int remove_by_value(Node **list, int val) {

    Node * cur_node = *list;

    while (cur_node != NULL && cur_node->next != NULL) {
        if (cur_node->next->val == val) {
            Node * temp = cur_node->next;
            cur_node->next = temp->next;
            free(temp);
            return 1;
        }
        cur_node = cur_node->next;
    }
    return 0;
}


/* Reverses the elements of the list.
*
* Does not allocate or free nodes.
*
* list: pointer to pointer to Node
*/
void reverse(Node **list) {
    Node * cur_node = *list;
    if (cur_node->next == NULL || cur_node == NULL) {
        return;
    }

    Node * temp_next;
    Node * prev_node = cur_node;
    cur_node = cur_node->next;
    prev_node->next = NULL;

    while (cur_node != NULL) {
        temp_next = cur_node->next;
        cur_node->next = prev_node;

        prev_node = cur_node;
        cur_node = temp_next;
    }
    *list = prev_node;

}


int main() {
    Node *head = make_node(1, NULL);
    head->next = make_node(2, NULL);
    head->next->next = make_node(3, NULL);
    head->next->next->next = make_node(4, NULL);

    Node **list = &head;
    print_list(list);

    int retval = pop(list);
    print_list(list);

    push(list, retval+10);
    print_list(list);

    remove_by_value(list, 3);
    print_list(list);

    remove_by_value(list, 7);
    print_list(list);

    reverse(list);
    print_list(list);
}

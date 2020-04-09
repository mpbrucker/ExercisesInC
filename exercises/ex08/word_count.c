/* Simple example using Glib.

From http://www.ibm.com/developerworks/linux/tutorials/l-glib/

*/

#include "word_count.h"

int read_file(char * file_name) {
    char 
    do
}

FILE * open_file(char * file_name) {
    FILE * fp;
    fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("Error: Specified file does not exist.")
        exit(EXIT_FAILURE);
    }
    return fp;
    
}


int main(int argc, char** argv) {
    GList* list = NULL;
    list = g_list_append(list, "Hello world!");
    printf("The first item is '%s'\n", (char *) g_list_first(list)->data);
    return 0;
}

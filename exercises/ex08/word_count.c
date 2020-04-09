/* Simple example using Glib.

From http://www.ibm.com/developerworks/linux/tutorials/l-glib/

*/
#define FILENAME "test.txt"

#include "word_count.h"

void process_line(char * line, GHashTable * dict) {
    char * word = strtok(line, " ");
    int * cur_count;
    while (word != NULL) {
        char * dup_str = strdup(word);
        cur_count = (int *) g_hash_table_lookup(dict, dup_str);

        if (cur_count == NULL) {
            int * new_val = malloc(sizeof(int));
            *new_val = 1;
            g_hash_table_insert(dict, dup_str, &new_val);
        } else {
            *cur_count += 1;
            // g_hash_table_insert(dict, word, (*cur_count) + 1);
        }
        word = strtok(NULL, " ");
        printf("%s %d\n", word, cur_count);
    }
}

FILE * open_file(char * file_name) {
    FILE * fp;
    fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("Error: Specified file does not exist.");
        exit(EXIT_FAILURE);
    }
    return fp;
}

int main(int argc, char** argv) {
    FILE * fp = open_file(FILENAME);
    size_t len = 0;
    char * line;
    int read;
    GHashTable * dict = g_hash_table_new(g_str_hash, g_str_equal);

    while ((read = getline(&line, &len, fp)) != -1) {
        process_line(line, dict);
    }

    return 0;
}

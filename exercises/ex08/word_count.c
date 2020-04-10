/* Simple example using Glib.

From http://www.ibm.com/developerworks/linux/tutorials/l-glib/

*/
#define FILENAME "test.txt"

#include "word_count.h"

void remove_newline(char * line) {
    char * pos = strchr(line, '\n');
    if (pos != NULL) {
        *pos = '\0';
    }
}

void process_line(char * line, GHashTable * dict) {
    char * word = strtok(line, " ");
    int * cur_count;
    while (word != NULL) {
        char * dup_str = strdup(word);
        cur_count = (int *) g_hash_table_lookup(dict, dup_str);

        if (cur_count == NULL) {
            int * new_entry = malloc(sizeof(int));
            *new_entry = 1;
            g_hash_table_insert(dict, dup_str, new_entry);
        } else {
            *cur_count += 1;
        }
        word = strtok(NULL, " ");
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

void print_hash_table(GHashTable * table, char * file_name) {
    GList * key = g_hash_table_get_keys(table);
    char * word;
    int * count;

    printf("Word counts for %s:\n", file_name);
    while (key != NULL) {
        word = (char *) key->data;
        count = (int *) g_hash_table_lookup(table, word);
        printf("%s: %d\n", word, *count);
        key = key->next;
    }
} 

int main(int argc, char** argv) {
    FILE * fp = open_file(FILENAME);
    size_t len = 0;
    char * line;
    int read;
    GHashTable * dict = g_hash_table_new(g_str_hash, g_str_equal);

    while ((read = getline(&line, &len, fp)) != -1) {
        remove_newline(line);
        process_line(line, dict);
    }
    print_hash_table(dict, FILENAME);

    return 0;
}

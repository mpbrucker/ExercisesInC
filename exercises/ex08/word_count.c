/* Simple example using Glib.

From http://www.ibm.com/developerworks/linux/tutorials/l-glib/

*/

#include "word_count.h"

/*
    Removes a newline character from a string.
*/
void remove_newline(char * line) {
    char * pos = strchr(line, '\n');
    if (pos != NULL) {
        *pos = '\0';
    }
}

/*
    Parses a line of text, adding to the counts in the specified table for each word
    line: the line of text to parse
    dict: the GHashTable to add the word counts to
*/
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

/*
    Opens the specified file, checking to ensure it exists.
*/
FILE * open_file(char * file_name) {
    FILE * fp;
    fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("Error: Specified file does not exist.");
        exit(EXIT_FAILURE);
    }
    return fp;
}

/*
    Print the keys and values in a hash table.
    table: the hash table to print
    file_name: a string specifying the file that was processed.
*/
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
    if (argc < 2) {
        printf("Error. Please specify a filename.");
        exit(1);
    }
    char * file_name = argv[1];
    FILE * fp = open_file(file_name);
    size_t len = 0;
    char * line;
    int read;
    GHashTable * dict = g_hash_table_new(g_str_hash, g_str_equal);

    while ((read = getline(&line, &len, fp)) != -1) {
        remove_newline(line);
        process_line(line, dict);
    }
    print_hash_table(dict, file_name);

    return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <glib.h>

void remove_newline(char * line);
void process_line(char * line, GHashTable * dict);
FILE * open_file(char * file_name);
void print_hash_table(GHashTable * table, char * file_name);
int main(int argc, char** argv);
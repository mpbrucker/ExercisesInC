#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <glib.h>

void process_line(char * line, GHashTable * dict);
FILE * open_file(char * file_name);
int main(int argc, char** argv);
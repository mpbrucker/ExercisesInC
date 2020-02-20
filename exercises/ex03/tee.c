#include <stdio.h>
#include <unistd.h>
#include <string.h>


void handle_input(char * stream_names[], int num_streams, char * append) {
    size_t line_size = 0;
    char * buffer = NULL;
    int has_opened = 0;

    while(1) {
        getline(&buffer, &line_size, stdin);
        printf("%s", buffer);
        for (int i=0; i < num_streams; i++) {
            FILE * stream;
            if (!has_opened) {
                stream = fopen(stream_names[i], append);
                has_opened = !has_opened;
            } else {
                stream = fopen(stream_names[i], "a");
            }
            fprintf(stream, "%s", buffer);
            fclose(stream);
        }
    }
    
}

int main(int argc, char * argv[]) {
    char ch;
    int append = 0;

    while ((ch = getopt(argc, argv, "apohv")) != EOF) {
        switch (ch) {
            case 'a':
                append = 1;
                break;
            case 'p':
                break;
            case 'o':
                break;
            case 'h':
                break;
            case 'v':
                puts("tee version 0.1.");
                break;
            default:
                printf("tee: invalid option -- '%c'\nTry 'tee --help' for more information.\n", ch);
                return 1;
        }
    }

    char * append_flag = append ? "a" : "w";
    int stream_num = 0;
    const int NUM_STREAMS = argc-optind;
    char * stream_names[NUM_STREAMS];

    for (; optind < argc; optind++) {
        stream_names[stream_num] = argv[optind];
        stream_num++;
    }

    handle_input(stream_names, NUM_STREAMS, append_flag);

    return 0;
}
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
int flag = 0;
int ignore_interrupt = 0;

void handle_input(FILE * streams[], int num_streams) {
    size_t line_size = 0;
    char * buffer = NULL;

    while(1) {
        if (flag) {
            flag = 0;
            break;
        }
        getline(&buffer, &line_size, stdin);
        printf("%s", buffer);
        for (int i=0; i < num_streams; i++) {
            fprintf(streams[i], "%s\n", buffer);
        }
    }
}

void handle_interrupt(int sig) {
    puts("interrupt");
    if (!ignore_interrupt) {
        flag = 1;
    }
}

int main(int argc, char * argv[]) {
    char ch;
    int append = 0;
    signal(SIGINT, handle_interrupt);

    while ((ch = getopt(argc, argv, "aipohv")) != EOF) {
        switch (ch) {
            case 'a':
                append = 1;
                break;
            case 'i':
                puts("test");
                ignore_interrupt = 1;
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
    FILE * streams[NUM_STREAMS];

    for (; optind < argc; optind++) {
        streams[stream_num] = fopen(argv[optind], append_flag);
        printf("%s\n",argv[optind]);
    }

    handle_input(streams, stream_num);

    for (int i=0; i < NUM_STREAMS; i++) {
        fclose(streams[i]);
    }

    return 0;
}
#include <stdio.h>
#include <unistd.h>


//  Opens a file stream with a given file name in a specified mode, writes a buffer to it, and closes the filestream.
//  stream_name: the filename of the stream.
//  apppend: the character to specify the mode of the file (append vs. write)
//  buffer: The buffer to write.
//
void write_stream(char * stream_name, char * mode, char * buffer) {
    FILE * stream; 
    int res;
    stream = fopen(stream_name, mode);
    res = fprintf(stream, "%s", buffer);
    fclose(stream);
    if (stream == NULL || res == -1) {
        printf("Error writing to file: %s", stream_name);
    }
}

//  Handles the input loop of taking in input writing anad writing it to a list of filestreams.
//  stream_names: the names of the files to write to.
//  num_streams: the number of output streams.
//  append: specifies whether to append or write to files.
//
void handle_input(char * stream_names[], int num_streams, char * append) {
    size_t line_size = 0;
    char * buffer = NULL;
    int has_opened = 0;
    int res;

    while(1) {
        res = getline(&buffer, &line_size, stdin);
        if (res == -1) {
            printf("Error reading input from stdin");
            break;
        }
        printf("%s", buffer);
        for (int i=0; i < num_streams; i++) {
            write_stream(stream_names[i], has_opened ? "a" : append, buffer);
        }
        if (!has_opened) {
            has_opened = !has_opened;
        }
    }
    
}

// Writes input from stdin to one or more filestreams whose filenames are provided.
// -a option: append to files (instead of writing)
// -v option: version
// 
int main(int argc, char * argv[]) {
    char ch;
    int append = 0;

    while ((ch = getopt(argc, argv, "av")) != EOF) {
        switch (ch) {
            case 'a':
                append = 1;
                break;
            case 'v':
                printf("%s", "tee version 0.1.");
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
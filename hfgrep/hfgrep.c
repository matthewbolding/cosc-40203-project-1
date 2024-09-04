// Operating Systems
// COSC 40203-065
// Matthew Bolding
// Dr. Michael Scherger

// Project 1
// hfgrep.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // If no arguments are given,
    if(argc == 1) {
        // show the program's usage.
        printf("%s", "hfgrep.out: searchterm [file ...]\n");
        exit(1);
    } 
    else if(argc == 2) {
        // If stdin is the file,
        char *line = NULL;
        size_t len = 0;
        ssize_t nread;
        // read from stdin, as documented in `man getline`.
        while((nread = getline(&line, &len, stdin)) != -1) 
        {
            if(strstr(line, argv[1]))
            {
                // Print the line, if the searchterm is in the line.
                printf("%s", line);
            }
        }
    } 
    else {
        // Open each file listed.
        for(int i = 2; i < argc; i++)
        {
            // Open the file.
            FILE *file = fopen(argv[i], "r");
            if (file == NULL) {
                printf("hfgrep.out: cannot open file\n");
                exit(1);
            }
            
            // Read a line from some file, as documented in `man getline`.
            char *line = NULL;
            size_t len = 0;
            ssize_t nread;
            while((nread = getline(&line, &len, file)) != -1) 
            {
                if(strstr(line, argv[1]))
                {
                    // Print the line, if the searchterm is in the line.
                    printf("%s", line);
                }
            }

            // Close the file
            fclose(file);
        }
    }
    exit(0);
}
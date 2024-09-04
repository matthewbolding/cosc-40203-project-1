// Operating Systems
// COSC 40203-065
// Matthew Bolding
// Dr. Michael Scherger

// Project 1
// hfzip.c

#include <stdio.h>
#include <stdlib.h>

int count = 1;
char recent_three[3];

FILE *file;

void same_letter();
void diff_letter();
void eof_reached();
void ingest_letter();
void zip_print(int index);

int main(int argc, char *argv[]) {
    // If no arguments are given,
    if(argc == 1) {
        // show the program's usage.
        printf("%s", "hfzip.out: file1 [file2 ...]\n");
        exit(1);
    } 
    else
    {
        // Open each file listed.
        for(int i = 1; i < argc;)
        {
            // Open the file.
            file = fopen(argv[i], "r");
            if(file == NULL) {
                printf("hfzip.out: cannot open file\n");
                exit(1);
            }

            // Read the file and keep track of three characters.
            if(i == 1) {
                recent_three[0] = fgetc(file);
                recent_three[1] = fgetc(file);
                recent_three[2] = fgetc(file);
            } else {
                // At the end of one file, pull in the first character
                // of the next one, and continue the compression process.
                recent_three[2] = fgetc(file);
            }
            
            
            while(1) {
                if(recent_three[2] == EOF) {
                    i++;
                    // If there are no more files over which to iterate,
                    // start signal that the file of files have been reached.
                    if(i == argc) {
                        eof_reached();
                    }
                    // Break.
                    break;
                } else if(recent_three[0] == recent_three[1]) {
                    same_letter();
                } else {
                    diff_letter();
                }
            }

            // Close the file
            fclose(file);
        }
    }
    exit(0);
}

/*
eof_reached handles logic for when the end of all files
is reached.
*/
void eof_reached() {
    if(recent_three[0] == recent_three[1]) {
        count++;
        zip_print(0);
    } else {
        zip_print(0);
        count = 1;
        zip_print(1);
    }
}

/*
same_letter brings in a new letter and increases the count.
*/
void same_letter() {
    ingest_letter();
    count++;
}

/*
diff_letter prints the 0th index of recent_three, resets
the counter, and brings in a new letter.
*/
void diff_letter() {
    zip_print(0);
    count = 1;
    ingest_letter();
}

/*
Bring in a new letter.
*/
void ingest_letter() {
    recent_three[0] = recent_three[1];
    recent_three[1] = recent_three[2];
    recent_three[2] = fgetc(file);
}

/*
Print the character at index index of the recent_three character array
and the current count.
*/
void zip_print(int index) {
    fwrite(&count, sizeof(int), 1, stdout);
    fwrite(&recent_three[index], 1, sizeof(char), stdout);
}
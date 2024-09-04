// Operating Systems
// COSC 40203-065
// Matthew Bolding
// Dr. Michael Scherger

// Project 1
// hfunzip.c

#include <stdio.h>
#include <stdlib.h>

FILE *file;

char letter;
int number;

int main(int argc, char *argv[]) {
    // If no arguments are given,
    if(argc == 1) {
        // show the program's usage.
        printf("%s", "hfunzip.out: file1 [file2 ...]\n");
        exit(1);
    } 
    else {
        // Open each file listed.
        for(int i = 1; i < argc; i++) {
            
            // Open the file.
            file = fopen(argv[i], "r");
            if(file == NULL) {
                printf("hfunzip.out: cannot open file\n");
                exit(1);
            }

            // Read the file.
            // While still reading in a non-zero number of integers and characters,
            while(fread(&number, sizeof(int), 1, file) != 0 && fread(&letter, sizeof(char), 1, file) != 0) {
                for(int i = 0; i < number; i++) {
                    // print some number of characters letter.
                    printf("%c", letter);
                }
            }  

            // Close the file.
            fclose(file);
        }
    }
    exit(0);
}
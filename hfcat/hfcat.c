// Operating Systems
// COSC 40203-065
// Matthew Bolding
// Dr. Michael Scherger

// Project 1
// hfcat.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char buffer[64];

    // Open each file listed.
    for(int i = 1; i < argc; i++) {
        // Open the file.
        FILE *file = fopen(argv[i], "r");
        if(file == NULL) {
            printf("hfcat.out: cannot open file\n");
            exit(1);
        }

        // Read the file.
        while(fgets(buffer, sizeof(buffer), file) != NULL) {
            // Print the buffer.
            printf("%s", buffer);
        }
        
        // Close the file.
        fclose(file);
    }
    
    // Note that if no files are listed, the program will not enter 
    // the for loop, but still return the appropriate return code.
    exit(0);
}
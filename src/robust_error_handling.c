#include <stdio.h>

int main(void) {
    FILE *fp = fopen("config.txt", "r"); // Use the file from the last lesson
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    int c;

    // Loop until fgetc() returns EOF
    while ((c = fgetc(fp)) != EOF) {
        putchar(c); // Process the character
    }

    // --- After the loop, diagnose the reason for termination ---
    if (ferror(fp)) {
        fprintf(stderr, "\n\nERROR: An I/O error occurred during reading.\n");
    } 
    else if (feof(fp)) {
        printf("\n\nSUCCESS: End of file was reached normally.\n");
    }

    fclose(fp);
    return 0;
}
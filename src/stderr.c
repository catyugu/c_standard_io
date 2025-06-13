#include <stdio.h>

int main(void) {
    // This is normal output, so it goes to stdout.
    printf("Processing data...\n");

    // This is an informational message, also goes to stdout.
    fprintf(stdout, "Task complete.\n");

    // Now, let's simulate an error.
    // Error messages should ALWAYS be sent to stderr.
    fprintf(stderr, "Warning: Configuration file not found. Using defaults.\n");

    // Let's try opening a file that we know will fail.
    FILE *f = fopen("a_file_that_does_not_exist.txt", "r");
    if (f == NULL) {
        // This is the professional way to report the error.
        fprintf(stderr, "Fatal Error: Could not open the required data file.\n");
    }

    return 0;
}
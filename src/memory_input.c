#include <stdio.h>

int main(void) {
    char filename[50];
    char user[] = "alex";
    int day_of_year = 165;

    // Safely format a string like "alex_165.log" into the buffer
    int result = snprintf(filename, sizeof(filename), "%s_%d.log", user, day_of_year);

    // snprintf returns the number of characters it *would* have written.
    // A successful call means this number is positive and less than the buffer size.
    if (result > 0 && result < sizeof(filename)) {
        printf("Formatted filename: %s\n", filename);
        // Now you could use this filename in fopen():
        // FILE *fp = fopen(filename, "w");
    } else {
        fprintf(stderr, "Error: Buffer was too small to format the filename.\n");
    }

    return 0;
}
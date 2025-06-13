#include <stdio.h>
#include <string.h>

int main(void) {
    FILE *fp = fopen("config.txt", "r");
    if (fp == NULL) {
        perror("Could not open config.txt");
        return 1;
    }

    char line_buffer[256];
    char user[50];
    int id;

    // Read the file line by line with fgets
    while (fgets(line_buffer, sizeof(line_buffer), fp) != NULL) {
        // Now, try to parse the buffer with sscanf
        if (sscanf(line_buffer, "user = %s", user) == 1) {
            printf("Found user: %s\n", user);
        } else if (sscanf(line_buffer, "id = %d", &id) == 1) {
            printf("Found id: %d\n", id);
        }
        // If sscanf fails, no problem! We just ignore the line
        // (like the comment and the "host" line) and fgets gets the next one.
    }

    fclose(fp);
    return 0;
}
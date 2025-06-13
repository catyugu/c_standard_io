#include <stdio.h>

#define MAX_LINE_LENGTH 256

int main(void) {
    FILE *in_file = fopen("student_record.txt", "r");
    FILE *out_file = fopen("record_with_lines.txt", "w");

    if (in_file == NULL || out_file == NULL) {
        printf("Error opening files.\n");
        return 1;
    }

    char line_buffer[MAX_LINE_LENGTH];
    int line_num = 1;

    // The best way to read a text file:
    // Read one line at a time with fgets() until it returns NULL (end of file).
    while (fgets(line_buffer, sizeof(line_buffer), in_file) != NULL) {
        // Write the line number
        fprintf(out_file, "%d: ", line_num++);
        // Write the line itself (which already contains a \n)
        fputs(line_buffer, out_file);
    }

    printf("File processed. See 'record_with_lines.txt'.\n");

    fclose(in_file);
    fclose(out_file);

    return 0;
}
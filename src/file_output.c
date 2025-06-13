#include <stdio.h>

int main(void) {
    FILE *file_handle = NULL;
    const char *filename = "student_record.txt";
    
    char name[] = "Alice";
    int student_id = 42;
    float gpa = 3.85f;

    // Open the file in "write" mode. This will create the file
    // or erase its contents if it already exists.
    file_handle = fopen(filename, "w");

    if (file_handle == NULL) {
        printf("Error opening %s\n", filename);
        return 1;
    }

    printf("File opened. Writing record...\n");

    // --- Use fprintf() to write to the file ---
    fprintf(file_handle, "Student Record\n");
    fprintf(file_handle, "================\n");
    fprintf(file_handle, "Name: %s\n", name);
    fprintf(file_handle, "ID: %d\n", student_id);
    fprintf(file_handle, "GPA: %.2f\n", gpa); // %.2f prints the float with 2 decimal places

    printf("Record written to %s.\n", filename);

    // Close the file to save the data to disk
    fclose(file_handle);

    return 0;
}
#include <stdio.h>

int main(void) {
    FILE *file_handle = NULL;
    const char *filename = "student_record.txt";

    // Variables to hold the data read from the file
    char name[50];
    int student_id;
    float gpa;

    // Open the file for reading
    file_handle = fopen(filename, "r");

    if (file_handle == NULL) {
        printf("Error: Could not open %s for reading.\n", filename);
        return 1;
    }

    // Read from the file using a format string that matches the file's content.
    // Note how "Name:", "ID:", and "GPA:" are part of the format string.
    // The `\n` at the end of each part consumes the newline character.
    int items_read = fscanf(file_handle, "Student Record\n================\nName: %s\nID: %d\nGPA: %f\n",
                           name, &student_id, &gpa);

    // ALWAYS check the return value of fscanf()
    if (items_read == 3) {
        // We successfully read 3 items.
        printf("--- Record Read from File ---\n");
        printf("Name: %s\n", name);
        printf("ID: %d\n", student_id);
        printf("GPA: %.2f\n", gpa);
    } else {
        printf("Error: File content does not match expected format.\n");
        printf("fscanf() expected to read 3 items, but read %d.\n", items_read);
    }

    // Close the file
    fclose(file_handle);

    return 0;
}
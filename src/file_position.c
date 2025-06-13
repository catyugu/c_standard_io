#include <stdio.h>

int main(void) {
    FILE *fp = fopen("data.bin", "rb");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    int number;

    // --- 1. Find the total size of the file ---
    fseek(fp, 0, SEEK_END);      // Jump to the end of the file
    long file_size = ftell(fp);  // Get the current position (which is the size)
    printf("File size is %ld bytes.\n", file_size);

    // --- 2. Read the 5th integer (index 4) ---
    // An integer on my system is 4 bytes. So we jump to offset 4 * 4 = 16.
    long offset = 4 * sizeof(int);
    fseek(fp, offset, SEEK_SET); // Jump 16 bytes from the beginning

    fread(&number, sizeof(int), 1, fp); // Read one integer
    printf("The 5th integer (at offset %ld) is: %d\n", offset, number);

    // --- 3. Read the 2nd to last integer ---
    // We go to the end, then seek backwards by the size of two integers.
    fseek(fp, -2 * sizeof(int), SEEK_END);

    fread(&number, sizeof(int), 1, fp);
    printf("The 2nd to last integer is: %d\n", number);

    // --- 4. Go back to the beginning ---
    printf("Rewinding...\n");
    rewind(fp);

    fread(&number, sizeof(int), 1, fp);
    printf("The very first integer is: %d\n", number);
    
    fclose(fp);
    return 0;
}
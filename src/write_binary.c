#include <stdio.h>

int main(void) {
    FILE *f_out = fopen("data.bin", "wb"); // Notice the "wb"
    if (f_out == NULL) {
        perror("Error opening file");
        return 1;
    }

    int numbers[] = { 1, 2, 4, 8, 16, 32 };
    size_t num_items = sizeof(numbers) / sizeof(int);

    size_t items_written = fwrite(numbers, sizeof(int), num_items, f_out);

    if (items_written == num_items) {
        printf("Successfully wrote %zu integers to data.bin\n", items_written);
    } else {
        fprintf(stderr, "Error: Only wrote %zu out of %zu items.\n", items_written, num_items);
    }

    fclose(f_out);
    return 0;
}
#include <stdio.h>

int main(void) {
    FILE *f_in = fopen("data.bin", "rb"); // Notice the "rb"
    if (f_in == NULL) {
        perror("Error opening file");
        return 1;
    }

    int numbers_read[6];
    size_t num_items = 6;

    size_t items_read = fread(numbers_read, sizeof(int), num_items, f_in);

    if (items_read == num_items) {
        printf("Successfully read %zu integers:\n", items_read);
        for (size_t i = 0; i < items_read; i++) {
            printf("%d\n", numbers_read[i]);
        }
    } else {
        fprintf(stderr, "Error: Only read %zu out of %zu items.\n", items_read, num_items);
    }
    
    fclose(f_in);
    return 0;
}
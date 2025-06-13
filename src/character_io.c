#include <stdio.h>

int main(void) {
    int c; // Use an int to hold the return value of getchar()

    printf("Enter text. Press Ctrl+D (Linux/macOS) or Ctrl+Z (Windows) to signal end-of-file.\n");

    // 1. Read a character
    // 2. Check if it's EOF
    // 3. If not, print it and repeat
    while ((c = getchar()) != EOF) {
        putchar(c);
    }

    printf("\nEnd of input reached.\n");

    return 0;
}
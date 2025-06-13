#include <stdio.h>
#define MAX_LENGTH 80

int main(void) {
    char sentence[MAX_LENGTH];

    printf("Please enter a sentence: ");

    if (fgets(sentence, MAX_LENGTH, stdin) != NULL) {
        printf("You entered: %s", sentence);
    }

    return 0;
}
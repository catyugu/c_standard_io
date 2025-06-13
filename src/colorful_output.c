#include <stdio.h>

// Color and format macros
#define ANSI_RESET          "\x1b[0m"
#define ANSI_BOLD           "\x1b[1m"
#define ANSI_RED_BOLD       "\x1b[1;31m"
#define ANSI_GREEN_BOLD     "\x1b[1;32m"
#define ANSI_YELLOW_BOLD    "\x1b[1;33m"
#define ANSI_BLUE_BOLD      "\x1b[1;34m"

int main() {
    printf(ANSI_BLUE_BOLD "This is bold and blue." ANSI_RESET "\n");
    printf(ANSI_RED_BOLD "This is bold and red." ANSI_RESET "\n");
    
    printf("This is back to the default terminal style.\n");

    return 0;
}
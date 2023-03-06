#include <stdio.h>
#include <stdlib.h>

#include "../include/menu.h"
#include "../include/configuration.h"

#define TRUE 1

int main() {
    while(TRUE) {
        clear_screen();
        char* options[] = { "[1] - List all notes"
                          , "[2] - Create a new note"
                          , "[3] - Search by title"
                          , "[4] - Exit" };
        int choice = generic_menu(options, 4);
        process_user_choice(choice);
    }
    return 0;
}

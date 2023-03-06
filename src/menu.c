#include <stdio.h>
#include <stdlib.h>

#include "../include/menu.h"
#include "../include/configuration.h"

int generic_menu(char* options[], int options_number) {
    int index = 0;
    while(index < options_number) {
        printf("%s\n", options[index]);
        index++;
    }
    int choice;
    printf("\nSelect any option: ");
    scanf("%d", &choice);
    return choice;
}

void process_user_choice(int choice) {
    switch(choice) {
        case 1:
            clear_screen();
            printf("List all needs implements...\n");
            pause_screen();
            break;
        case 2:
            clear_screen();
            printf("Create new note needs implements...\n");
            pause_screen();
            break;
        case 3:
            clear_screen();
            printf("Search some note needs implements...\n");
            pause_screen();
            break;
        case 4:
            exit(0);
            break;
        default:
            clear_screen();
            printf("Invalid selection...try again");
            pause_screen();
            break;
    }
}


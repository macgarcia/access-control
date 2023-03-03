#include <stdio.h>
#include <stdlib.h>

#include "../include/menu.h"

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
    printf("%d\n\n", choice);
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/menu.h"
#include "../include/configuration.h"
#include "../include/note_list.h"
#include "../include/note_repository.h"
#include "../include/note_behavior.h"
#include "../include/note.h"

int generic_menu(char* options[], int options_number) {
    int index = 0;
    while(index < options_number) {
        printf("%s\n", options[index]);
        index++;
    }
    char choice[4];
    printf("\nSelect any option: ");
    fgets(choice, 4, stdin);
    clear_buffer_keyboard();
    return atoi(choice);
}

static void remove_break_line(char line[MAX_LENGTH]) {
    if (line[strlen(line) - 1] == '\n') {
        line[strlen(line) - 1] = '\0';
    }
}

static void create_note() {
    char title[MAX_LENGTH];
    char user[MAX_LENGTH];
    char pass[MAX_LENGTH];

    clear_buffer_keyboard();
    printf("Input title of new note: ");
    fgets(title, MAX_LENGTH, stdin);

    clear_buffer_keyboard();
    printf("Input user of new note: ");
    fgets(user, MAX_LENGTH, stdin);

    clear_buffer_keyboard();
    printf("Input title of new note: ");
    fgets(pass, MAX_LENGTH, stdin);

    remove_break_line(title);
    remove_break_line(user);
    remove_break_line(pass);

    Note note = new_note(title, user, pass);
    save_note(note);
}

static void search() {
    char key[MAX_LENGTH];

    clear_buffer_keyboard();
    printf("Input key to search any note: ");
    fgets(key, MAX_LENGTH, stdin);

    remove_break_line(key);
    printf("\n");
    find_by_filter(key);
}

void process_user_choice(int choice) {
    find_all();
    switch(choice) {
        case 1:
            clear_screen();
            printf("List all notes...\n\n");
            print_list();
            printf("\nNumbers of notes: %d\n\n", get_size_list());
            pause_screen();
            break;
        case 2:
            clear_screen();
            printf("Create new note...\n\n");
            create_note();
            pause_screen();
            break;
        case 3:
            clear_screen();
            printf("Search some note...\n\n");
            search();
            pause_screen();
            break;
        case 4:
            exit(0);
            break;
        default:
            clear_screen();
            printf("Invalid selection...try again\n\n");
            pause_screen();
            break;
    }
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "../include/menu.h"
#include "../include/configuration.h"
#include "../include/note_list.h"
#include "../include/note_repository.h"
#include "../include/note_behavior.h"
#include "../include/note.h"

#define FUNCTIONALITES 4

int generic_menu(char* options[], int options_number) {
    int index = 0;
    char choice[2];
    int controller = 1;
    int i;

    while(controller) {
        // Print menu
        while(index < options_number) {
            printf("%s\n", options[index]);
            index++;
        }
        printf("\nSelect any option: ");
        scanf("%s", choice);

        //Verify if tho user input is a digit
        for (i = 0; choice[i] != '\0'; i++) {
            if (!isdigit(choice[i])) {
                printf("\nInvalid input...\n\n");
                pause_screen();
                clear_screen();
                index = 0;
                break;
            }
        }

        //If input is not null, but is a digit, break the loop
        if (choice[i] == '\0') {
            controller = 0;
        }
    }

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

static void list_all() {
    clear_screen();
    printf("List all notes...\n\n");
    print_list();
    printf("\nNumbers of notes: %d\n\n", get_size_list());
    pause_screen();
}

static void create_new_note() {
    clear_screen();
    printf("Create new note...\n\n");
    create_note();
    pause_screen();
}

static void search_note() {
    clear_screen();
    printf("Search some note...\n\n");
    search();
    pause_screen();
}

static void finish_system() {
    exit(0);
}

void process_user_choice(int choice) {
    find_all();
    void (*cases[FUNCTIONALITES])() = {list_all, create_new_note, search_note, finish_system};
    if (choice > FUNCTIONALITES) {
        clear_screen();
        printf("Invalid selection...try again\n\n");
        pause_screen();
    } else {
        cases[choice - 1]();
    }
}


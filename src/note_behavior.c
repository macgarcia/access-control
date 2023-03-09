#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../include/note_behavior.h"
#include "../include/note.h"

#define DELIMITER "|"
#define MAX_BUFFER 350

static char* to_txt(Note note) {
    static char buffer[MAX_BUFFER];
    snprintf(buffer, sizeof(buffer), "%d|%s|%s|%s\n", note.id, note.title, note.user, note.pass);
    return buffer;
}

static void to_string(Note n) {
    printf("ID: %d\n", n.id);
    printf("Title: %s\n", n.title);
    printf("User: %s\n", n.user);
    printf("Pass: %s\n", n.pass);
    printf("=========================\n");
}

static int generated_value() {
    int id;
    time_t t;

    //Get time now
    t = time(NULL);
    //Define the seed of rand number generator
    srand((unsigned int) t);
    // Builder a random number of four digit
    id = rand() % 10000;
    // Concatenates the current time in seconds with the random number
    id = id + (int) t % 1000000;
    return id;
}

Note new_note(char title[MAX_LENGTH], char user[MAX_LENGTH], char pass[MAX_LENGTH]) {
    Note n;
    n.id = generated_value();
    strcpy(n.title, title);
    strcpy(n.user, user);
    strcpy(n.pass, pass);
    n.to_txt = &to_txt;
    n.to_string = &to_string;
    return n;
}

Note to_note_by_buffer_line(char* buffer_line) {
    char* token;
    Note note;

    token = strtok(buffer_line, DELIMITER);
    note.id = atoi(token);

    token = strtok(NULL, DELIMITER);
    strcpy(note.title, token);

    token = strtok(NULL, DELIMITER);
    strcpy(note.user, token);

    token = strtok(NULL, DELIMITER);
    strcpy(note.pass, token);

    note.to_txt = &to_txt;
    note.to_string = &to_string;

    return note;
}

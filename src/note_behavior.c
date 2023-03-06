#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/note_behavior.h"
#include "../include/note.h"

#define DELIMITER "|"

static int controller_id = 0;

char* to_txt(Note note) {
    static char buffer[150];
    snprintf(buffer, sizeof(buffer), "%d|%s|%s|%s\n", note.id, note.title, note.user, note.pass);
    return buffer;
}

void to_string(Note n) {
    printf("ID: %d\n", n.id);
    printf("Title: %s\n", n.title);
    printf("User: %s\n", n.user);
    printf("Pass: %s\n", n.pass);
    printf("=========================\n");
}

Note new_note(char title[MAX_LENGTH], char user[MAX_LENGTH], char pass[MAX_LENGTH]) {
    Note n;
    n.id = ++controller_id;
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

    ++controller_id;

    note.to_txt = &to_txt;
    note.to_string = &to_string;

    return note;
};

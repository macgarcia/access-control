#include <stdio.h>

#include "../include/note_list.h"
#include "../include/note.h"

#define MAX_TAM_NOTES 1000

Note notes[MAX_TAM_NOTES];
int size_of_list = 0;

void add_list(Note n) {
    notes[size_of_list++] = n;
}

void set_size_list(int size_list) {
    size_of_list = size_list;
}

int get_size_list() {
    return size_of_list;
}

Note* get_notes() {
    return notes;
}

void print_list() {
    int index = 0;
    while(index < size_of_list) {
        Note tmpNote = notes[index];
        tmpNote.to_string(tmpNote);
        index++;
    }
}

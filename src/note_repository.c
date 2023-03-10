#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "../include/note_repository.h"
#include "../include/text_file.h"
#include "../include/note_behavior.h"
#include "../include/note_list.h"
#include "../include/note.h"

void save_note(Note note) {
    FILE* file = get_txt_writing();
    fprintf(file, note.to_txt(note));
    close_txt(file);
}

void find_all() {
    char line[201];
    set_size_list();
    FILE * file = get_txt_reading();
    while(fgets(line, 200, file) != NULL) {
        Note n = to_note_by_buffer_line(line);
        add_list(n);
    }
    close_txt(file);
}

//via chatGpt
char* strlwr(char *str) {
    char* p = str;
    while (*p) {
        *p = tolower((unsigned char)*p);
        p++;
    }
    return str;
}
//

void find_by_filter(char* filter) {
    Note* notes = get_notes();
    char* filter_lower = strlwr(strdup(filter));
    char* tmp_title_lower = NULL;
    for (int i = 0; i < get_size_list(); i++) {
        Note tmp_note = notes[i];
        tmp_title_lower = strlwr(strdup(tmp_note.title));
        if (strstr(tmp_title_lower, filter_lower) != NULL) {
            notes[i].to_string(notes[i]);
        }
    }
}


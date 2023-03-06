#include <stdio.h>

#include "../include/text_file.h"

#define READ "r"
#define APPEND "a"

static const char arq_notes[15] = ".notes.txt";

FILE* get_txt_reading() {
    FILE* file = fopen(arq_notes, READ);
    if (file == NULL) {
        file = fopen(arq_notes, APPEND);
    }
    return file;
}

FILE* get_txt_writing() {
    return fopen(arq_notes, APPEND);
}

void close_txt(FILE* file) {
    fclose(file);
}

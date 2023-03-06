#ifndef NOTE_H_INCLUDED
#define NOTE_H_INCLUDED

#define MAX_LENGTH 100

typedef struct Note {
    int id;
    char title[MAX_LENGTH];
    char user[MAX_LENGTH];
    char pass[MAX_LENGTH];
    char* (*to_txt)(struct Note n);
    void (*to_string)(struct Note n);
} Note;

extern Note note;

#endif // NOTE_H_INCLUDED

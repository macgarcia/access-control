#ifndef NOTE_REPOSITORY_H_INCLUDED
#define NOTE_REPOSITORY_H_INCLUDED

#include "note.h"

void save_note(Note note);
void find_all();
void find_by_filter(char* filter);

#endif // NOTE_REPOSITORY_H_INCLUDED

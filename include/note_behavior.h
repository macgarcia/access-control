#ifndef NOTE_BEHAVIOR_H_INCLUDED
#define NOTE_BEHAVIOR_H_INCLUDED

#include <string.h>
#include "note.h"

extern Note new_note(char title[MAX_LENGTH], char user[MAX_LENGTH], char pass[MAX_LENGTH]);
extern Note to_note_by_buffer_line(char* buffer_line);
#endif // NOTE_BEHAVIOR_H_INCLUDED

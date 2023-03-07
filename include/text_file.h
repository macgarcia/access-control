#ifndef TEXT_FILE_H_INCLUDED
#define TEXT_FILE_H_INCLUDED

#include <stdio.h>

extern FILE* get_txt_reading();
extern FILE* get_txt_writing();

extern void close_txt(FILE* file);

#endif // TEXT_FILE_H_INCLUDED

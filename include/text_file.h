#ifndef TEXT_FILE_H_INCLUDED
#define TEXT_FILE_H_INCLUDED

#include <stdio.h>

FILE* get_txt_reading();
FILE* get_txt_writing();

void close_txt(FILE* file);

#endif // TEXT_FILE_H_INCLUDED

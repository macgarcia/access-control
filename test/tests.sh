#!/bin/sh

mkdir test-obj

echo "Compilation to test of unity of txt access"

gcc -Wall -g -c ../src/text_file.c -o test-obj/text_file.o
gcc -Wall -g -c text_file_test.c -o test-obj/text_file_test.o
gcc -Wall -g -c unit/unity.c -o test-obj/unity.o

gcc -o text_file_test test-obj/text_file.o test-obj/text_file_test.o test-obj/unity.o

#=========

gcc -Wall -g -c ../src/note_list.c -o test-obj/note_list.o
gcc -Wall -g -c note_list_test.c -o test-obj/note_list_test.o

gcc -o note_list_test test-obj/note_list.o test-obj/note_list_test.o test-obj/unity.o

#==========

gcc -Wall -g -c test.c -o test-obj/test.o
gcc -o tests test-obj/test.o

echo "Start tests"
./tests

sh clear-tests.sh
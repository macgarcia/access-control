mkdir test-obj

@echo Compilation to test of unity of txt access

gcc -Wall -g -c ..\src\text_file.c -o test-obj\text_file.o
gcc -Wall -g -c text_file_test.c -o test-obj\text_file_test.o
gcc -Wall -g -c unit\unity.c -o test-obj\unity.o

gcc.exe -o text_file_test.exe test-obj\text_file.o test-obj\text_file_test.o test-obj\unity.o

gcc -Wall -g -c ..\src\note_list.c -o test-obj\note_list.o
gcc -Wall -g -c note_list_test.c -o test-obj\note_list_test.o

gcc -o note_list_test.exe test-obj\note_list.o test-obj\note_list_test.o test-obj\unity.o

gcc -Wall -g -c ..\src\note_behavior.c -o test-obj\note_behavior.o
gcc -Wall -g -c note_behavior_test.c -o test-obj\note_behavior_test.o

gcc -o note_behavior_test.exe test-obj\note_behavior.o test-obj\note_behavior_test.o test-obj\unity.o

gcc -Wall -g -c test.c -o test-obj\test.o
gcc.exe -o tests test-obj\test.o

@echo Start tests
start tests.exe

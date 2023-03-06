mkdir obj
mkdir bin

gcc -Wall -g -c src\main.c -o obj\main.o
gcc -Wall -g -c src\configuration.c -o obj\configuration.o
gcc -Wall -g -c src\menu.c -o obj\menu.o
gcc -Wall -g -c src\note_behavior.c -o obj\note_behavior.o
gcc -Wall -g -c src\note_list.c -o obj\note_list.o
gcc -Wall -g -c src\note_repository.c -o obj\note_repository.o
gcc -Wall -g -c src\text_file.c -o obj\text_file.o

gcc -o bin\access-control obj\main.o obj\configuration.o obj\menu.o obj\note_behavior.o obj\note_list.o obj\note_repository.o obj\text_file.o
#!/bin/sh

mkdir obj
mkdir bin

#gcc -Wall -g -c main.c -o obj/main.o
#gcc -Wall -g -c note_behavior.c -o obj/note_behavior.o
#gcc -Wall -g -c note_repo_txt.c -o obj/note_repo_txt.o
#gcc -Wall -g -c note_repository.c -o obj/note_repository.o
#gcc -Wall -g -c configurations.c -o obj/configurations.o
#gcc -o bin/manager-access obj/main.o obj/note_behavior.o obj/note_repo_txt.o obj/note_repository.o obj/configurations.o

gcc -Wall -g -c src/main.c -o obj/main.o
gcc -Wall -g -c src/configuration.c -o obj/configuration.o
gcc -Wall -g -c src/menu.c -o obj/menu.o

gcc -o bin/access-control obj/main.o obj/configuration.o obj/menu.o
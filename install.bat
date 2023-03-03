mkdir obj
mkdir bin

gcc.exe -Wall -g  -c main.c -o obj\main.o
gcc.exe -Wall -g  -c note_behavior.c -o obj\note_behavior.o
gcc.exe -Wall -g  -c note_repo_txt.c -o obj\note_repo_txt.o
gcc.exe -Wall -g  -c note_repository.c -o obj\note_repository.o
gcc.exe -Wall -g  -c configurations.c -o obj\configurations.o
gcc.exe  -o bin\manager-access.exe obj\main.o obj\note_behavior.o obj\note_repo_txt.o obj\note_repository.o obj\configurations.o

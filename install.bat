mkdir obj
mkdir bin

gcc -Wall -g -c src\main.c -o obj\main.o
gcc -Wall -g -c src\configuration.c -o obj\configuration.o
gcc -Wall -g -c src\menu.c -o obj\menu.o

gcc -o bin\access-control.exe obj\main.o obj\configuration.o obj\menu.o
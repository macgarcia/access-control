#include <stdlib.h>

#include "../include/configuration.h"

void clear_screen() {
    #ifdef __linux__
        system("clear");
    #else
        system("cls");
    #endif
}

void pause_screen() {
    #ifdef __linux__
        system("read -p \"Press any key to exit\" exit");
    #else
        system("pause");
    #endif
}

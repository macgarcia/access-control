#include <stdlib.h>

int main(void) {
    #ifdef __linux__
        system("./text_file_test");
    #else
        system("text_file_test.exe");
    #endif
    return 0;
}

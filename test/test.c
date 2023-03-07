#include <stdlib.h>

int main(void) {
    #ifndef __linux__
        system("./text_file_test");
    #else
        system("text_file_test.exe");
    #endif // __linux__
    return 0;
}

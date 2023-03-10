#include <stdlib.h>

int main(void) {
    #ifdef __linux__
        system("./text_file_test");
        system("./note_list_test");
        system("./note_behavior_test");
    #else
        system("text_file_test.exe");
        system("note_list_test.exe");
        system("note_behavior_test.exe");
        system("pause");
    #endif
    return 0;
}

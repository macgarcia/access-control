#include <string.h>
#include "unit/unity.h"
#include "../include/note_behavior.h"
#include "../include/note.h"

void setUp(){};
void tearDown(){};

void new_note_test() {
    char title[MAX_LENGTH] = "title-test";
    char user[MAX_LENGTH] = "user-test";
    char pass[MAX_LENGTH] = "pass-test";

    Note n = new_note(title, user, pass);
    TEST_ASSERT(n.id > 0);
    TEST_ASSERT(strcmp(title, n.title) == 0);
}

void to_note_by_buffer_line_test() {
    char line[MAX_LENGTH] = "1|title-test|user-test|pass-test";
    Note n = to_note_by_buffer_line(line);
    TEST_ASSERT(n.id == 1);
    TEST_ASSERT(strcmp("title-test", n.title) == 0);
}

int main(void) {
    printf("\n\nTests on note_behavior.\n\n");
    UNITY_BEGIN();
    RUN_TEST(new_note_test);
    RUN_TEST(to_note_by_buffer_line_test);
    return UNITY_END();
}

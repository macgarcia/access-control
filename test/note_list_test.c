#include "unit/unity.h"
#include "../include/note_list.h"
#include "../include/note.h"

void setUp(){};
void tearDown(){};

void add_new_note_test() {
    Note n = {1, "teste-title", "teste-user", "teste-pass"};
    add_list(n);
    TEST_ASSERT(get_size_list() == 1);
}

void set_size_list_test() {
    Note n = {1, "teste-title", "teste-user", "teste-pass"};
    add_list(n);
    set_size_list();
    TEST_ASSERT(get_size_list() == 0);
}

void get_size_list_test() {
    int size = get_size_list();
    TEST_ASSERT_EQUAL(size, 0);
    Note n = {1, "teste-title", "teste-user", "teste-pass"};
    add_list(n);
    size = get_size_list();
    TEST_ASSERT_EQUAL(size, 1);
}

void get_notes_test() {
    set_size_list();
    Note n1 = {1, "teste-title1", "teste-user", "teste-pass"};
    Note n2 = {2, "teste-title2", "teste-user2", "teste-pass2"};
    add_list(n1);
    add_list(n2);
    Note* notes = get_notes();
    TEST_ASSERT_EQUAL(notes[0].id, n1.id);
    TEST_ASSERT_EQUAL(notes[1].id, n2.id);
    TEST_ASSERT_EQUAL_CHAR_ARRAY(n1.title, notes[0].title, MAX_LENGTH);
}

int main() {
    printf("\n\nTests on note_list.\n\n");
    UNITY_BEGIN();
    RUN_TEST(add_new_note_test);
    RUN_TEST(set_size_list_test);
    RUN_TEST(get_size_list_test);
    RUN_TEST(get_notes_test);
    return UNITY_END();
}

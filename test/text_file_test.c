#include <stdio.h>
#include <stdlib.h>
#include "unit/unity.h"

#include "../include/text_file.h"

void setUp(){};
void tearDown(){};

void test_get_txt_reading() {
    FILE* file = get_txt_reading();
    TEST_ASSERT_GREATER_THAN(0, file);
    TEST_ASSERT(file != NULL);
}

void test_get_txt_writing() {
    FILE* file = get_txt_writing();
    TEST_ASSERT_GREATER_THAN(0, file);
    TEST_ASSERT(file != NULL);
}

void test_close_txt() {
    FILE* file = get_txt_reading();
    close_txt(file);
    TEST_ASSERT(file != NULL);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_get_txt_reading);
    RUN_TEST(test_get_txt_writing);
    RUN_TEST(test_close_txt);
    system("pause");
    return UNITY_END();
}

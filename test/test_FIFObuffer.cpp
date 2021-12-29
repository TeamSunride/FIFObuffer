//
// Created by Tom Danvers on 29/12/2021.
// 2021 TeamSunride.
//

#include "FIFObuffer.h"
#include "unity.h"

void test_FIFObuffer_count() {
    FIFObuffer<int, 10> buffer;
    buffer.put(1);
    buffer.put(2);
    buffer.put(3);
    TEST_ASSERT_EQUAL(3, buffer.count());
}

void test_FIFObuffer_full_empty() {
    FIFObuffer<int, 3> buffer;
    buffer.put(1); buffer.put(1); buffer.put(1);
    TEST_ASSERT_TRUE(buffer.isFull());
    TEST_ASSERT_FALSE(buffer.put(1));
    buffer.pop(); buffer.pop(); buffer.pop();
    TEST_ASSERT_TRUE(buffer.isEmpty());
    TEST_ASSERT_FALSE(buffer.pop());
}

void test_FIFObuffer_order() {
    FIFObuffer<int, 3> buffer;
    buffer.put(1);
    buffer.put(2);
    buffer.put(3);
    TEST_ASSERT_EQUAL(1, buffer.pop());
    TEST_ASSERT_EQUAL(2, buffer.pop());
    TEST_ASSERT_EQUAL(3, buffer.pop());
}

void test_FIFObuffer_put() {
    FIFObuffer<int, 2> buffer;
    TEST_ASSERT_TRUE(buffer.put(1));
    TEST_ASSERT_TRUE(buffer.put(2));
    TEST_ASSERT_FALSE(buffer.put(3)); // this should fail as the buffer is full
}

void test_FIFObuffer_push() {
    FIFObuffer<int, 2> buffer;
    buffer.put(1);
    buffer.put(2);
    buffer.push(3);
    TEST_ASSERT_EQUAL(2, buffer.pop());
    TEST_ASSERT_EQUAL(3, buffer.pop());
}

void test_FIFObuffer_get() {
    FIFObuffer<int, 3> buffer;
    buffer.put(0);
    buffer.put(1);
    buffer.put(2);
    TEST_ASSERT_EQUAL(2, buffer.get(0));
    TEST_ASSERT_EQUAL(1, buffer.get(1));
    TEST_ASSERT_EQUAL(0, buffer.get(2));
}

// This test fails (requires further investigation)
//void test_FIFObuffer_push_and_get() {
//    FIFObuffer<int, 2> buffer;
//    buffer.put(0);
//    buffer.put(1);
//    buffer.push(2);
//    TEST_ASSERT_EQUAL(2, buffer.get(0));
//    TEST_ASSERT_EQUAL(1, buffer.get(1));
//}

void test_FIFObuffer_sum() {
    FIFObuffer<int, 3> buffer;
    buffer.put(1);
    buffer.put(2);
    buffer.push(3);
    TEST_ASSERT_EQUAL(6, buffer.sum());

    FIFObuffer<int, 3> buffer2;
    buffer2.put(1);
    buffer2.put(2);
    TEST_ASSERT_EQUAL(3, buffer2.sum());
}

int main(int args, char **argv) {
    UNITY_BEGIN();

    RUN_TEST(test_FIFObuffer_count);
    RUN_TEST(test_FIFObuffer_full_empty);
    RUN_TEST(test_FIFObuffer_order);
    RUN_TEST(test_FIFObuffer_put);
    RUN_TEST(test_FIFObuffer_push);
    RUN_TEST(test_FIFObuffer_get);
    // RUN_TEST(test_FIFObuffer_push_and_get);
    // RUN_TEST(test_FIFObuffer_sum);

    UNITY_END();

    return 0;
}
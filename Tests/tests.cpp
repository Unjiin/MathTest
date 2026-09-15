#include <gtest/gtest.h>
// Функция, которую будем тестировать
int add(int a, int b) {
    return a + b;
}

// Первый аргумент — имя группы тестов (TestSuite)
// Второй аргумент — имя конкретного теста (TestCase)
TEST(AdditionTest, HandlesPositiveNumbers) {
    EXPECT_EQ(add(1, 2), 3);
    EXPECT_EQ(add(10, 20), 30);
}

TEST(AdditionTest, HandlesZero) {
    EXPECT_EQ(add(0, 0), 0);
    EXPECT_EQ(add(-5, 5), 0);
}
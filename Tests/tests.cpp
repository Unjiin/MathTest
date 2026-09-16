#include <gtest/gtest.h>
#include "../Lib/Task.h"

// Проверяем конструктор по умолчанию
TEST(TaskTest, DefaultConstructor) {
    Task task;

    // Проверяем, что операция допустимая
    EXPECT_TRUE(
        task.operation == '+' ||
        task.operation == '-' ||
        task.operation == '*'
    );

    // Проверяем правильность ответа
    if (task.operation == '+')
        EXPECT_EQ(task.answer, task.num_1 + task.num_2);
    else if (task.operation == '-')
        EXPECT_EQ(task.answer, task.num_1 - task.num_2);
    else if (task.operation == '*')
        EXPECT_EQ(task.answer, task.num_1 * task.num_2);
}


// Проверяем диапазон чисел
TEST(TaskTest, RangeConstructor) {
    Task task(5, 20);

    EXPECT_GE(task.num_1, 5);
    EXPECT_LE(task.num_1, 20);

    EXPECT_GE(task.num_2, 5);
    EXPECT_LE(task.num_2, 20);
}


// Проверяем заданную операцию +
TEST(TaskTest, PlusOperation) {
    Task task(1, 10, '+');

    EXPECT_EQ(task.operation, '+');
    EXPECT_EQ(task.answer, task.num_1 + task.num_2);
}


// Проверяем заданную операцию -
TEST(TaskTest, MinusOperation) {
    Task task(1, 10, '-');

    EXPECT_EQ(task.operation, '-');
    EXPECT_EQ(task.answer, task.num_1 - task.num_2);
}


// Проверяем заданную операцию *
TEST(TaskTest, MultiplyOperation) {
    Task task(1, 10, '*');

    EXPECT_EQ(task.operation, '*');
    EXPECT_EQ(task.answer, task.num_1 * task.num_2);
}
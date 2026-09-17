#include <gtest/gtest.h>
#include "task.h"
#include "MathTest.h"

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



TEST(MathTestTest, ConstructorCount) {
    MathTest test(5);

    EXPECT_EQ(test.getCount(), 5);
    EXPECT_EQ(test.getCorrectCount(), 0);
}


TEST(MathTestTest, RangeConstructor) {
    MathTest test(10, 5, 20);

    EXPECT_EQ(test.getCount(), 10);

    for (int i = 0; i < test.getCount(); i++) {
        Task task = test.getTask(i);

        EXPECT_GE(task.num_1, 5);
        EXPECT_LE(task.num_1, 20);

        EXPECT_GE(task.num_2, 5);
        EXPECT_LE(task.num_2, 20);
    }
}


TEST(MathTestTest, OperationConstructor) {
    MathTest test(10, 1, 20, '+');

    for (int i = 0; i < test.getCount(); i++) {
        Task task = test.getTask(i);

        EXPECT_EQ(task.operation, '+');
    }
}


TEST(MathTestTest, CorrectAnswer) {
    MathTest test(5, 1, 10, '+');

    Task task = test.getTask(0);

    test.addAnswer(0, task.answer);

    EXPECT_EQ(test.getUserAnswer(0), task.answer);
    EXPECT_EQ(test.getCorrectCount(), 1);
}


TEST(MathTestTest, WrongAnswer) {
    MathTest test(5, 1, 10, '+');

    Task task = test.getTask(0);

    test.addAnswer(0, task.answer + 1000);

    EXPECT_EQ(test.getCorrectCount(), 0);
}
#ifndef MATHTEST_TASK_H
#define MATHTEST_TASK_H

struct Task {
    int num_1;
    int num_2;
    char operation;
    int answer{};

    Task();

    Task(int min, int max, char operation = '\0');

    void calculateAnswer();
};

class MathTest;

#endif
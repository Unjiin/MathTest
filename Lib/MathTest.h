#ifndef MATHTEST_MATHTEST_H
#define MATHTEST_MATHTEST_H

#include "task.h"

class MathTest {
private:
    Task* tasks;
    int count;

    int* user_answers;
    int correct_count;

public:
    MathTest(int count);

    MathTest(int count, int min, int max);

    MathTest(int count, int min, int max, char operation);

    ~MathTest();

    void run();

    void show_statistics();

    void addAnswer(int index, int answer);

    int getCorrectCount() const;

    int getCount() const;

    Task getTask(int index) const;

    int getUserAnswer(int index) const;
};

#endif
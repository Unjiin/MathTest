#include "task.h"
#include <cstdlib>

Task::Task() {
    num_1 = rand() % 10 + 1;
    num_2 = rand() % 10 + 1;

    int op = rand() % 3;

    if (op == 0)
        operation = '+';
    else if (op == 1)
        operation = '-';
    else
        operation = '*';

    calculateAnswer();
}

Task::Task(int min, int max, char op) {
    num_1 = rand() % (max - min + 1) + min;
    num_2 = rand() % (max - min + 1) + min;

    if (op == '\0') {
        int randomOp = rand() % 3;

        if (randomOp == 0)
            operation = '+';
        else if (randomOp == 1)
            operation = '-';
        else
            operation = '*';
    }
    else {
        operation = op;
    }

    calculateAnswer();
}

void Task::calculateAnswer() {
    if (operation == '+')
        answer = num_1 + num_2;
    else if (operation == '-')
        answer = num_1 - num_2;
    else if (operation == '*')
        answer = num_1 * num_2;
}
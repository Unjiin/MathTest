#include "MathTest.h"
#include <iostream>
#include <iomanip>

MathTest::MathTest(int count) {
    this->count = count;
    correct_count = 0;

    tasks = new Task[count];
    user_answers = new int[count];

    for (int i = 0; i < count; i++) {
        user_answers[i] = 0;
    }
}


MathTest::MathTest(int count, int min, int max) {
    this->count = count;
    correct_count = 0;

    tasks = new Task[count];
    user_answers = new int[count];

    for (int i = 0; i < count; i++) {
        tasks[i] = Task(min, max);
        user_answers[i] = 0;
    }
}


MathTest::MathTest(int count, int min, int max, char operation) {
    this->count = count;
    correct_count = 0;

    tasks = new Task[count];
    user_answers = new int[count];

    for (int i = 0; i < count; i++) {
        tasks[i] = Task(min, max, operation);
        user_answers[i] = 0;
    }
}


MathTest::~MathTest() {
    delete[] tasks;
    delete[] user_answers;
}


void MathTest::addAnswer(int index, int answer) {
    user_answers[index] = answer;

    if (answer == tasks[index].answer) {
        correct_count++;
    }
}


void MathTest::run() {
    for (int i = 0; i < count; i++) {
        std::cout << "Question " << i + 1 << ": ";
        std::cout << tasks[i].num_1 << " "
                  << tasks[i].operation << " "
                  << tasks[i].num_2 << " = ";

        int answer;
        std::cin >> answer;

        addAnswer(i, answer);
    }

    show_statistics();
}


void MathTest::show_statistics() {
    std::cout << "\n";

    std::cout << std::setw(12) << "No |";
    for (int i = 0; i < count; i++) {
        std::cout << std::setw(8) << i + 1 << " |";
    }

    std::cout << "\n";


    std::cout << std::setw(12) << "Question |";
    for (int i = 0; i < count; i++) {
        std::cout << std::setw(3) << tasks[i].num_1
                  << " " << tasks[i].operation << " "
                  << std::setw(2) << tasks[i].num_2 << " |";
    }

    std::cout << "\n";


    std::cout << std::setw(12) << "True Answer |";
    for (int i = 0; i < count; i++) {
        std::cout << std::setw(8) << tasks[i].answer << " |";
    }

    std::cout << "\n";


    std::cout << std::setw(12) << "Your Answer |";
    for (int i = 0; i < count; i++) {
        std::cout << std::setw(8) << user_answers[i] << " |";
    }

    std::cout << "\n";


    std::cout << std::setw(12) << "Result |";
    for (int i = 0; i < count; i++) {
        if (user_answers[i] == tasks[i].answer)
            std::cout << std::setw(8) << "+" << " |";
        else
            std::cout << std::setw(8) << "-" << " |";
    }

    std::cout << "\n";

    char mark;

    double percent = (double)correct_count / count * 100;

    if (percent >= 90)
        mark = 'A';
    else if (percent >= 75)
        mark = 'B';
    else if (percent >= 60)
        mark = 'C';
    else if (percent >= 50)
        mark = 'D';
    else
        mark = 'F';

    std::cout << "\nTotal Result: "
              << correct_count << " / " << count
              << " (mark: " << mark << ")\n";
}



int MathTest::getCorrectCount() const {
    return correct_count;
}

int MathTest::getCount() const {
    return count;
}

Task MathTest::getTask(int index) const {
    return tasks[index];
}

int MathTest::getUserAnswer(int index) const {
    return user_answers[index];
}
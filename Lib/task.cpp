

struct Task {
    int num_1;
    int num_2;
    char operation;
    int answer;

    Task(); // базовый конструктор

    Task(int min, int max, char operation = '\0'); // конструктор инициализации
};
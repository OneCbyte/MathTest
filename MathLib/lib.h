#pragma once

struct Task
{
    int num_1;
    int num_2;
    char operation;
    int answer;

    Task();
    Task(int min, int max, char operation = '\0');
};

class MathTest
{
private:
    Task* tasks;
    int count;
    int* user_answers;
    int correct_count;

    void create_tasks(int min, int max, char operation);

public:
    MathTest(int count);
    MathTest(int count, int min, int max);
    MathTest(int count, int min, int max, char operation);
    ~MathTest();

    void run();
    void show_statistics();
    bool check_answer(int index, int user_answer);

    int get_count() const;
    int get_correct_count() const;
    Task get_task(int index) const;
    int get_user_answer(int index) const;

    static char get_mark(int correct, int total);
};
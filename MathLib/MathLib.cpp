#include "Lib.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int random_number(int min, int max)
{
    return min + rand() % (max - min + 1);
}

char random_operation()
{
    int number = random_number(0, 3);

    if (number == 0) return '+';
    if (number == 1) return '-';
    if (number == 2) return '*';
    return '/';
}

int calculate_answer(int num_1, int num_2, char operation)
{
    if (operation == '+') return num_1 + num_2;
    if (operation == '-') return num_1 - num_2;
    if (operation == '*') return num_1 * num_2;
    if (operation == '/' && num_2 != 0) return num_1 / num_2;

    return 0;
}

Task::Task()
{
    num_1 = random_number(1, 20);
    num_2 = random_number(1, 20);
    operation = random_operation();

    if (operation == '/')
    {
        num_2 = random_number(1, 20);
        num_1 = num_2 * random_number(1, 20);
    }

    answer = calculate_answer(num_1, num_2, operation);
}

Task::Task(int min, int max, char selected_operation)
{
    operation = selected_operation;

    if (operation == '\0')
        operation = random_operation();

    num_1 = random_number(min, max);
    num_2 = random_number(min, max);

    if (operation == '/')
    {
        num_2 = random_number(min, max);

        if (num_2 == 0)
            num_2 = 1;

        num_1 = num_2 * random_number(min, max);
    }

    answer = calculate_answer(num_1, num_2, operation);
}

void MathTest::create_tasks(int min, int max, char operation)
{
    tasks = new Task[count];
    user_answers = new int[count];

    for (int i = 0; i < count; i++)
    {
        tasks[i] = Task(min, max, operation);
        user_answers[i] = 0;
    }
}

MathTest::MathTest(int test_count)
{
    count = test_count;
    correct_count = 0;
    create_tasks(1, 20, '\0');
}

MathTest::MathTest(int test_count, int min, int max)
{
    count = test_count;
    correct_count = 0;
    create_tasks(min, max, '\0');
}

MathTest::MathTest(int test_count, int min, int max, char operation)
{
    count = test_count;
    correct_count = 0;
    create_tasks(min, max, operation);
}

MathTest::~MathTest()
{
    delete[] tasks;
    delete[] user_answers;
}

bool MathTest::check_answer(int index, int user_answer)
{
    user_answers[index] = user_answer;

    if (user_answer == tasks[index].answer)
    {
        correct_count++;
        return true;
    }

    return false;
}

void MathTest::run()
{
    for (int i = 0; i < count; i++)
    {
        cout << tasks[i].num_1 << " " << tasks[i].operation << " "
            << tasks[i].num_2 << " = ";

        int answer;
        cin >> answer;
        check_answer(i, answer);
    }

    show_statistics();
}

void MathTest::show_statistics()
{
    cout << "|          No |";

    for (int i = 0; i < count; i++)
        cout << " " << i + 1 << " |";

    cout << endl;
    cout << "+---------------------------------------------------------------+" << endl;

    cout << "|    Question |";

    for (int i = 0; i < count; i++)
    {
        cout << " " << tasks[i].num_1 << " " << tasks[i].operation
            << " " << tasks[i].num_2 << " |";
    }

    cout << endl;
    cout << "| True Answer |";

    for (int i = 0; i < count; i++)
        cout << " " << tasks[i].answer << " |";

    cout << endl;
    cout << "| Your Answer |";

    for (int i = 0; i < count; i++)
        cout << " " << user_answers[i] << " |";

    cout << endl;
    cout << "|      Result |";

    for (int i = 0; i < count; i++)
    {
        if (user_answers[i] == tasks[i].answer)
            cout << "       + |";
        else
            cout << "       - |";
    }

    cout << endl << endl;

    cout << "Total Result: " << correct_count << " / " << count;
    cout << " (mark: " << get_mark(correct_count, count) << ")" << endl;
}

int MathTest::get_count() const
{
    return count;
}

int MathTest::get_correct_count() const
{
    return correct_count;
}

Task MathTest::get_task(int index) const
{
    return tasks[index];
}

int MathTest::get_user_answer(int index) const
{
    return user_answers[index];
}

char MathTest::get_mark(int correct, int total)
{
    if (total == 0) return 'F';

    double percent = static_cast<double>(correct) / total;

    if (percent >= 0.9) return 'A';
    if (percent >= 0.75) return 'B';
    if (percent >= 0.5) return 'C';
    if (percent >= 0.3) return 'D';

    return 'F';
}

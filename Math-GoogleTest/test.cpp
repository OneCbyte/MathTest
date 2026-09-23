#include "pch.h"
#include "lib.h"

TEST(TaskTest, ConstructorWithOperation)
{
    Task task(2, 2, '+');

    EXPECT_EQ(task.num_1, 2);
    EXPECT_EQ(task.num_2, 2);
    EXPECT_EQ(task.operation, '+');
    EXPECT_EQ(task.answer, 4);
}

TEST(TaskTest, DefaultConstructorCreatesTask)
{
    Task task;

    EXPECT_TRUE(
        task.operation == '+' ||
        task.operation == '-' ||
        task.operation == '*' ||
        task.operation == '/'
    );
}

TEST(MathTestTest, ConstructorCreatesCorrectNumberOfQuestions)
{
    MathTest test(5, 1, 10, '+');

    EXPECT_EQ(test.get_count(), 5);
    EXPECT_EQ(test.get_correct_count(), 0);

    for (int i = 0; i < test.get_count(); i++)
    {
        EXPECT_EQ(test.get_task(i).operation, '+');
    }
}

TEST(MathTestTest, CorrectAnswerIncreasesCounter)
{
    MathTest test(1, 2, 2, '+');

    bool result = test.check_answer(0, 4);

    EXPECT_TRUE(result);
    EXPECT_EQ(test.get_user_answer(0), 4);
    EXPECT_EQ(test.get_correct_count(), 1);
}

TEST(MathTestTest, WrongAnswerDoesNotIncreaseCounter)
{
    MathTest test(1, 2, 2, '+');

    bool result = test.check_answer(0, 10);

    EXPECT_FALSE(result);
    EXPECT_EQ(test.get_user_answer(0), 10);
    EXPECT_EQ(test.get_correct_count(), 0);
}

TEST(MathTestTest, MarkIsCalculated)
{
    EXPECT_EQ(MathTest::get_mark(5, 5), 'A');
    EXPECT_EQ(MathTest::get_mark(3, 5), 'C');
}
#include <iostream>
#include <time.h>

struct students
{
    int rating_grade;
    int exam_grade;
};

students *study_book;

void make_study_book(int n)
{
    srand(time(NULL));
    study_book = new students[n];
    for (int i = 0; i < n; ++i)
    {
        study_book[i].exam_grade = rand() % 100;
        study_book[i].rating_grade = rand() % 100;
    }
}

int main()
{
    int n, rate_excellent, rate_good, rate_enough, exam_excellent, exam_good, exam_enough;
    std::cout << "Number of students: ";
    std::cin >> n;
    make_study_book(n);

    for (int i = 0; i < n; ++i)
    {
        if (study_book[i].rating_grade <= 60)
        {
            if (study_book[i].rating_grade >= 40)
                ++rate_enough;
        }
        else if (study_book[i].rating_grade <= 80)
        {
            if (study_book[i].rating_grade >= 60)
                ++rate_good;
        }
        else if (study_book[i].rating_grade <= 100)
        {
            if (study_book[i].rating_grade >= 80)
                ++rate_excellent;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        if (study_book[i].exam_grade <= 60)
        {
            if (study_book[i].exam_grade >= 40)
                ++exam_enough;
        }
        else if (study_book[i].exam_grade <= 80)
        {
            if (study_book[i].exam_grade >= 60)
                ++exam_good;
        }
        else if (study_book[i].exam_grade <= 100)
        {
            if (study_book[i].exam_grade >= 80)
                ++exam_excellent;
        }
    }

    std::cout << "Exam statistics \n"
              << "Enough: " << exam_enough << std::endl
              << "Good: " << exam_good << std::endl
              << "Excellent: " << exam_excellent << std::endl;

    std::cout << "Rating grade statistics \n"
              << "Enough: " << rate_enough << std::endl
              << "Good: " << rate_good << std::endl
              << "Excellent: " << rate_excellent << std::endl;
}
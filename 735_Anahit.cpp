#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <time.h>

struct subjects
{
    std::string Name;
    int rating_grade;
    int exam_grade;
};

std::string path = "subjects.txt";
std::ifstream input;
std::string str;
std::string::iterator it;
char space = ' ';
char new_line = '\000';
std::vector<subjects> subject;
subjects one_subject;

void make_study_book()
{
    srand(time(NULL));
    input.open(path);

    if (!input.is_open())
        return;

    for (int i = 0; !input.eof(); ++i)
    {
        str = "";
        std::getline(input, str);
        it = str.begin();
        one_subject.rating_grade = rand() % 101;
        one_subject.exam_grade = rand() % 101;
        while (*it != new_line)
        {
            one_subject.Name.push_back(*it);
            ++it;
        }
        subject.push_back(one_subject);
        one_subject.Name.clear();
    }
    input.close();
}

int main()
{
    int a, b;
    make_study_book();
    std::cout << "Number of subjects: " << subject.size() << std::endl;
    std::cout << "a: ";
    std::cin >> a;
    std::cout << "b: ";
    std::cin >> b;

    for (int i = 0; i < subject.size(); ++i)
        if (subject[i].rating_grade >= a && subject[i].exam_grade > b)
        std::cout << subject[i].Name << std::endl;

}
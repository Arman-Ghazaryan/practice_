#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <time.h>

struct students
{
    std::string Name;
    std::string Surname;
    int midgrade;
    int number;
};

std::string path = "names.txt";
std::ifstream input;
std::string str;
std::string::iterator it;
char space = ' ';
char new_line = '\000';
std::vector<students> study_book;
students one_stdnt;

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
        one_stdnt.number = i + 1;
        one_stdnt.midgrade = rand() % 50 + 50;
        while (*it != space)
        {
            one_stdnt.Surname.push_back(*it);
            ++it;
        }
        ++it;
        while (*it != new_line)
        {
            one_stdnt.Name.push_back(*it);
            ++it;
        }
        study_book.push_back(one_stdnt);
        one_stdnt.Name.clear();
        one_stdnt.Surname.clear();
    }
    input.close();
}

int main()
{
    make_study_book();
    int a, b;
    std::cout << "Number of students: " << study_book.size() << std::endl;
    std::cout << "Please enter the range" << std::endl;
    std::cout << "a: ";
    std::cin >> a;
    std::cout << "b: ";
    std::cin >> b;

    for (int i = 0; i < study_book.size(); ++i)
    {
        if (a <= study_book[i].midgrade && study_book[i].midgrade <= b)
        {
            std::cout << study_book[i].number << " ";
            std::cout << study_book[i].Name << " ";
            std::cout << study_book[i].Surname << std::endl;
        }
    }
}

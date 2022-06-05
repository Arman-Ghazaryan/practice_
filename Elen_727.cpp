#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <time.h>

struct students
{
    std::string Surname;
    std::string City;
    int age;
};

std::string path = "surnames_only.txt";
std::ifstream input;
std::string str;
std::string::iterator it;
char space = ' ';
char new_line = '\000';
std::vector<students> study_book;
std::string Cities[5] = {"Erevan", "Gyumri", "Vanadzor", "Ijevan", "Kapan"};
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
        one_stdnt.age = rand() % 5 + 17;
        one_stdnt.City = Cities[rand() % 5];
        while (*it != new_line)
        {
            one_stdnt.Surname.push_back(*it);
            ++it;
        }
        study_book.push_back(one_stdnt);
        one_stdnt.Surname.clear();
    }
    input.close();
}

int main()
{
    make_study_book();
    std::cout << "Number of students: " << study_book.size() << std::endl;

    for (int i = 0; i < study_book.size(); ++i)
        if (study_book[i].age >= 20 && study_book[i].City == "Erevan")
            std::cout << study_book[i].Surname << std::endl;
}
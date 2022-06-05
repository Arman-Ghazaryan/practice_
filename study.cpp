#include <fstream>
#include <iostream>
#include <string>
#include <vector>

struct students
{
    std::string Name;
    std::string Surname;
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
    input.open(path);

    if (!input.is_open())
        return;

    for (int i = 0; !input.eof(); ++i)
    {
        str = "";
        std::getline(input, str);
        it = str.begin();
        one_stdnt.number = i + 1;
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
    int fpos, lpos;
    char nflet, snflet;
    std::cout << "Number of students: " << study_book.size() << std::endl;
    std::cout << "Please enter the range" << std::endl;
    std::cout << "First pos: ";
    std::cin >> fpos;
    std::cout << "Last pos: ";
    std::cin >> lpos;
    std::cout << "Please enter the first letter of name and surname of students you want find" << std::endl;
    std::cout << "First letter of name: ";
    std::cin >> nflet;
    std::cout << "First letter of surname: ";
    std::cin >> snflet;

    for (int i = fpos - 1; i <= lpos - 1; ++i)
    {
        if (study_book[i].Name.front() == nflet && study_book[i].Surname.front() == snflet)
        {
            std::cout << study_book[i].Name << " ";
            std::cout << study_book[i].Surname << std::endl;
        }
    }
}
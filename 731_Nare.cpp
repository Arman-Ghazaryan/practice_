#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <time.h>

struct library
{
    std::string Surname;
    int page_count;
    int price;
};

std::string path = "surnames_only.txt";
std::ifstream input;
std::string str;
std::string::iterator it;
char space = ' ';
char new_line = '\000';
std::vector<library> lib;
library book;

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
        book.page_count = rand() % 700;
        book.price = (rand() % 10 + 1) * 1000;
        while (*it != new_line)
        {
            book.Surname.push_back(*it);
            ++it;
        }
        lib.push_back(book);
        book.Surname.clear();
    }
    input.close();
}

int main()
{
    int k;
    make_study_book();
    std::cout << "Number of library: " << lib.size() << std::endl;
    std::cout << "k: ";
    std::cin >> k;

    for (int i = 0; i < lib.size(); ++i)
    {
        if (lib[i].price >= k)
            lib[i].price *= 2;

        std::cout << lib[i].Surname << std::endl;
        std::cout << lib[i].price << std::endl;
    }
}
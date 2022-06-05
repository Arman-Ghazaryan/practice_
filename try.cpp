#include <iostream>
#include <time.h>

int main()
{
    srand(time(NULL));
    for (size_t i = 0; i < 100; i++)
    {
        /* code */
    std::cout << rand() % 5 << " "; 
    }
    
}
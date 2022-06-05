#include <iostream>
#include <time.h>

int main()
{
    srand(time(NULL));
    int m, n, line, count = 0;
    std::cout << "m = ";
    std::cin >> m;
    std::cout << "n = ";
    std::cin >> n;
    int matrix[m][n];
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            matrix[i][j] = rand() % 200 - 100;
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    for (int i = 0; i < n - 1; ++i)
    {
        for (line = 0; line != m && matrix[line][i] < 0; ++line)
            ;
        if (line == m)
        {
            for (int l = 0, temp; l < m; ++l)
            {
                temp = matrix[l][n - 1];
                matrix[l][n - 1] = matrix[l][i];
                matrix[l][i] = temp;
            }
            break;
        }
    }
    std::cout << std::endl;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
            std::cout << matrix[i][j] << "\t";
        std::cout << std::endl;
    }
}
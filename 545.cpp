#include <iostream>
#include <time.h>

int check(int arr[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        if (arr[i] > arr[i + 1])
        {
            if (i == n - 2)
                return 1;
        }
        else
            break;
    }
    for (int i = 0; i < n - 1; ++i)
    {
        if (arr[i] < arr[i + 1])
        {
            if (i == n - 2)
                return 2;
        }
        else
            break;
    }
    return 0;
}

int main()
{
    srand(time(NULL));
    int m, n, count = 0;
    std::cout << "m = ";
    std::cin >> m;
    std::cout << "n = ";
    std::cin >> n;
    int matrix[m][n];

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            matrix[i][j] = rand() % 100;
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < m; ++i)
    {
        switch (check(matrix[i], n))
        {
        case 1:
            std::cout << "matrix[" << i << "][0] " << matrix[i][0] << std::endl;
            ++count;
            break;
        case 2:
            std::cout << "matrix[" << i << "][" << n - 1 << "]" << matrix[i][n - 1] << std::endl;
            ++count;
            break;
        default:
            break;
        }
    }

    if (!count)
        std::cout << "NO" << std::endl
                  << std::endl;
}
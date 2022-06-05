
#include <iostream>
#include <time.h>
constexpr int n = 90;

int main()
{
    srand(time(NULL));
    int arr[n];
    int cnt = 0, sum = 0;

    for (int i = 0; i < n; ++i)
    {
        arr[i] = rand() % 100;
        std::cout << arr[i] << " ";
        if (i == 30 || i == 60)
            std::cout << std::endl;
    }

    for (int i = 0; i < n; ++i, cnt = 0)
    {
        for (int j = 0; j < n; ++j)
        {
            if (arr[i] == arr[j] && i != j)
            {
                ++cnt;
                if (cnt > 2)
                    break;
            }
        }
        if (cnt == 2)
            sum += arr[i];
    }
    std::cout << std::endl
              << "sum = " << sum << std::endl
              << std::endl;
}
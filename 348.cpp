
#include <iostream>

int main()
{
    int n;
    std::cout << "n = ";
    std::cin >> n;
    int arr[n];
    int k;
    std::cout << "k = ";
    std::cin >> k;
    int min, len = 0, resarr[n];

    for (int i = 0; i < n; ++i)
        std::cin >> arr[i];

    for (int i = 0; i < n; i++)
    {
        if (i % k == 2)
        {
            resarr[len] = i;
            ++len;
        }
    }

    min = 0;
    for (int i = 1; i < len; ++i)
        if (arr[resarr[i]] < arr[resarr[min]])
            min = i;

    std::cout << std::endl
              << "min = " << arr[resarr[min]] << std::endl
              << std::endl;
}
#include <iostream>
#include <time.h>
constexpr int n = 10;
int *arrZ = new int[n];
int Size = 0;

void newArr(int x)
{
    int *arr = new int[Size + 1];
    for (int i = 0; i < Size; ++i)
        arr[i] = arrZ[i];
    arr[Size] = x;
    ++Size;
    delete arrZ;
    arrZ = arr;
}

int main()
{
    int arrX[n], arrY[n];
    srand(time(NULL));
    for (int i = 0; i < n; ++i)
    {
        arrX[i] = rand() % 30;
        arrY[i] = rand() % 30;
        std::cout << "arrX[" << i << "] = " << arrX[i] << std::endl;
        std::cout << "arrY[" << i << "] = " << arrY[i] << std::endl;
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (arrX[i] == arrY[j])
            {
                newArr(arrX[i]);
                break;
            }
        }
    }
    std::cout << std::endl;
    for (int i = 0; i < Size; ++i)
        std::cout
            << "arrZ[" << i << "] = " << arrZ[i] << std::endl;
}

#include <iostream>
#include <time.h>
#include <string>
constexpr int n = 3;
int* arrZ = new int[n];
int Size = 0;

void newArr(int x)
{
	int* arr = new int[Size + 1];
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
	int sum = 0;
	srand(time(NULL));

	for (int i = 0; i < n; ++i)
	{
		arrX[i] = rand() % 30;
		arrY[i] = rand() % 20;
		std::cout << "arrX[" << std::to_string(i) << "] = " << arrX[i] << std::endl;
		std::cout << "arrY[" << std::to_string(i) << "] = " << arrY[i] << std::endl;
	}

	for (int i = 0; i < n; ++i)
		sum += arrY[i];

	sum /= n;

	for (int i = 0; i < n; ++i)
		if (arrX[i] > sum)
			newArr(arrX[i]);

	for (int i = 0; i < Size; ++i)
		std::cout << "arrZ[" << std::to_string(i) << "] = " << arrZ[i] << std::endl;
}
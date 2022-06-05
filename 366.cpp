#include <iostream>
#include <math.h>
constexpr int n = 10;
int Size = 0;
int *resArr;

bool isPrime(int x)
{
	for (int i = 2; i < sqrt(x); ++i)
		if (x % 2 == 0)
			return 0;
	return 1;
}

void newArr(int x)
{
	if (x != 1 || x != 2)
	{
		int *arr = new int[Size + 1];
		for (int i = 0; i < Size; ++i)
			arr[i] = resArr[i];

		arr[Size] = x;
		++Size;
		delete resArr;
		resArr = arr;
	}
}

int main()
{
	int arr[n];
	int a, b;
	resArr = new int[n];

	for (int i = 0; i < n; ++i)
		std::cin >> arr[i];

	std::cout << "a = ";
	std::cin >> a;
	std::cout << "b = ";
	std::cin >> b;

	if (a > b)
	{
		a += b;
		b = a - b;
		a -= b;
	}

	for (int i = a; i <= b; ++i)
	{
		if (isPrime(arr[i]))
		{
			newArr(arr[i]);
		}
	}

	for (int i = 0; i < Size; ++i)
		std::cout << resArr[i] << " ";
}
// 366

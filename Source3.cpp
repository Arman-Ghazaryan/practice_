
#include <iostream>
#include <time.h>
constexpr int n = 3;
constexpr int m = 3;

int max(int arr[])
{
	int temp = 0;

	for (int i = 1; i < n; ++i)
		if (arr[i] > arr[temp])
			temp = i;
	return temp;
}

int min(int arr[])
{
	int temp = 0;

	for (int i = 1; i < n; ++i)
		if (arr[i] < arr[temp])
			temp = i;
	return temp;
}

int main()
{
	int arr[m][n];
	int temp, frst,scnd;
	srand(time(NULL));

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			arr[i][j] = rand() % 100;
			std::cout << arr[i][j] << " ";
		}
		std::cout << std::endl;
	}

	for (int i = 0; i < m; ++i)
	{
		frst = max(arr[i]);
		scnd = min(arr[i]);
		temp = arr[i][frst];
		arr[i][frst] = arr[i][scnd];
		arr[i][scnd] = temp;
	}

	std::cout << std::endl;

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			std::cout << arr[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
#include <iostream>
#include <time.h>
constexpr int m = 4;
constexpr int n = 3;

int main()
{
	int arr[m][n], resArr[m][n];
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
	for (int i = 0; i < m / 2; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			resArr[i][j] = arr[i + m / 2][j];
			resArr[i + m / 2][j] = arr[i][j];
		}
	}
	std::cout << std::endl;

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			std::cout << resArr[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
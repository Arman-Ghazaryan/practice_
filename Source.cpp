#include <iostream>
constexpr int n = 3;

int main()
{
	double arr[n];
	double sum = 0;

	for (int i = 0; i < n; ++i)
		std::cin >> arr[i];

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (1 / arr[i] == arr[j])
			{
				sum += arr[i];
				break;
			}
		}
	}
	std::cout << std::endl
			  << sum;
}
// 351
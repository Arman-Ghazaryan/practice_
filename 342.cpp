#include <iostream>

int main()
{

	int n;
	std::cout << "n = ";
	std::cin >> n;
	int arr[n];
	int sum, max;

	for (int i = 0; i < n; ++i)
		std::cin >> arr[i];

	max = 0;
	for (int i = 1; arr[i] > arr[max]; ++i)
		max = i;

	if (max < n / 2)
	{
		sum = 0;
		for (int i = 0; i < n; ++i)
			if (arr[i] > 0)
				sum += arr[i];
	}
	else
	{
		sum = 1;
		for (int i = 0; i < n; ++i)
			if (arr[i] < 0)
				sum *= arr[i];
	}
	std::cout << std::endl
			  << "sum = " << sum << std::endl
			  << std::endl;
}
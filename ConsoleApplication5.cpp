#include <iostream>
constexpr int n = 10;

int main()
{
	int arr[n];
	int sum = 1;

	for (int i = 0; i < n; ++i)
		std::cin >> arr[i];

	for (int i = 2; i < n; i += 2)
		sum *= arr[i];

	if (sum > 0)
	{
		sum = 0;
		for (int i = 1; i < n; i += 2)
			sum += arr[i];
		std::cout << sum;
	}
	else
	{
		sum = 1;
		std::cout << "sum = " << sum;
	}
}
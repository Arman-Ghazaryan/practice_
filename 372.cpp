#include <iostream>
#include <time.h>
constexpr int n = 10;

int main()
{
	srand(time(NULL));
	int arr[n];
	int cnt = 0, glbcnt = 0;

	for (int i = 0; i < n; ++i)
	{
		arr[i] = rand() % 10;
		std::cout << arr[i] << " ";
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
			++glbcnt;
	}
	std::cout << std::endl << glbcnt;
}
//372
#include <iostream>
#include <time.h>
#include <math.h>

int main()
{
	srand(time(NULL));
	int x, hun = 100;
	std::cout << "x = ";
	std::cin >> x;
	double arrY[hun];

	for (int i = 0; i < hun; ++i)
		arrY[i] = rand() % 30 + 4;

	for (int i = 0; i < hun; ++i)
	{
		std::cout << "y[" << i << "] = " << arrY[i] << " ";
		std::cout << " k = ";
		for (int k = 1; pow(arrY[i], k - 1) < x; ++k)
			if (x < pow(arrY[i], k))
				std::cout << k << " |";
		if (i % 7 == 0 && i != 0)
			std::cout << std::endl
					  << std::endl;
	}
	std::cout << std::endl
			  << std::endl;
}
//362
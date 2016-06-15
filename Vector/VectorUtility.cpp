#include "Vector.h"
#include <iostream>

double read_and_sum(int size)
{
	Vector v(size);
	double sum = 0;
	try
	{
		for (int i = 0; i != v.size(); ++i)
		{
			std::cin >> v[i];
		}

		for (int i = 0; i != v.size(); ++i)
		{
			sum += v[i];
		}
	}
	catch (std::out_of_range& e)
	{
		std::cout << e.what() << "\n";
		return 0;
	}

	return sum;
}

void print_vector(Vector& v)
{
	std::cout << "The vector [";
	for (int i = 0; i < v.size(); ++i)
	{
		std::cout << (i == 0 ? "" : ", ") << v[i];
	}
	std::cout << "]\n";
}
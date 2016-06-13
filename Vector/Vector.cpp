#include "Vector.h"
#include <iostream>

double read_and_sum(size_t size)
{
	Vector v(size);
	for (size_t i = 0; i != v.size(); ++i)
	{
		std::cin >> v[i];
	}

	double sum = 0;
	for (size_t i = 0; i != v.size(); ++i)
	{
		sum += v[i];
	}

	return sum;
}

Vector::Vector(size_t size)
	: m_elem { new double[ size ] }
	, m_size { size }
{}

double& Vector::operator[](size_t idx)
{
	return m_elem[ idx ];
}

size_t Vector::size()
{
	return m_size;
}
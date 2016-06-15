#include "Vector.h"
#include <iostream>

double read_and_sum(int size)
{
	Vector v(size);
	for (int i = 0; i != v.size(); ++i)
	{
		std::cin >> v[i];
	}

	double sum = 0;
	for (int i = 0; i != v.size(); ++i)
	{
		sum += v[i];
	}

	return sum;
}

Vector::Vector(int size)
	: m_elem { new double[ size ] }
	, m_size { size }
{}

double& Vector::operator[](int idx)
{
	return m_elem[ idx ];
}

int Vector::size() const
{
	return m_size;
}
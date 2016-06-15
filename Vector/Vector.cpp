#include "Vector.h"
#include <iostream>
#include <exception>

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

Vector::Vector(int size)
{
	if (size <= 0)
	{
		throw std::length_error { 
			"exception: invalid length (<=0) in Vector::Vector" 
		};
	}
	m_elem = new double[size];
	for (int i = 0; i < size; ++i)
	{
		m_elem[i] = 0;
	}
	m_size = size;
}

Vector::~Vector()
{
	delete[] m_elem;
}

double& Vector::operator[](int idx)
{
	if (idx < 0 || idx >= size())
	{
		throw std::out_of_range { 
			"exception: out of range (<0 or >=vector size)"
			" in Vector::operator[]" 
		};
	}
	return m_elem[ idx ];
}

int Vector::size() const
{
	return m_size;
}
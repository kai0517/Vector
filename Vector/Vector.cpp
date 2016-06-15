#include "Vector.h"
#include <iostream>
#include <exception>
#include <iterator>

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

Vector::Vector(int size)
	: m_pos{ 0 }
{
	if (size < 0)
	{
		throw std::length_error { 
			"exception: invalid length (<0) in Vector::Vector" 
		};
	}
	m_elem = new double[size];
	for (int i = 0; i < size; ++i)
	{
		m_elem[i] = 0;
	}
	m_size = size;
}

Vector::Vector(std::initializer_list<double> lst)
	: m_elem{ new double[lst.size()] }
	, m_size{ static_cast< int >( lst.size() ) }
	, m_pos{ 0 }
{
	stdext::checked_array_iterator< double* > checked
		{ m_elem, static_cast< size_t >( m_size ) };
	std::copy(lst.begin(), lst.end(), checked);
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

void Vector::push_back(double val)
{
	// Add simplified version of push_back
	// If the vector is full, then the function
	// simply returns without any error prompt.
	if (m_pos < size())
	{
		m_elem[m_pos++] = val;
	}
}
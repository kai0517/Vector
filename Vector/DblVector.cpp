#include "DblVector.h"
#include <exception>
#include <iterator>

DblVector::DblVector(int size)
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

DblVector::DblVector(std::initializer_list<double> lst)
	: m_elem{ new double[lst.size()] }
	, m_size{ static_cast< int >( lst.size() ) }
	, m_pos{ 0 }
{
#if defined(_MSC_VER)    
	stdext::checked_array_iterator< double* > checked
		{ m_elem, static_cast< size_t >( m_size ) };
	std::copy(lst.begin(), lst.end(), checked);
#else
    std::copy(lst.begin(), lst.end(), m_elem);
#endif
}

DblVector::~DblVector()
{
	delete[] m_elem;
}

DblVector::DblVector(DblVector const& v)
	: m_elem{ new double[v.m_size] }
	, m_size{ v.m_size }
{
	for (int i = 0; i < m_size; ++i)
	{
		m_elem[i] = v.m_elem[i];
	}
}

DblVector& DblVector::operator=(DblVector const& v)
{
	double* p = new double[v.m_size];
	for (int i = 0; i < v.m_size; ++i)
	{
		p[i] = v.m_elem[i];
	}
	delete[] m_elem;
	m_elem = p;
	m_size = v.m_size;
	return *this;
}

DblVector::DblVector(DblVector&& v)
	: m_elem{ v.m_elem }
	, m_size{ v.m_size }
{
	m_elem = nullptr;
	m_size = 0;
}

DblVector& DblVector::operator=(DblVector&& v)
{
	m_elem = v.m_elem;
	m_size = v.m_size;
	v.m_elem = nullptr;
	v.m_size = 0;
	return *this;
}

double const& DblVector::operator[](int idx) const
{
	if (idx < 0 || idx >= size())
	{
		throw std::out_of_range{
			"exception: out of range (<0 or >=vector size)"
			" in Vector::operator[]"
		};
	}
	return m_elem[ idx ];
}

double& DblVector::operator[](int idx)
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

int DblVector::size() const
{
	return m_size;
}

void DblVector::push_back(double val)
{
	// Add simplified version of push_back
	// If the vector is full, then the function
	// simply returns without any error prompt.
	if (m_pos < size())
	{
		m_elem[m_pos++] = val;
	}
}

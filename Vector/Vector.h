#pragma once

class Vector
{
public:
	Vector(size_t size);

	double& operator[](size_t idx);
	size_t  size();

private:
	double* m_elem;
	size_t  m_size;
};

double read_and_sum(size_t size);
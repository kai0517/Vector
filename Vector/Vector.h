#pragma once

class Vector
{
public:
	Vector(int size);

	double& operator[](int idx);
	int size() const;

private:
	double* m_elem;
	int     m_size;
};

double read_and_sum(int size);
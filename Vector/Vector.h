#pragma once
#include <initializer_list>

class Vector
{
public:
	Vector(int size);
	Vector(std::initializer_list<double> lst);
	~Vector();

	Vector(Vector const& v);
	Vector& operator=(Vector const& v);

	Vector(Vector&& v);
	Vector& operator=(Vector&& v);

	double& operator[](int idx);
	double const& operator[](int idx) const;
	int size() const;
	void push_back(double val);

private:
	double* m_elem;
	int     m_size;
	int     m_pos;
};

double read_and_sum(int size);
void print_vector(Vector& v);
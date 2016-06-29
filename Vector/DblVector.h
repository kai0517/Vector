#pragma once
#include <initializer_list>

class DblVector
{
public:
	DblVector(int size);
	DblVector(std::initializer_list<double> lst);
	~DblVector();

	DblVector(DblVector const& v);
	DblVector& operator=(DblVector const& v);

	DblVector(DblVector&& v);
	DblVector& operator=(DblVector&& v);

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
void print_vector(DblVector& v);
#pragma once
#include <initializer_list>

template <typename T>
class Vector
{
public:
	Vector(int size);
	Vector(std::initializer_list lst);
	~Vector();

	Vector(Vector const& v);
	Vector& operator=(Vector const& v);

	Vector(Vector&& v);
	Vector& operator=(Vector&& v);

	T& operator[](int idx);
	T const& operator[](int idx) const;
	int size() const;

private:
	T*  m_elem;
	int m_size;
};

template <typename T>
void print_vector(Vector<T> const& v);

template <typename T>
T* begin(Vector<T>& v);

template <typename T>
T* end(Vector<T>& v);

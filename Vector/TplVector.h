#pragma once
#include <initializer_list>
#include <exception>

template <typename T>
class Vector
{
public:
    using value_type = T;

	Vector(int size);
	Vector(std::initializer_list<T> lst);
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
Vector<T>::Vector(int size)
{
    if (size<0)
    {
		throw std::length_error { 
			"exception: invalid length (<0) in Vector::Vector" 
        };
    }

    m_elem = new T[size];
    m_size = size;
}

template <typename T>
Vector<T>::Vector(std::initializer_list<T> lst)
    : m_elem{ new T[lst.size()] }
    , m_size{ static_cast<int>(lst.size()) }
{
#if defined(_MSC_VER)    
	stdext::checked_array_iterator< T* > checked
		{ m_elem, static_cast< size_t >( m_size ) };
	std::copy(lst.begin(), lst.end(), checked);
#else
    std::copy(lst.begin(), lst.end(), m_elem);
#endif
}

template <typename T>
Vector<T>::~Vector()
{
    delete[] m_elem;
}

template <typename T>
Vector<T>::Vector(Vector<T> const& v)
    : m_elem{ new T[v.m_size] }
    , m_size{ v.m_size }
{
    for (int i=0; i<v.m_size; ++i)
    {
        m_elem[i] = v.m_elem[i];
    }
}

template <typename T>
Vector<T>& Vector<T>::operator=(Vector<T> const& v)
{
    T* ptr = new T[v.m_size];
    for (int i=0; i<v.m_size; ++i)
    {
        ptr[i] = v.m_elem[i];
    }

    delete[] m_elem;
    m_elem = ptr;
    m_size = v.m_size;
    
    return *this;
}

template <typename T>
Vector<T>::Vector(Vector<T>&& v)
    : m_elem(v.m_elem)
    , m_size(v.m_size)
{
    v.m_elem = nullptr;
    v.m_size = 0;
}

template <typename T>
Vector<T>& Vector<T>::operator=(Vector<T>&& v)
{
    m_elem = v.m_elem;
    m_size = v.m_size;
    
    v.m_elem = nullptr;
    v.m_size = 0;

    return *this;
}

template <typename T>
T& Vector<T>::operator[](int idx)
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

template <typename T>
T const& Vector<T>::operator[](int idx) const
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

template <typename T>
int Vector<T>::size() const
{
    return m_size;
}

template <typename T>
void print_vector(Vector<T> const& v)
{
    std::cout << "The value of the vector is \n";
    for (auto const& elem : v)
    {
        std::cout << elem << " ";
    }
    std::cout << "\n";
}

template <typename Cntr, typename Pred>
int count(Cntr const& cntr, Pred pred)
{
    int count = 0;
    for (auto const& elem : cntr)
    {
        if (pred(elem))
        {
            ++count;
        }
    }
    return count;
}

template <typename T>
T const* begin(Vector<T> const& v)
{
    return &v[0];
}

template <typename T>
T const* end(Vector<T> const& v)
{
    return begin(v)+v.size();
}

template <typename T>
class Less_than
{
public:
    Less_than(T const& val)
        : m_val(val)
    {}

    bool operator()(T const& val)
    {
        return val < m_val;
    }

private:
    T const m_val;
};

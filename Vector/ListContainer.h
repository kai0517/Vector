#pragma once
#include "Container.h"
#include <list>

class List_container : public Container
{
public:
	List_container() {}
	List_container(std::initializer_list<double> il) : m_ld(il) {}
	~List_container() {}

	double& operator[](int i);
	int size() const { return static_cast<int>(m_ld.size()); }

private: 
	std::list<double> m_ld;
};
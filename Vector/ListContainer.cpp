#include "ListContainer.h"

double& List_container::operator[](int i)
{
	for (auto& x : m_ld)
	{
		if (i == 0) return x;
		--i;
	}
	throw std::out_of_range("List_container::operator[]");
}
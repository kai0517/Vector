#pragma once
#include "Container.h"
#include "DblVector.h"

class Vector_container : public Container
{
public:
    Vector_container(int s) : m_vec(s) {}
    Vector_container(std::initializer_list<double> il) : m_vec(il) {}
    ~Vector_container() {}

    double& operator[](int i) { return m_vec[i]; }
    int size() const { return m_vec.size(); }

private:
    DblVector m_vec;
};

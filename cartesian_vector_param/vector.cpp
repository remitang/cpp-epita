#include <ostream>
#include <iostream>

#include <initializer_list>

#include "vector.h"

Vector::Vector()
{
    n = NDIM;
    for (size_t i = 0; i < n; i++)
        data[i] = 0;
}

Vector::Vector(std::initializer_list<value> l)
{
    n = l.size();
    int i = 0;
    for (auto & val : l)
        data[i++] = val;
}

size_t Vector::getDim() const
{
    return n;
}

Vector& Vector::operator+=(const Vector& rhs)
{
    for (int i = 0; i < rhs.getDim(); i++)
        data[i] += rhs[i];
    return *this;
}

Vector& Vector::operator-=(const Vector& rhs)
{
    for (int i = 0; i < rhs.getDim(); i++)
        data[i] -= rhs[i];
    return *this;
}

Vector Vector::operator+(const Vector& rhs)
{
    auto v = Vector();
    for (int i = 0; i < rhs.getDim(); i++)
        v[i] = rhs[i] + (*this)[i];
    return v;
}

Vector Vector::operator-(const Vector& rhs)
{
    auto v = Vector();
    for (int i = 0; i < rhs.getDim(); i++)
        v[i] = rhs[i] - (*this)[i];
    return v;
}

value Vector::operator*(const Vector& rhs)
{
    value v = 0;
    for (int i = 0; i < rhs.getDim(); i++)
        v += rhs[i] * (*this)[i];
    return v;
}

value Vector::operator[](size_t i) const
{
    return data[i];
}

value& Vector::operator[](size_t i)
{
    return data[i];
}

Vector operator*(Vector& rhs, const value val)
{
    auto v = Vector();
    for (int i = 0; i < rhs.getDim(); i++)
        v[i] = rhs[i] * val;
    return v;
}

Vector operator*=(Vector& rhs, const value a)
{
    for (int i = 0; i < rhs.getDim(); i++)
        rhs[i] *= a;
    return rhs;
}

Vector operator+=(Vector& rhs, const value a)
{
    for (int i = 0; i < rhs.getDim(); i++)
        rhs[i] += a;
    return rhs;
}

std::ostream& operator<<(std::ostream &os, const Vector& rhs)
{
    os << "{";
    for (int i = 0; i < rhs.getDim(); i++)
        os << rhs[i] << (i == rhs.getDim() - 1 ? "" : ",");
    return os << "}";
}

#pragma once

#include <ostream>
#include <initializer_list>
#include <cassert>

#include "config.h"

class Vector
{
public:
// DO NOT CHANGE THIS
    Vector(const Vector&) = default;
    Vector& operator=(const Vector&) = default;
    ~Vector() = default;
//

// Add suitable constructors
    Vector();
    Vector(std::initializer_list<value> l);
    // possibly more

// Public Member functions here
    Vector& operator+=(const Vector& rhs);
    Vector& operator-=(const Vector& rhs);
    Vector operator+(const Vector& rhs);
    value operator*(const Vector& rhs);
    Vector operator-(const Vector& rhs);
    value& operator[](size_t i);
    value operator[](size_t i) const;
    size_t getDim() const;
    // More to go

private:
// Private Member functions here (if necessary)
    value data[NDIM];
    size_t n;
// Member variables are ALWAYS private, and they go here

};

// Nonmember function operators go here
Vector operator*(Vector& rhs, const value a);
Vector operator+=(Vector& rhs, const value a);
Vector operator*=(Vector& rhs, const value a);
std::ostream& operator<<(std::ostream& os, const Vector& rhs);

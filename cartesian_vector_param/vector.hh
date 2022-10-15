#pragma once

#include <ostream>
#include <initializer_list>

#include "config.h"

class Vector
{
public:
    // DO NOT CHANGE THIS
    Vector(const Vector &) = default;
    Vector &operator=(const Vector &) = default;
    ~Vector() = default;
    //

    Vector();
    Vector(std::initializer_list<value>);

    Vector &operator+=(const Vector &rhs);
    Vector &operator-=(const Vector &rhs);

    Vector &operator+=(const value &rhs);
    Vector &operator*=(const value &rhs);

    value &operator[](size_t i);
    value operator[](size_t i) const;

private:
    value data[NDIM];
};

std::ostream &operator<<(std::ostream &os, const Vector &rhs);
Vector operator+(const Vector &rhs1, const Vector &rhs2);
Vector operator*(const Vector &rhs, const value &value);
Vector operator*(const value &value, const Vector &rhs);
value operator*(const Vector &rhs1, const Vector &rhs2);
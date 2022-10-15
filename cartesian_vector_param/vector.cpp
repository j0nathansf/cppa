#include "vector.hh"

Vector::Vector()
{
    for (size_t i = 0; i < NDIM; i++)
        data[i] = 0;
}

Vector::Vector(std::initializer_list<value> values)
{
    size_t i = 0;
    for (const value &value : values)
        data[i++] = value;
}

Vector &Vector::operator+=(const Vector &rhs)
{
    for (size_t i = 0; i < NDIM; i++)
        data[i] += rhs[i];
    return *this;
}

Vector &Vector::operator-=(const Vector &rhs)
{
    for (size_t i = 0; i < NDIM; i++)
        data[i] -= rhs[i];
    return *this;
}

Vector &Vector::operator+=(const value &rhs)
{
    for (size_t i = 0; i < NDIM; i++)
        data[i] += rhs;
    return *this;
}

Vector &Vector::operator*=(const value &rhs)
{
    for (size_t i = 0; i < NDIM; i++)
        data[i] *= rhs;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Vector &rhs)
{
    os << '{';
    for (size_t i = 0; i < NDIM; i++)
    {
        os << rhs[i];
        if (i != NDIM - 1)
            os << ',';
    }
    return os << '}';
}

Vector operator+(const Vector &rhs1, const Vector &rhs2)
{
    Vector tmp;
    for (size_t i = 0; i < NDIM; i++)
        tmp[i] = rhs1[i] + rhs2[i];
    return tmp;
}

Vector operator*(const Vector &rhs, const value &value)
{
    Vector tmp;
    for (size_t i = 0; i < NDIM; i++)
        tmp[i] = rhs[i] * value;
    return tmp;
}

Vector operator*(const value &value, const Vector &rhs)
{
    return value * rhs;
}

value operator*(const Vector &rhs1, const Vector &rhs2)
{
    value tmp = 0;
    for (size_t i = 0; i < NDIM; i++)
        tmp += rhs1[i] * rhs2[i];
    return tmp;
}

value Vector::operator[](size_t i) const
{
    return data[i];
}

value &Vector::operator[](size_t i)
{
    return data[i];
}
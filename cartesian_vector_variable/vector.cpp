#include "vector.hh"

Vector::Vector(const Vector &rhs)
{
    NDIM = rhs.NDIM;
    data = std::make_unique<value[]>(rhs.size());
    for (size_t i = 0; i < rhs.size(); i++)
        data[i] = rhs[i];
}

Vector::Vector(size_t N)
{
    NDIM = N;
    data = std::make_unique<value[]>(N);
    for (size_t i = 0; i < N; i++)
        data[i] = 0;
}

Vector::Vector(std::initializer_list<value> l)
{
    NDIM = l.size();
    data = std::make_unique<value[]>(l.size());
    size_t i = 0;
    for (const value value : l)
    {
        data[i] = value;
        i += 1;
    }
}

size_t Vector::size() const
{
    return this->NDIM;
}

Vector &Vector::operator=(const Vector &rhs)
{
    NDIM = rhs.size();
    for (size_t i = 0; i < rhs.size(); i++)
        data[i] = rhs[i];
    return *this;
}

Vector &Vector::operator+=(const Vector &rhs)
{
    if (rhs.size() != NDIM)
        throw std::runtime_error("Incompatible size");
    for (size_t i = 0; i < rhs.size(); i++)
        data[i] += rhs[i];
    return *this;
}

Vector &Vector::operator-=(const Vector &rhs)
{
    if (rhs.size() != NDIM)
        throw std::runtime_error("Incompatible size");
    for (size_t i = 0; i < rhs.size(); i++)
        data[i] -= rhs[i];
    return *this;
}

Vector &Vector::operator+=(const value v)
{
    for (size_t i = 0; i < NDIM; i++)
        data[i] += v;
    return *this;
}

Vector &Vector::operator*=(const value v)
{
    for (size_t i = 0; i < NDIM; i++)
        data[i] *= v;
    return *this;
}

Vector Vector::operator+(const Vector &rhs) const
{
    if (rhs.size() != NDIM)
        throw std::runtime_error("Incompatible size");
    Vector *tmp = new Vector(rhs.size());
    for (size_t i = 0; i < rhs.size(); i++)
        tmp->data[i] = data[i] + rhs[i];
    return *tmp;
}

Vector Vector::operator+(value v) const
{
    Vector *tmp = new Vector(NDIM);
    for (size_t i = 0; i < NDIM; i++)
        tmp->data[i] = data[i] + v;
    return *tmp;
}

value Vector::operator*(const Vector &rhs) const
{
    if (rhs.size() != NDIM)
        throw std::runtime_error("Incompatible size");
    value tmp = 0;
    for (size_t i = 0; i < rhs.size(); i++)
        tmp += rhs[i] * data[i];
    return tmp;
}

Vector Vector::operator*(value v) const
{
    Vector *tmp = new Vector(NDIM);
    for (size_t i = 0; i < NDIM; i++)
        tmp->data[i] = data[i] * v;
    return *tmp;
}

value &Vector::operator[](size_t idx)
{
    return data[idx];
}

value Vector::operator[](size_t idx) const
{
    return data[idx];
}

Vector operator*(const value &s, const Vector &v)
{
    Vector *tmp = new Vector(v.size());
    for (size_t i = 0; i < v.size(); i++)
        tmp[i] = s * v[i];
    return *tmp;
}

Vector operator+(const value &s, const Vector &v)
{
    Vector *tmp = new Vector(v.size());
    for (size_t i = 0; i < v.size(); i++)
        tmp[i] = s + v[i];
    return *tmp;
}

std::ostream &operator<<(std::ostream &o, const Vector &v)
{
    o << '{';
    for (size_t i = 0; i < v.size(); i++)
    {
        o << v[i];
        if (i != v.size() - 1)
            o << ',';
    }
    return o << '}';
}
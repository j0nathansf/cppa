#include <set>

template<class T>
std::set<T> operator+(std::set<T> s, std::set<T> t)
{
    std::set<T> tmp = s;
    for (const auto& e : t)
        tmp.insert(e);
    return tmp;
}

template<class T>
std::set<T> operator-(std::set<T> s, std::set<T> t)
{
    std::set<T> tmp = s;
    for (const auto& e : t)
    {
        if (tmp.find(e) != tmp.end()) {
            tmp.erase(e);
        }
    }
    return tmp;
}

template<class T>
std::set<T> operator^(std::set<T> s, std::set<T> t)
{
    std::set<T> tmp = s;
    for (const auto& e : t)
    {
        if (tmp.find(e) != tmp.end()) {
            tmp.erase(e);
        } else {
            tmp.insert(e);
        }
    }
    return tmp;
}

template<class T>
std::set<T> operator*(std::set<T> s, std::set<T> t)
{
    std::set<T> tmp = {};
    for (const auto& e1 : s)
    {
        for (const auto& e2 : t)
        {
            tmp.insert(e1 + e2);
        }   
    }
    return tmp;
}

template<class T>
std::set<T> operator^(std::set<T> s, int n)
{
    std::set<T> tmp = s;

    if (n < 0)
    {
        throw std::invalid_argument("n cannot be negative");
    }
    else if (n == 0)
    {
        if (std::is_integral<int>::value) {
            std::cout << "int" << std::endl;
        }
    }
    else 
    {
        for (int i = 0; i < n - 1; i++)
        {
            tmp = tmp * s;
        }
    }
    return tmp;
}
#include <iostream>
#include <stdlib.h>

std::string check_prime(long nb)
{
    if (nb <= 1)
    {
        return "False";
    }
    for (int i = 2; i <= nb / 2; i++)
    {
        if (nb %i != 0)
        {
            continue;
        }
        else
        {
            return "False";
        }
    }
    return "True";
}

int main(void)
{
    long params;
    while (std::cin >> params)
    {
        std::cout << params << " is a prime: " << check_prime(params) << "\n";
    }
    return 0;
}

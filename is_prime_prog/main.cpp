#include <iostream>
#include <stdlib.h>

std::string check_prime(int nb) {
    for (int i = 2; i <= nb / 2; i++) {
        if (nb %i != 0)
        {
            continue;
        } else {
            return "False";
        }
    }
    return "True";
}

int main(int argc, char** argv) {
    for (int i = 1; i < argc; i++)
    {
        std::cout << argv[i] << " is a prime: " << check_prime(atoi(argv[i])) << "\n";
    }
    return 0;
}

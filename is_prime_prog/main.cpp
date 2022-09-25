#include <cmath>
#include <iostream>

int main()
{
    int i, n;

    while (std::cin >> n)
    {
        bool is_prime = true;

        if (n <= 1)
        {
            is_prime = false;
        }

        for (i = 2; i <= std::sqrt(n); ++i)
        {
            if (n % i == 0)
            {
                is_prime = false;
                break;
            }
        }

        if (is_prime)
            std::cout << n << " is a prime: True\n";
        else
            std::cout << n << " is a prime: False\n";
    }
    return 0;
}

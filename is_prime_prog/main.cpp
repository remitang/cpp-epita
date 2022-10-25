#include <cmath>
#include <iostream>

int main()
{
    long long i, n;

    while (std::cin >> n)
    {
        bool is_prime = true;

        if (n <= 1)
            is_prime = false;
        if (n == 2 || n == 3)
            is_prime = true;
        if (n % 2 == 0 || n % 3 == 0)
            is_prime = false;
        for (i = 5; i * i <= n; i = i + 6)
        {
            if (n % i == 0 || n % (i + 2) == 0)
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

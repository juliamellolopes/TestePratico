#include <iostream>

bool isPerfectSquare(int x)
{
    int s = sqrt(x);
    return (s * s == x);
}

bool isFibonacci(int n)
{
    return isPerfectSquare(5 * n * n + 4) || isPerfectSquare(5 * n * n - 4);
}

int main()
{
    int number;
    std::cout << "Digite um número: ";
    std::cin >> number;

    if (isFibonacci(number))
        std::cout << number << " pertence à sequência de Fibonacci.\n";
    else
        std::cout << number << " não pertence à sequência de Fibonacci.\n";

    return 0;
}

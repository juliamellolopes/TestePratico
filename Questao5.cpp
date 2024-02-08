#include <iostream>

void reverseString(std::string &str)
{
    int length = str.length();
    for (int i = 0; i < length / 2; i++)
    {
        std::swap(str[i], str[length - i - 1]);
    }
}

int main()
{
    std::string inputString;
    std::cout << "Digite uma string: ";
    std::cin >> inputString;

    reverseString(inputString);

    std::cout << "String invertida: " << inputString << std::endl;

    return 0;
}

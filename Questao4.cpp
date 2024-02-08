#include <iostream>
#include <map>

int main()
{
    std::map<std::string, double> monthlySales = {
        {"SP", 67836.43},
        {"RJ", 36678.66},
        {"MG", 29229.88},
        {"ES", 27165.48},
        {"Outros", 19849.53}};

    double totalSales = 0.0;
    for (const auto &entry : monthlySales)
    {
        totalSales += entry.second;
    }

    std::cout << "Percentual de representação de cada estado:\n";
    for (const auto &entry : monthlySales)
    {
        double percentual = (entry.second / totalSales) * 100.0;
        std::cout << entry.first << " - " << percentual << "%\n";
    }

    return 0;
}

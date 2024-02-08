#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "json.hpp"

using json = nlohmann::json;

struct DailySales
{
    int day;
    double value;
};

int main()
{
    std::ifstream file("dados.json");
    json jsonData;
    file >> jsonData;

    std::vector<DailySales> dailySales;

    for (const auto &item : jsonData)
    {
        DailySales sales;
        sales.day = item["dia"];
        sales.value = item["valor"];
        dailySales.push_back(sales);
    }

    double minSales = std::numeric_limits<double>::max();
    double maxSales = 0.0;
    double totalSales = 0.0;

    int daysAboveAverage = 0;

    for (const auto &sales : dailySales)
    {
        totalSales += sales.value;

        if (sales.value < minSales)
        {
            minSales = sales.value;
        }

        if (sales.value > maxSales)
        {
            maxSales = sales.value;
        }
    }

    double averageSales = totalSales / dailySales.size();

    for (const auto &sales : dailySales)
    {
        if (sales.value > averageSales)
        {
            daysAboveAverage++;
        }
    }

    std::cout << "Menor valor de faturamento: " << minSales << std::endl;
    std::cout << "Maior valor de faturamento: " << maxSales << std::endl;
    std::cout << "Número de dias com faturamento acima da média: " << daysAboveAverage << std::endl;

    return 0;
}

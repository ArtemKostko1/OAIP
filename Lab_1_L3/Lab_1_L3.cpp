#include <iostream>
#include <cmath>

double calculateExpression(double x, double y, double z)
{
    if (x == 0 || y == 0 || z == 0)
    {
        throw std::runtime_error("Делить на ноль нельзя!");
    }

    double absoluteDifference = std::abs(y - x);
    double tangentZ = std::tan(z);

    double numerator = (std::pow(x, y) + 1) + (std::exp(y) - 1);
    double denominator = 1 + x * std::abs(y - tangentZ * z);
    double fraction1 = numerator / denominator;

    double fraction2 = 1 + absoluteDifference;
    double fraction3 = std::pow(absoluteDifference, 2) / 2;
    double fraction4 = std::pow(absoluteDifference, 3) / 3;

    double h = (fraction1 * fraction2) + fraction3 - fraction4;

    return h;
}

int main()
{
    setlocale(LC_ALL, "en_US.UTF-8");

    double x = 2.444;
    double y = 0.869e-2;
    double z = -0.13e-3;

    try
    {
        double result = calculateExpression(x, y, z);
        std::wcout << L"Результат: " << result << std::endl;
    }
    catch (const std::exception& ex)
    {
        std::wcout << L"Произошла ошибка: " << ex.what() << std::endl;
    }

    return 0;
}
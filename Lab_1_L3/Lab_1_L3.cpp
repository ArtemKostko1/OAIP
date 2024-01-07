#include <iostream>
#include <sstream>
#include <cmath>
#include <stdexcept>
#include <limits>
#include <string>
#include <locale>

double inputNumber() {
    double value;

    std::string input;
    while (true) {
        std::getline(std::cin, input); // Считывание всей строки ввода и сохранение ее в переменной input
        std::stringstream ss(input); // Создание объекта std::stringstream с именем ss. std::stringstream нужен для преобразования строк в числа и наоборот.

        if (ss >> value && ss.eof()) {  // Преобразование строки input в число
            break;
        }

        std::wcout << L"Недопустимый ввод! Пожалуйста, введите число: ";
    }

    return value;
}

double getResult(double x, double y, double z) {
    if (z == 0 || (1 + x * y) - tan(z) == 0 || y - x == 0) // Проверка исключительных ситуаций
        throw std::invalid_argument("Недопустимые аргументы: деление на ноль или другое неопределенное поведение.");

    double part1 = (pow(x, y + 1) + exp(y - 1)) / (1 + x * abs(y - tan(z)));
    double part2 = 1 + abs(y - x);
    double part3 = pow(abs(y - x), 2) / 2 - pow(abs(y - x), 3) / 3;

    return part1 * part2 + part3;
}

int main()
{
    setlocale(LC_ALL, "ru_RU.UTF-8"); //Символы русского алфавита в консоли

    double x, y, z;

    std::wcout << L"Введите значение для x: ";
    x = inputNumber();

    std::wcout << L"Введите значение для y: ";
    y = inputNumber();

    std::wcout << L"Введите значение для z: ";
    z = inputNumber();

    try {
        double h = getResult(x, y, z);
        std::wcout << L"Результат значения h равно: " << h;
    }
    catch (const std::invalid_argument& e) {
        std::wcerr << e.what();
    }

    return 0;
}
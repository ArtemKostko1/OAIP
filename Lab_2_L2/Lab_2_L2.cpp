#include <iostream>
#include <sstream>
#include <clocale>
#include <cmath>
#include <stdexcept>
#include <limits>
#include <string>
#include <windows.h>

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

double getChoice(double x, int choice) {
    switch (choice) {
    case 1:
        return 2 * x;
    case 2:
        return pow(x, 2);
    case 3:
        return x / 3;
    default:
        std::wcout << L"Ошибка: неверный выбор.";
    }
}

double getResult(double z, double a, double d, int choice) {
    double x, y;

    if (z >= 0) {
        x = -3 * z;
        std::wcout << L"Так как z >= 0, используемая функция: x = -3z\n";
    }
    else {
        x = pow(z, 2);
        std::wcout << L"Так как z < 0, используемая функция: x = z^2\n";
    }

    if (x == 0) throw std::invalid_argument("Ошибка: деление на ноль недопустимо.");

    y = 2 * getChoice(x, choice) * (a * sin(x) + d * exp(-x - 3));

    if (y == INFINITY || y == -INFINITY || isnan(y))
        throw std::overflow_error("Ошибка: результат выходит за пределы допустимых значений.");

    return y;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian"); //Символы русского алфавита в консоли

    std::wcout << L"Введите значение z: ";
    double z = inputNumber();

    std::wcout << L"Введите значение a: ";
    double a = inputNumber();

    std::wcout << L"Введите значение d: ";
    double d = inputNumber();
    
    int choice;
    std::wcout << L"Выберите функцию для вычисления y:\n1. f(x) = 2x\n2. f(x) = x^2\n3. f(x) = x/3\nВаш выбор: ";
    std::wcin >> choice;

    try {
        double y = getResult(z, a, d, choice);
        std::wcout << L"Результат значения y равно: " << y;
    }
    catch (const std::invalid_argument& e) {
        std::wcerr << e.what();
    }

    return 0;
}

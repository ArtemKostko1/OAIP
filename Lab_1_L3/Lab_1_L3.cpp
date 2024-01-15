#include <iostream>
#include <sstream>
#include <cmath>
#include <stdexcept>
#include <limits>
#include <string>
#include <locale>
#include <windows.h>

using namespace std;

double inputNumber() {
    double value;

    string input;
    while (true) {
        getline(cin, input); // Считывание всей строки ввода и сохранение ее в переменной input
        stringstream ss(input); // Создание объекта std::stringstream с именем ss. std::stringstream нужен для преобразования строк в числа и наоборот.

        if (ss >> value && ss.eof()) {  // Преобразование строки input в число
            break;
        }

        cout << "Недопустимый ввод! Пожалуйста, введите число: ";
    }

    return value;
}

double getResult(double x, double y, double z) {
    if (z == 0 || (1 + x * abs(y - tan(z))) == 0 || y - x == 0) // Проверка исключительных ситуаций
        throw "Недопустимые аргументы: деление на ноль или другое неопределенное поведение.";

    double part1 = (pow(x, y + 1) + exp(y - 1)) / (1 + x * abs(y - tan(z)));
    double part2 = 1 + abs(y - x);
    double part3 = pow(abs(y - x), 2) / 2 - pow(abs(y - x), 3) / 3;

    return part1 * part2 + part3;
}

int main()
{
    setlocale(LC_ALL, "ru_RU"); //Символы русского алфавита в консоли

    double x, y, z;

    cout << "Введите значение для x: ";
    x = inputNumber();

    cout << "Введите значение для y: ";
    y = inputNumber();

    cout << "Введите значение для z: ";
    z = inputNumber();

    try {
        double h = getResult(x, y, z);
        cout << "Результат значения h равно: " << h;
    }
    catch (const char* error) {
        cout << error << endl;
    }

    return 0;
}
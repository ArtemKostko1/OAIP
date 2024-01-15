#include <iostream>
#include <sstream>
#include <clocale>
#include <cmath>
#include <stdexcept>
#include <limits>
#include <string>
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

double getChoice(double x, int choice) {
    switch (choice) {
    case 1:
        return 2 * x;
    case 2:
        return pow(x, 2);
    case 3:
        return x / 3;
    default:
        cout << "Ошибка: неверный выбор.";
    }
}

double getResult(double z, double a, double d, int choice) {
    double x, y;

    if (z >= 0) {
        x = -3 * z;
        cout << "Так как z >= 0, используемая функция: x = -3z\n";
    }
    else {
        x = pow(z, 2);
        cout << "Так как z < 0, используемая функция: x = z^2\n";
    }

    if (x == 0) throw "Ошибка: деление на ноль недопустимо.";

    y = 2 * getChoice(x, choice) * (a * sin(x) + d * exp(-x - 3));

    if (y == INFINITY || y == -INFINITY || isnan(y))
        throw "Ошибка: результат выходит за пределы допустимых значений.";

    return y;
}

int main()
{
    setlocale(LC_ALL, "ru_RU"); //Символы русского алфавита в консоли

    cout << "Введите значение z: ";
    double z = inputNumber();

    cout << "Введите значение a: ";
    double a = inputNumber();

    cout << "Введите значение d: ";
    double d = inputNumber();
    
    int choice;
    cout << "Выберите функцию для вычисления y:\n1. f(x) = 2x\n2. f(x) = x^2\n3. f(x) = x/3\nВаш выбор: ";
    cin >> choice;

    try {
        double y = getResult(z, a, d, choice);
        cout << "Результат значения y равно: " << y;
    }
    catch (const char* error) {
        cout << error << endl;
    }

    return 0;
}

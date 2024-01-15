﻿#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

double inputNumber() {
    double value;

    string input;
    while (true) {
        getline(cin, input); // Считывание всей строки ввода и сохранение ее в переменной input
        stringstream ss(input); // Создание объекта stringstream с именем ss. stringstream нужен для преобразования строк в числа и наоборот

        if (ss >> value && ss.eof()) {  // Преобразование строки input в число
            break;
        }

        cout << "Недопустимый ввод! Пожалуйста, введите число: ";
    }

    return value;
}

double getResultY(double x) {
    return log(sqrt(1 + pow(x, 2)) + x * atan(x));
}

double getResultS(double x, double e, int& n) { // Ссылка на переменную n
    double sum = 0;
    double term = x;
    n = 1;
    while (fabs(term) >= e) { // Цикл выполняется, пока абсолютное значение текущего члена ряда больше или равно заданной погрешности e
        sum += term; // Добавление текущего члена ряда к сумме
        ++n;
        term *= -x * x / (2 * n * (2 * n - 1)); // Вычисление следующего члена ряда
    }
    return sum;
}

int main()
{
    setlocale(LC_ALL, "ru_RU"); //Символы русского алфавита в консоли

    cout << "Введите значения для a: ";
    double a = inputNumber();

    double b;
    do {
        cout << "Введите значение для b (должно быть больше, чем a): ";
        b = inputNumber();
        if (b <= a) {
            cout << "Некорректный ввод. Значение b должно быть больше, чем a. Пожалуйста, попробуйте еще раз.\n";
        }
    } while (b <= a);

    cout << "Введите значения для h: ";
    double h = inputNumber();

    cout << "Введите значение для e: ";
    double e = inputNumber();

    cout << fixed << setprecision(4); // Вывод 4 знаков после запятой

    cout << left << setw(15) << "x"
        << setw(15) << "Y(x)"
        << setw(15) << "S(x)"
        << setw(15) << "|Y-S|"
        << "Кол-во шагов n\n";

    for (double x = a; x <= b; x += h) {
        int n;
        double y = getResultY(x);
        double s = getResultS(x, e, n);
        double diff = fabs(y - s);

        cout << left << setw(15) << x
            << setw(15) << y
            << setw(15) << s
            << setw(15) << diff
            << n
            << "\n";
    }

    return 0;
}
#include <iostream>
#include <sstream>
#include <clocale>
#include <cmath>
#include <stdexcept>
#include <limits>
#include <string>
#include <windows.h>
#include <iomanip>

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

double getResultY(double x) {
    return log(sqrt(1 + pow(x, 2)) + x * atan(x));
}

double getResultS(double x, int n) {
    double sum = 0;
    for (int k = 1; k <= n; ++k) {
        sum += pow(-1, k + 1) * pow(x, 2 * k) / (2 * k * (2 * k - 1));
    }
    return sum;
}

int main()
{
    setlocale(LC_ALL, "Russian"); //Символы русского алфавита в консоли

    std::wcout << L"Введите значения для a: ";
    double a = inputNumber();

    double b;
    do {
        std::wcout << L"Введите значение для b (должно быть больше, чем a): ";
        b = inputNumber();
        if (b <= a) {
            std::wcout << L"Некорректный ввод. Значение b должно быть больше, чем a. Пожалуйста, попробуйте еще раз.\n";
        }
    } while (b <= a);

    std::wcout << L"Введите значения для h: ";
    double h = inputNumber();

    std::wcout << L"Введите значения для n: ";
    double n = inputNumber();

    std::cout << std::fixed << std::setprecision(4); // Вывод 4 знаков после запятой.

    std::cout << std::left << std::setw(15) << "x"
        << std::setw(15) << "Y(x)"
        << std::setw(15) << "S(x)"
        << std::setw(15) << "|Y-S|"
        << "n\n";

    for (double x = a; x <= b; x += h) { // Цикл for, в котором x изменяется от a до b с шагом h.
        double y = getResultY(x);
        double s = getResultS(x, n);
        double diff = fabs(y - s);

        if (diff < 0.001) { // Если разница меньше 0.001, то цикл прерывается.
            break;
        }

        std::cout << std::left << std::setw(15) << x
            << std::setw(15) << y
            << std::setw(15) << s
            << diff
            << "\n";

        if (n > 1000) { // Если n больше 1000 (чтобы предотвратить бесконечный цикл), то цикл прерывается.
            break;
        }

        ++n;
    }

    return 0;
}
#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <sstream>

double inputNumber() {
    double value;

    std::string input;
    while (true) {
        std::getline(std::cin, input); // Считывание всей строки ввода и сохранение ее в переменной input
        std::stringstream ss(input); // Создание объекта std::stringstream с именем ss. std::stringstream нужен для преобразования строк в числа и наоборот

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

    std::wcout << L"Введите значение для e: ";
    double e = inputNumber();

    std::cout << std::fixed << std::setprecision(4); // Вывод 4 знаков после запятой

    std::wcout << std::left << std::setw(15) << "x"
        << std::setw(15) << "Y(x)"
        << std::setw(15) << "S(x)"
        << std::setw(15) << "|Y-S|"
        << L"Кол-во шагов n\n";

    for (double x = a; x <= b; x += h) {
        int n;
        double y = getResultY(x);
        double s = getResultS(x, e, n);
        double diff = fabs(y - s);

        std::cout << std::left << std::setw(15) << x
            << std::setw(15) << y
            << std::setw(15) << s
            << std::setw(15) << diff
            << n
            << "\n";
    }

    return 0;
}
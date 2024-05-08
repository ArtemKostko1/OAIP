#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// Функция для ввода значений с обработкой на целое число
int inputInteger() {
    int value;
    bool isValidInput = false;
    string input;

    while (!isValidInput) {
        getline(cin, input);

        // Проверка, является ли ввод пустым
        if (input.empty()) {
            cout << "Некорректный ввод. Пожалуйста, введите целое неотрицательное число: ";
            continue;
        }

        // Проверка на наличие недопустимых символов
        // Если в строке имееются символы отличные от данных "-0123456789" возвращается true и выводится некорректный ввод
        if (input.find_first_not_of("0123456789") != string::npos) {
            cout << "Некорректный ввод. Пожалуйста, введите целое неотрицательное число: ";
            continue;
        }

        // Попытка преобразовать строку в переменную int
        try {
            value = stoi(input);
            isValidInput = true;
        }
        catch (const exception&) {
            cout << "Некорректный ввод. Пожалуйста, введите целое неотрицательное число: ";
        }
    }

    return value;
}

// Функция для ввода значений с обработкой на положительное целое число
int inputPositive() {
    int value;

    while (true) {
        value = inputInteger();
        if (value > 0) {
            break;
        }
        cout << "Некорректный ввод. Введите положительное число: ";
    }

    return value;
}

// Обычная функция для вычисления факториала
int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Рекурсивная функция для вычисления факториала
int factorialRecursive(int n) {
    if (n <= 0)
        return 1;
    else
        return n * factorialRecursive(n - 1);
}

// Функция для вычисления биномиального коэффициента
int binomialCoeff(int n, int k, int choice) {
    int factN, factK, factNK;

    if (choice == 1) {
        factN = factorial(n);
        factK = factorial(k);
        factNK = factorial(n - k);
    }
    else if (choice == 2) {
        factN = factorialRecursive(n);
        factK = factorialRecursive(k);
        factNK = factorialRecursive(n - k);
    }

    return factN / (factK * factNK);
}

int main()
{
    setlocale(LC_ALL, "ru_RU"); //Символы русского алфавита в консоли

    int n, k, choice;

    cout << "Введите n: ";
    n = inputPositive();
    cout << "Введите k: ";
    k = inputPositive();

    cout << "Выберите способ вычисления (1 - обычная ф-я, 2 - рекурсивная ф-я): ";

    while (!(cin >> choice) || (choice != 1 && choice != 2)) {
        cout << "Некорректный выбор. Пожалуйста, введите 1 или 2: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Биномиальный коэффициент C = " << binomialCoeff(n, k, choice);

    return 0;
}
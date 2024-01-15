#include <iostream>
#include <limits>
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
            cout << "Некорректный ввод. Пожалуйста, введите целое число: ";
            continue;
        }

        // Проверка на наличие недопустимых символов
        // Если в строке имееются символы отличные от данных "-0123456789" возвращается true и выводится некорректный ввод
        if (input.find_first_not_of("-0123456789") != string::npos) {
            cout << "Некорректный ввод. Пожалуйста, введите целое число: ";
            continue;
        }

        // Попытка преобразовать строку в переменную int
        try {
            value = stoi(input);
            isValidInput = true;
        }
        catch (const exception&) {
            cout << "Некорректный ввод. Пожалуйста, введите целое число: ";
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

// Функция для создания и заполнения массива
int** createAndFillArray(int rows, int columns) {
    int** array = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        array[i] = new int[columns];
        for (int j = 0; j < columns; ++j) {
            cout << "Введите значение для элемента [" << i << "] строки и [" << j << "] столбца: ";
            array[i][j] = inputInteger();
        }
    }

    return array;
}

void printArray(int** array, int rows, int columns) {
    cout << "Двумерный массив:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            cout << array[i][j] << ' ';
        }
        cout << endl;
    }
}

// Функция для поиска номера первой строки без положительных элементов
int findFirstNonPositiveRow(int** array, int rows, int columns) {
    for (int i = 0; i < rows; ++i) {
        bool hasPositive = false;
        for (int j = 0; j < columns; ++j) {
            if (array[i][j] > 0) {
                hasPositive = true;
                break;
            }
        }
        if (!hasPositive) {
            return i+1;
        }
    }

    return -1; // Если все строки содержат положительные элементы
}

void deleteArray(int** array, int rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] array[i];
    }
    delete[] array;
}

int main()
{
    setlocale(LC_ALL, "ru_RU"); //Символы русского алфавита в консоли

    int rows, columns;

    cout << "Введите количество строк: ";
    rows = inputPositive();

    cout << "Введите количество столбцов: ";
    columns = inputPositive();

    int** array = createAndFillArray(rows, columns);
    printArray(array, rows, columns);

    int firstNonPositiveRow = findFirstNonPositiveRow(array, rows, columns);
    if (firstNonPositiveRow != -1) {
        cout << "Первая строка без положительных элементов: " << firstNonPositiveRow << endl;
    }
    else {
        cout << "Все строки содержат положительные элементы." << endl;
    }

    deleteArray(array, rows);

    return 0;
}
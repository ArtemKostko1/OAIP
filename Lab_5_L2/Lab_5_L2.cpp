#include <iostream>
#include <limits>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>

// Функция для ввода значений с обработкой на целое число
int inputInteger() {
    int value;
    bool isValidInput = false;
    std::string input;

    while (!isValidInput) {
        std::getline(std::cin, input);

        // Проверка, является ли ввод пустым
        if (input.empty()) {
            std::wcout << L"Некорректный ввод. Пожалуйста, введите целое число: ";
            continue;
        }

        // Проверка на наличие недопустимых символов
        // Если в строке имееются символы отличные от данных "0123456789" возвращается true и выводится некорректный ввод
        if (input.find_first_not_of("0123456789") != std::string::npos) {
            std::wcout << L"Некорректный ввод. Пожалуйста, введите целое число: ";
            continue;
        }

        // Попытка преобразовать строку в переменную int
        try {
            value = std::stoi(input);
            isValidInput = true;
        }
        catch (const std::exception&) {
            std::wcout << L"Некорректный ввод. Пожалуйста, введите целое число: ";
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
        std::wcout << L"Некорректный ввод. Введите положительное число: ";
    }

    return value;
}

// Функция для вывода матрицы на экран
void printMatrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << std::setw(4) << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Функция для создания и заполнения матрицы
int** createAndFillArray(int n) {
    int** matrix = new int* [n];
    std::srand(std::time(nullptr)); // Инициализация генератора случайных чисел
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
        for (int j = 0; j < n; j++) {
            matrix[i][j] = std::rand() % 41 - 20; // Генерация случайного числа от -20 до 20
        }
    }

    return matrix;
}

// Функция для удаления строки и столбца с наибольшим по модулю значением элементом
int** removeRowAndColumn(int** matrix, int n) {
    int maxAbsValue = 0;
    int row = 0;
    int col = 0;

    // Нахождение элемента с наибольшим по модулю значением
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int absValue = abs(matrix[i][j]);
            if (absValue > maxAbsValue) {
                maxAbsValue = absValue;
                row = i;
                col = j;
            }
        }
    }

    // Создание новой матрицы размером (n - 1)
    int** newMatrix = new int* [n-1];

    for (int i = 0; i < n-1; i++) {
        newMatrix[i] = new int[n-1];
    }

    // Копирование элементов из исходной матрицы в новую
    int newRow = 0;
    for (int i = 0; i < n; i++) {
        if (i == row) {
            continue; // Пропускаем строку
        }
        int newCol = 0;
        for (int j = 0; j < n; j++) {
            if (j == col) {
                continue; // Пропускаем столбец
            }
            newMatrix[newRow][newCol] = matrix[i][j];
            newCol++;
        }
        newRow++;
    }

    return newMatrix;
}

int main()
{
    setlocale(LC_ALL, "ru_RU.UTF-8"); //Символы русского алфавита в консоли

    int n;

    std::wcout << L"Введите размер матрицы: ";
    n = inputPositive();

    int** matrix = createAndFillArray(n);

    std::wcout << L"Исходная матрица: " << std::endl;
    printMatrix(matrix, n);
    std::wcout << std::endl;

    int** newMatrix = removeRowAndColumn(matrix, n);

    std::wcout << L"Новая матрица:" << std::endl;
    printMatrix(newMatrix, n-1);

    // Освобождение памяти
    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    for (int i = 0; i < n - 1; i++) {
        delete[] newMatrix[i];
    }
    delete[] newMatrix;

    return 0;
}
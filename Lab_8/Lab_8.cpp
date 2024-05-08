#include <iostream>
#include <sstream>
#include <stack>
#include <vector>
#include <cstdlib>
#include <ctime>

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

// Функция для создания стека со случайными числами
stack<int> createStack(int size) {
    srand(time(0));
    stack<int> s;
    for (int i = 0; i < size; i++) {
        s.push(rand() % 100 - 50); // Генерация случайных чисел от -50 до 49
    }
    return s;
}

// Функция для печати стека
void printStack(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

// Функция для сортировки стека путем обмена информацией
stack<int> sortStack(stack<int> s) {
    vector<int> v;
    while (!s.empty()) {
        v.push_back(s.top());
        s.pop();
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        s.push(v[i]);
    }
    return s;
}

// Функция для удаления каждого второго элемента из стека
stack<int> removeEverySecond(stack<int> s) {
    stack<int> temp;
    int index = 0;
    while (!s.empty()) {
        if (index % 2 == 0) {
            temp.push(s.top());
        }
        s.pop();
        index++;
    }
    return temp;
}

int main()
{
    int size;
    cout << "Введите размер стека: ";
    size = inputPositive();

    stack<int> stack = createStack(size);

    cout << "Исходный стек: ";
    printStack(stack);

    stack = sortStack(stack);

    cout << "Отсортированный стек: ";
    printStack(stack);

    stack = removeEverySecond(stack);

    cout << "Стек после удаления каждого второго элемента: ";
    printStack(stack);

    return 0;
}
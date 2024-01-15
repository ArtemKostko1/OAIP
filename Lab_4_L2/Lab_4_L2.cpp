#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Функция для заполнения массива с клавиатуры
void fillArrayWithUserInput(int arr[], int n) {
    cout << "Введите " << n << " элементов массива:" << endl;;

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
}

// Функция для заполнения массива случайными числами
void fillArrayWithRandomNumbers(int arr[], int n) {
    srand(static_cast<unsigned int>(time(0)));
    cout << "Массив, заполненный случайными числами:" << endl;

    for (int i = 0; i < n; ++i) {
        // От 0 до 99
        arr[i] = rand() % 100;
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Функция удаления из массива нечетных чисел
void removeEvenElements(int arr[], int& n) {
    int i = 0;
    
    while (i < n) {
        if (arr[i] % 2 == 0) {
            for (int j = i; j < n - 1; ++j) {
                // Сдвигает элементы массива, стоящие после элемента i на одну позицию в лево,
                // и тем самым удаляя нечетные числа из массива
                arr[j] = arr[j + 1];
            }
            --n;
        }
        else {
            ++i;
        }
    }
}

void printArray(const int arr[], int n) {
    cout << "Итоговый массив:\n";

    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "ru_RU"); //Символы русского алфавита в консоли

    int n;

    while (true)
    {
        cout << "Введите количество элементов (не более 20): ";
        if (cin >> n)
        {
            if (n > 0 && n <= 20)
            {
                break;
            }
            else
            {
                cout << "Недопустимое количество элементов. Введите положительное число не более 20.\n";
            }
        }
        else
        {
            cout << "Ошибка ввода. Введите число.\n";
            // Возвращает пользователя на ввод значения при некорректном вводе
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    int* arr = new int[n]; // Динамическое выделение памяти для массива
    int choice;

    cout << "Выберите способ заполнения массива (1 - ввод с клавиатуры, 2 - случайные числа): ";

    while (!(cin >> choice) || (choice != 1 && choice != 2)) {
        cout << "Некорректный выбор. Пожалуйста, введите 1 или 2: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    if (choice == 1) {
        fillArrayWithUserInput(arr, n);
    }
    else if (choice == 2) {
        fillArrayWithRandomNumbers(arr, n);
    }

    removeEvenElements(arr, n);
    printArray(arr, n);

    return 0;
}
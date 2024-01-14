#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>


int main()
{
    setlocale(LC_ALL, "ru_RU.UTF-8");

    int n;

    while (true)
    {
        std::wcout << L"Введите количество элементов (не более 20): ";
        if (std::cin >> n)
        {
            if (n > 0 && n <= 20)
            {
                break;
            }
            else
            {
                std::wcout << L"Недопустимое количество элементов. Введите положительное число не более 20.\n";
            }
        }
        else
        {
            std::wcout << L"Ошибка ввода. Введите число.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    int* arr = new int[n]; // Динамическое выделение памяти для массива

    //srand генерирует разные последовательности случайных числ при запуске программы
    srand(static_cast<unsigned int>(time(0)));
    for (int i = 0; i < n; ++i)
    {
        //Оператор % 31 устанавливаеит диапазон значений до 0 - 30, а затем вычитается 10, чтобы сместить диапазон значений от -10 до 20
        arr[i] = rand() % 31 - 10;
    }

    // Нахождение максимального элемента
    int maxElement = arr[0];
    for (int i = 1; i < n; ++i)
    {
        if (arr[i] > maxElement)
        {
            maxElement = arr[i];
        }
    }

    std::wcout << L"Максимальный элемент: " << maxElement << std::endl;

    // Вычисление суммы положительных элементов до максимального элемента
    int sumPositive = 0;
    for (int i = 0; i < n; ++i)
    {
        // Прекращаем поиск после нахождения максимального элемента
        if (arr[i] == maxElement)
        {
            break;
        }

        if (arr[i] > 0)
        {
            sumPositive += arr[i];
        }
    }

    std::wcout << L"Элементы массива: ";
    for (int i = 0; i < n; ++i)
    {
        std::wcout << arr[i] << " ";
    }
    std::wcout << std::endl;

    std::wcout << L"Сумма положительных элементов до максимального элемента: " << sumPositive << std::endl;


    delete[] arr; // Освобождение памяти, выделенной для массива

    return 0;
}
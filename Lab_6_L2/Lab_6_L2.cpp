#include <iostream>
#include <sstream>
#include <string>

int main()
{
    setlocale(LC_ALL, "ru_RU.UTF-8"); //Символы русского алфавита в консоли

    // Стандартный cin считывает данные до первого пробела или /n, поэтому используется getline
    std::string str; // Объявление переменной str типа std::string
    std::wcout << L"Введите строку из слов, разделенных пробелами: ";
    std::getline(std::cin, str); // Считывание строки и запись ее в str

    std::istringstream iss(str); // Считываение из строки str и создание объекта
    std::string word; // Объявление переменной word типа std::string
    int minLength = std::numeric_limits<int>::max();  // Создается переменная minLength, которая инициализируется максимально возможным значением для типа int для отслеживания минимальной длины слова
    int minIndex = -1; // Для хранения порядкового номера (индекса) слова с минимальной длиной
    int currentIndex = 0; // Для отслеживания текущего порядкового номера (индекса) слова при итерации по строке

    while (iss >> word) { // Считывает строку и записывает каждое слово в word
        int length = word.length(); // Получает длину текущего слова

        if (length < minLength) {
            minLength = length;
            minIndex = currentIndex;
        }
        currentIndex++;
    }

    if (minIndex != -1) {
        std::wcout << L"Порядковый номер слова с минимальной длиной: " << minIndex + 1 << std::endl;
    }
    else {
        std::wcout << L"Строка пустая." << std::endl;
    }

    return 0;
}
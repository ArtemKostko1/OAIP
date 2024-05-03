#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru_RU"); //Символы русского алфавита в консоли

    // Стандартный cin считывает данные до первого пробела или /n, поэтому используется getline
    string str; // Объявление переменной str типа string
    cout << "Введите строку из слов, разделенных пробелами: ";
    getline(cin, str); // Считывание строки и запись ее в str

    istringstream ss(str); // Считываение из строки str и создание объекта
    string word; // Объявление переменной word типа string
    int minLength = numeric_limits<int>::max();  // Создается переменная minLength, которая инициализируется максимально возможным значением для типа int для отслеживания минимальной длины слова
    int minIndex = -1; // Для хранения порядкового номера (индекса) слова с минимальной длиной
    int currentIndex = 0; // Для отслеживания текущего порядкового номера (индекса) слова при итерации по строке

    while (ss >> word) { // Считывает строку и записывает каждое слово в word
        int length = word.length(); // Получает длину текущего слова

        if (length < minLength) {
            minLength = length;
            minIndex = currentIndex;
        }
        currentIndex++;
    }

    if (minIndex != -1) {
        cout << "Порядковый номер слова с минимальной длиной: " << minIndex + 1 << endl;
        cout << "Количество сисмволов в найденном слове: " << minLength << endl;
    }
    else {
        cout << "Строка пустая." << endl;
    }

    return 0;
}
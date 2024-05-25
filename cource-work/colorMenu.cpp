#include <iostream>
#include <windows.h>
#include "colorMenu.h"

using namespace std;

void showColorMenu() {
    int choice;
    bool exit = false;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Дескриптор консоли
    
    while (!exit) {
        system("cls");
        cout << "Меню смены цветовой палитры:" << endl;
        cout << "................................................." << endl;
        cout << "1. По умолчанию" << endl;
        cout << "2. Черный фон, зеленый текст" << endl;
        cout << "3. Черный фон, синий текст" << endl;
        cout << "4. Черный фон, красный текст" << endl;
        cout << "5. Зеленый фон, красный текст" << endl;
        cout << "6. Выход" << endl;
        cout << "................................................." << endl;
        cout << "Выберите цветовую политру: ";
        cin >> choice;

        switch (choice) {
        case 1:
            SetConsoleTextAttribute(hConsole, 0x07); // Черный фон, белый текст
            break;
        case 2:
            SetConsoleTextAttribute(hConsole, 0x0A); // Черный фон, зеленый текст
            break;
        case 3:
            SetConsoleTextAttribute(hConsole, 0x09); // Черный фон, синий текст
            break;
        case 4:
            SetConsoleTextAttribute(hConsole, 0x0C); // Черный фон, красный текст
            break;
        case 5:
            SetConsoleTextAttribute(hConsole, 0x20); // Зеленый фон, красный текст
            break;
        case 6:
            exit = true;
            break;
        default:
            cout << "Неверный выбор. Попробуйте снова." << endl;
            Sleep(2000);
            system("cls");
            break;
        }
    }
}
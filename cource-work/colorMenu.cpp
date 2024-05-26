#include <iostream>
#include <thread>
#include "colorMenu.h"

using namespace std;

void colorMenu() {
    int choice;
    bool exit = false;
    
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
            system("color 07"); // Черный фон, белый текст
            break;
        case 2:
            system("color 0A"); // Черный фон, зеленый текст
            break;
        case 3:
            system("color 09"); // Черный фон, синий текст
            break;
        case 4:
            system("color 0C"); // Черный фон, красный текст
            break;
        case 5:
            system("color 20"); // Зеленый фон, красный текст
            break;
        case 6:
            exit = true;
            break;
        default:
            cout << "Неверный ввод. Ожидайте..." << endl;
            cin.clear(); // Очистка ошибочного состояния ввода
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка буфер ввода
            this_thread::sleep_for(chrono::milliseconds(1500)); // Задержка приложения, чтобы пользователь увидел сообщение об ошибке
        }
    }
}
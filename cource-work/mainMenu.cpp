#include <iostream>
#include <thread>
#include "mainMenu.h"
#include "colorMenu.h"

using namespace std;

void showMainMenu() {
    int choice;
    bool exit = false;

    while (!exit) {
        system("cls");
        cout << "Главное меню:" << endl;
        cout << "................................................." << endl;
        cout << "1. Вход" << endl;
        cout << "2. Изменение цветовой палитры" << endl;
        cout << "3. Справка" << endl;
        cout << "4. Выход" << endl;
        cout << "................................................." << endl;
        cout << "Выберите пункт меню: ";
        cin >> choice;

        switch (choice) {
            case 1:
                // Вход
                break;
            case 2:
                showColorMenu();
                break;
            case 3:
                cout << "Справочная информация о приложении." << endl;
                break;
            case 4:
                exit = true;
                break;
            default:
                cout << "Неверный ввод. Ожидайте..." << endl;
                cin.clear(); // Очищаем ошибочное состояние ввода
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очищаем буфер ввода
                this_thread::sleep_for(chrono::milliseconds(2000)); // Задержка приложения, чтобы пользователь увидел сообщение об ошибке
        }
    }
}
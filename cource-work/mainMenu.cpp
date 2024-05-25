#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
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
                cout << "Неверный выбор. Попробуйте снова." << endl;

                // cin.clear(); // Очищаем ошибочное состояние ввода
                // cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очищаем буфер ввода
                // system("pause"); // Приостанавливаем выполнение программы, чтобы пользователь мог прочитать сообщение об ошибке
        }
    }
}
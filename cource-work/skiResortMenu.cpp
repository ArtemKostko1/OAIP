#include <iostream>
#include <thread>
#include "skiResortMenu.h"

using namespace std;

void skiResortMenu() {
    int choice;
    bool exit = false;

    while (!exit) {
        system("cls");
        cout << "Меню горнолыжного комплекса:" << endl;
        cout << "................................................." << endl;
        cout << "1. Добавление нового посетителя" << endl;
        cout << "2. Редактирование данных посетителя" << endl;
        cout << "3. Удаление записи посетителя" << endl;
        cout << "4. Считывание базы с файла" << endl;
        cout << "5. Выход" << endl;
        cout << "................................................." << endl;
        cout << "Выберите цветовую политру: ";
        cin >> choice;

        switch (choice) {
        case 1:
            
            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        case 5:
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
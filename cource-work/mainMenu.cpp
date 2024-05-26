#include <iostream>
#include <thread>
#include "mainMenu.h"
#include "colorMenu.h"
#include "skiResortMenu.h"

using namespace std;

void mainMenu() {
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
            {
                skiResortMenu();
                break;
            }
            case 2:
            {
                colorMenu();
                break;
            }
            case 3:
            {
                bool referenceExit = false;
                while (!referenceExit)
                {
                    system("cls");
                    cout << "................................................." << endl;
                    cout << "Разработчик: Костко Артём Владимирович" << endl;
                    cout << "Группа: 314371" << endl;
                    cout << "Специальность: Информационные системы и технологии" << endl;
                    cout << "БГУИР, Минск, 2024" << endl;
                    cout << "................................................." << endl;
                    cout << "Введите 0 для выхода: ";
                    
                    int input;
                    if (cin >> input && input == 0)
                    {
                        referenceExit = true;
                        break;
                    }
                    else
                    {
                        cout << "Неверный ввод. Ожидайте..." << endl;
                        cin.clear(); // Очистка ошибочного состояния ввода
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка буфер ввода
                        this_thread::sleep_for(chrono::milliseconds(1500)); // Задержка приложения, чтобы пользователь увидел сообщение об ошибке
                    }
                }
                break;
            }
            case 4:
            {
                exit = true;
                break;
            }
            default:
            {
                cout << "Неверный ввод. Ожидайте..." << endl;
                cin.clear(); // Очистка ошибочного состояния ввода
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка буфер ввода
                this_thread::sleep_for(chrono::milliseconds(1500)); // Задержка приложения, чтобы пользователь увидел сообщение об ошибке
            }
        }
    }
}
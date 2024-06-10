#include <iostream>
#include <thread>
#include <chrono>
#include <ctime>
#include "skiResortMenu.h"
#include "skiResortMenuUtils.h"

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
		cout << "4. Просмотор данных о посетителях" << endl;
		// Поиск по ключу из списка структуры
		// Сортировки списка
		cout << "6. Выход" << endl;
		cout << "................................................." << endl;
		cout << "Выберите пункт меню: ";
		cin >> choice;

		switch (choice) {
			case 1:
			{
				fillingNewVisitor();
				break;
			}
			case 2:
				// Редактирование элемента списка структуры

				break;
			case 3:
				// Удаление элемента списка структуры

				break;
			case 4:
			{
				displayVisitors();
				break;
			}
			case 6:
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
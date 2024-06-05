#include <iostream>
#include <thread>
#include "visitor.h"
#include "skiResortMenu.h"

using namespace std;

void skiResortMenu() {
	// Использовать вектор
	Visitor visitor;
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
		cin >> choice;

		switch (choice) {
		case 1:
			system("cls");

			cout << "Введите имя: ";
			cin >> visitor.name;

			cout << "Введите рост: ";
			cin >> visitor.height;

			cout << "Введите вес: ";
			cin >> visitor.weight;

			cout << "Введите размер обуви: ";
			cin >> visitor.footSize;

			cout << "Введите номер документа: ";
			cin >> visitor.documentNumber;

			cout << "Введите номер телефона: ";
			cin >> visitor.phoneNumber;

			int rentalKitChoice;
			cout << "Выберите тип оборудования (1 - Лыжный комплект, 2 - Комплект для сноуборда): ";
			cin >> rentalKitChoice;
			if (rentalKitChoice == 1) {
				visitor.rentalKit = "Лыжный комплект";
			}
			else if (rentalKitChoice == 2) {
				visitor.rentalKit = "Комплект для сноуборда";
			}

			cout << "Выберите время аренды (1 - 2ч, 2 - 4ч, 3 - 6ч, 4 - весь день): ";
			cin >> visitor.rentalTime;

			// Добавление нового посетителя в список структуры

			break;
		case 2:
			// Редактирование элемента списка структуры

			break;
		case 3:
			// Удаление элемента списка структуры

			break;
		case 4:
			cout << visitor.toString();
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
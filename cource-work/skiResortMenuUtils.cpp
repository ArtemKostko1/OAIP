#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <chrono>
#include <ctime>
#include <thread>
#include "visitor.h"
#include "vectorService.h"

using namespace std;

//string checkDocumentNumber() {
//	string documentNumber;
//	bool exit;
//	do {
//		exit = false;
//		cin >> documentNumber;
//		try {
//			getVisitorByDocumentNumber(documentNumber);
//			exit = true;
//			cout << "Посетитель уже существует. Пожалуйста, введите номер документа ещё раз: ";
//		}
//		catch (std::invalid_argument& e) {
//			// Посетитель с данным номером документа не найден, поэтому выходим из цикла
//		}
//	} while (exit);
//	return documentNumber;
//}

string fillingRentalKit() {
	int rentalKitChoice;
	cin >> rentalKitChoice;

	if (rentalKitChoice == 1) {
		return "Лыжный комплект";
	}
	else if (rentalKitChoice == 2) {
		return "Комплект для сноуборда";
	}
}

int fillingRentalTime() {
	int rentalTimeChoice;
	cin >> rentalTimeChoice;

	if (rentalTimeChoice == 1) {
		return 2;
	}
	else if (rentalTimeChoice == 2) {
		return 4;
	}
	else if (rentalTimeChoice == 3) {
		return 6;
	}
	else if (rentalTimeChoice == 4) {
		return 10;
	}
	else {
		cout << "Неверный выбор. Пожалуйста, выберите 1, 2, 3 или 4.";
	}
}

time_t checkTimeNow() {
	auto timeNow = chrono::system_clock::now();
	time_t timeNow_t = chrono::system_clock::to_time_t(timeNow);
	tm* timeNowInfo = localtime(&timeNow_t);

	// Проверка, если текущее время в промежутке с 22:00 до 12:00
	if ((timeNowInfo->tm_hour >= 22) || (timeNowInfo->tm_hour < 12)) {
		// Если текущее время с 22:00:00 до 00:00.00, то поле rentalPeriodStart устанавливает значение в 12:00:00 следующего дня
		if ((timeNowInfo->tm_hour >= 22) || (timeNowInfo->tm_hour < 0)) {
			timeNowInfo->tm_mday += 1;
		}
		// Устанавливаем время в 12:00:00
		timeNowInfo->tm_hour = 12;
		timeNowInfo->tm_min = 0;
		timeNowInfo->tm_sec = 0;

		// Преобразование в тип time_t
		return mktime(timeNowInfo);
	}
	else {
		// Если же текущее время не входит в данный промежуток, поле rentalPeriodStart устанавливает значение без изменений
		return timeNow_t;
	}
}

time_t checkRentalPeriodEnd(int& rentalTime, time_t& rentalPeriodStart) {
	// Создание промежуточной переменной для хранения фактического оканчания арнеды
	time_t rentalPeriodEndTemp = rentalPeriodStart + (rentalTime * 3600);

	// Преобразование значения rentalPeriodEndTemp в тип структуры tm с подробным разбиением времени на элменты
	struct tm* rpeTimeInfo = localtime(&rentalPeriodEndTemp);
	// Проверка, если время окончания аренды после 22:00:00, то устанавливать значение 22:00:00
	if ((rpeTimeInfo->tm_hour >= 22) || (rpeTimeInfo->tm_hour < 12)) {
		rpeTimeInfo->tm_hour = 22;
		rpeTimeInfo->tm_min = 0;
		rpeTimeInfo->tm_sec = 0;
	}

	// Преобразуем обратно в time_t, сохраняя дату, но изменяя время
	return mktime(rpeTimeInfo);
}

void fillingNewVisitor() {
	system("cls");
	Visitor visitor;

	cout << "Введите имя: ";
	cin >> visitor.name;

	cout << "Введите рост (см): ";
	cin >> visitor.height;

	cout << "Введите вес (кг): ";
	cin >> visitor.weight;

	cout << "Введите размер обуви (EU): ";
	cin >> visitor.footSize;

	cout << "Введите номер документа: ";
	//visitor.documentNumber = checkDocumentNumber();
	cin >> visitor.documentNumber;

	cout << "Введите номер телефона: ";
	cin >> visitor.phoneNumber;

	cout << "Выберите тип оборудования (1 - Лыжный комплект, 2 - Комплект для сноуборда): ";
	visitor.rentalKit = fillingRentalKit();

	cout << "Выберите время аренды (1 - 2 часа, 2 - 4 часа, 3 - 6 часов, 4 - весь день (с 12:00 до 22:00)): ";
	visitor.rentalTime = fillingRentalTime();

	visitor.rentalPeriodStart = checkTimeNow();

	visitor.rentalPeriodEnd = checkRentalPeriodEnd(visitor.rentalTime, visitor.rentalPeriodStart);

	addVisitor(visitor);
}

void updateVisitor() {

}

void deleteVisitor() {
	system("cls");
	int visitorId;
	cout << "Введите номер документа посетителя, которого хотите удалить: ";
	cin >> visitorId;
	removeVisitorById(visitorId);
}

void displayVisitors() {
	bool visitorListExit = false;
	while (!visitorListExit)
	{
		system("cls");
		cout << "СПИСОК ВСЕХ ПОСЕТИТЕЛЕЙ \n" << endl;
		printVisitorList();
		cout << "Введите 0 для выхода: ";

		int input;
		if (cin >> input && input == 0)
		{
			visitorListExit = true;
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
}
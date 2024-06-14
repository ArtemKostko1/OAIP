#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <chrono>
#include <ctime>
#include <thread>
#include <algorithm>
#include "visitor.h"
#include "vectorService.h"
#include "fileService.h"

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
//		catch (invalid_argument& e) {
//			// Посетитель с данным номером документа не найден, поэтому выходим из цикла
//		}
//	} while (exit);
//	return documentNumber;
//}

string fillingRentalKit() {
	int rentalKitChoice;
	bool validInput = false;

	while (!validInput) {
		cout << "Ввод: ";
		cin >> rentalKitChoice;

		if (rentalKitChoice == 1) {
			return "Лыжный комплект";
		}
		else if (rentalKitChoice == 2) {
			return "Комплект для сноуборда";
		}
		else if (rentalKitChoice == 3) {
			return "Тюбинг";
		}
		else {
			cout << "Неверный ввод. Ожидайте..." << endl;
			cin.clear(); // Очистка ошибочного состояния ввода
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка буфер ввода
			this_thread::sleep_for(chrono::milliseconds(1500)); // Задержка приложения, чтобы пользователь увидел сообщение об ошибке
		}
	}
}

int fillingRentalTime() {
	int rentalTimeChoice;
	bool validInput = false;

	while (!validInput) {
		cout << "Ввод: ";
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
			cout << "Неверный ввод. Ожидайте..." << endl;
			cin.clear(); // Очистка ошибочного состояния ввода
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка буфер ввода
			this_thread::sleep_for(chrono::milliseconds(1500)); // Задержка приложения, чтобы пользователь увидел сообщение об ошибке
		}
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

float checkFloatInput(const string& prompt) {
	float value;
	while (true) {
		cout << prompt;
		if (cin >> value) {
			return value;
		}
		else {
			cout << "Неверный ввод. Ожидайте..." << endl;
			cin.clear(); // Очистка ошибочного состояния ввода
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка буфер ввода
			this_thread::sleep_for(chrono::milliseconds(1500)); // Задержка приложения, чтобы пользователь увидел сообщение об ошибке
		}
	}
}

void fillingNewVisitor() {
	system("cls");
	Visitor visitor;

	cout << "Введите имя: ";
	cin >> visitor.name;

	visitor.height = checkFloatInput("Введите рост (см): ");

	visitor.weight = checkFloatInput("Введите вес (кг): ");

	visitor.footSize = checkFloatInput("Введите размер обуви (EU): ");

	cout << "Введите номер документа: ";
	//visitor.documentNumber = checkDocumentNumber();
	cin >> visitor.documentNumber;

	cout << "Введите номер телефона: ";
	cin >> visitor.phoneNumber;

	cout << "Выберите тип оборудования (1 - Лыжный комплект, 2 - Комплект для сноуборда, 3 - Тюбинг):" << endl;
	visitor.rentalKit = fillingRentalKit();

	cout << "Выберите время аренды (1 - 2 часа, 2 - 4 часа, 3 - 6 часов, 4 - весь день (с 12:00 до 22:00)):" << endl;
	visitor.rentalTime = fillingRentalTime();

	visitor.rentalPeriodStart = checkTimeNow();

	visitor.rentalPeriodEnd = checkRentalPeriodEnd(visitor.rentalTime, visitor.rentalPeriodStart);

	createVisitor(visitor);
}

void fillingUpdatedVisitor(const int& id, Visitor& visitor) {
	system("cls");

	cout << "Введите имя: ";
	cin >> visitor.name;

	visitor.height = checkFloatInput("Введите рост (см): ");

	visitor.weight = checkFloatInput("Введите вес (кг): ");

	visitor.footSize = checkFloatInput("Введите размер обуви (EU): ");

	cout << "Введите номер документа: ";
	//visitor.documentNumber = checkDocumentNumber();
	cin >> visitor.documentNumber;

	cout << "Введите номер телефона: ";
	cin >> visitor.phoneNumber;

	cout << "Выберите тип оборудования (1 - Лыжный комплект, 2 - Комплект для сноуборда, 3 - Тюбинг):" << endl;
	visitor.rentalKit = fillingRentalKit();

	cout << "Выберите время аренды (1 - 2 часа, 2 - 4 часа, 3 - 6 часов, 4 - весь день (с 12:00 до 22:00)):" << endl;
	visitor.rentalTime = fillingRentalTime();

	visitor.rentalPeriodEnd = checkRentalPeriodEnd(visitor.rentalTime, visitor.rentalPeriodStart);

	updateVisitor(id, visitor);
}

void updateVisitor() {
	bool updateVisitorExit = false;
	while (!updateVisitorExit)
	{
		system("cls");
		int id;
		cout << "Введите идентификатор посетителя, которого хотите отредактировать: ";
		cin >> id;

		try {
			Visitor& visitor = getVisitorById(id);
			fillingUpdatedVisitor(id, visitor);
			updateVisitorExit = true;
		}
		catch (invalid_argument& e) {
			cout << e.what();
			this_thread::sleep_for(chrono::milliseconds(1500));
		}
	}
}

void deleteVisitor() {
	bool deleteVisitorExit = false;
	while (!deleteVisitorExit)
	{
		system("cls");
		int visitorId;
		cout << "Введите идентификатор посетителя, которого хотите удалить: ";
		cin >> visitorId;

		try {
			getVisitorById(visitorId);
			deleteVisitor(visitorId);
			deleteVisitorExit = true;
		}
		catch (invalid_argument& e) {
			cout << e.what();
			this_thread::sleep_for(chrono::milliseconds(1500));
		}
	}
}

vector<Visitor> linearSearch(const string& searchCriterion) {
	vector<Visitor> result;
	vector<Visitor>& globalVisitors = getAllVisitors();

	for (int i = 0; i < globalVisitors.size(); i++)
	{
		if (globalVisitors[i].rentalKit.find(searchCriterion) != string::npos)
		{
			result.push_back(globalVisitors[i]);
		}
	}

	return result;
}

void displayLinearSearch() {
	bool linearSearchExit = false;
	while (!linearSearchExit)
	{
		system("cls");
		cout << "Выберите по какому типу горнолыжного комплекта вы хотите выполнить поиск:" << endl;
		cout << "1 - Лыжный комплект, 2 - Комплект для сноуборда, 3 - Тюбинг" << endl;
		string searchCriterion = fillingRentalKit();

		cout << "................................................." << "\n" << endl;

		vector<Visitor> searchResult = linearSearch(searchCriterion);
		if (searchResult.size() > 0) {
			for (const Visitor& visitor : searchResult) {
				cout << visitor.toString() << "\n" << endl;
			}
		}
		else {
			cout << "Список пуст \n" << endl;
		}

		writeResultToFile(searchResult);

		cout << "................................................." << endl;
		cout << "Введите 0 для выхода: ";

		int exitInput;
		if (cin >> exitInput && exitInput == 0)
		{
			linearSearchExit = true;
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

// Функция для сравнения двух посетителей по полю rentalKit
bool compareVisitors(const Visitor& visitor1, const Visitor& visitor2) {
	return visitor1.rentalKit < visitor2.rentalKit;
}

vector<Visitor> binarySearch(const string& searchCriterion) {
	vector<Visitor> globalVisitors = getAllVisitors();
	vector<Visitor> result;

	// Сортировка списка посетителей по полю rentalKit
	sort(globalVisitors.begin(), globalVisitors.end(), compareVisitors);

	int left = 0;
	int right = globalVisitors.size() - 1;

	while (left <= right) {
		int middle = left + (right - left) / 2;

		// Проверка, совпадает ли критерий поиска с полем rentalKit посетителя в середине
		if (globalVisitors[middle].rentalKit == searchCriterion) {
			result.push_back(globalVisitors[middle]);
			// Проверка элементов слева и справа от найденного
			int temp = middle;
			while (temp > 0 && globalVisitors[temp - 1].rentalKit == searchCriterion) {
				result.push_back(globalVisitors[temp - 1]);
				temp--;
			}
			temp = middle;
			while (temp < globalVisitors.size() - 1 && globalVisitors[temp + 1].rentalKit == searchCriterion) {
				result.push_back(globalVisitors[temp + 1]);
				temp++;
			}
			return result;
		}

		// Если критерий поиска больше, игнорировать левую половину
		if (globalVisitors[middle].rentalKit < searchCriterion) {
			left = middle + 1;
		}
		// Если критерий поиска меньше, игнорировать правую половину
		else {
			right = middle - 1;
		}
	}

	return result;
}

void displayBinarySearch() {
	bool binarySearchExit = false;
	while (!binarySearchExit)
	{
		system("cls");
		cout << "Выберите по какому типу горнолыжного комплекта вы хотите выполнить поиск:" << endl;
		cout << "1 - Лыжный комплект, 2 - Комплект для сноуборда, 3 - Тюбинг" << endl;
		string searchCriterion = fillingRentalKit();

		cout << "................................................." << "\n" << endl;

		vector<Visitor> searchResult = binarySearch(searchCriterion);
		if (searchResult.size() > 0) {
			for (const Visitor& visitor : searchResult) {
				cout << visitor.toString() << "\n" << endl;
			}
		}
		else {
			cout << "Список пуст \n" << endl;
		}

		writeResultToFile(searchResult);

		cout << "................................................." << endl;
		cout << "Введите 0 для выхода: ";

		int exitInput;
		if (cin >> exitInput && exitInput == 0)
		{
			binarySearchExit = true;
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

// Функция для разделения массива на две части для быстрой сортировки
int partition(vector<Visitor>& visitors, int low, int high) {
	Visitor& pivot = visitors[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++) {
		if (compareVisitors(visitors[j], pivot)) {
			i++;
			swap(visitors[i], visitors[j]);
		}
	}
	swap(visitors[i + 1], visitors[high]);
	return (i + 1);
}

// Рекурсивная функция быстрой сортировки
void quickSort(vector<Visitor>& visitors, int low, int high) {
    if (low < high) {
        int pivot = partition(visitors, low, high);

        quickSort(visitors, low, pivot - 1);
        quickSort(visitors, pivot + 1, high);
    }
}

vector<Visitor> quickSortDefinition() {
	vector<Visitor> sortedVisitors = getAllVisitors();

	quickSort(sortedVisitors, 0, sortedVisitors.size() - 1);

	return sortedVisitors;
}

void displayQuickSort() {
	bool quickSortExit = false;
	while (!quickSortExit)
	{
		system("cls");
		cout << "ОТСОРТИРОВАННЫЙ СПИСОК ПОСЕТИТЕЛЕЙ \n" << endl;
		cout << ".................................................\n" << endl;

		vector<Visitor> sortResult = quickSortDefinition();
		if (sortResult.size() > 0) {
			for (const Visitor& visitor : sortResult) {
				cout << visitor.toString() << "\n" << endl;
			}
		}
		else {
			cout << "Список пуст \n" << endl;
		}

		writeResultToFile(sortResult);

		cout << "................................................." << endl;
		cout << "Введите 0 для выхода: ";

		int exitInput;
		if (cin >> exitInput && exitInput == 0)
		{
			quickSortExit = true;
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

vector<Visitor> selectionSort() {
	vector<Visitor> sortedVisitors = getAllVisitors();

	int visitorsSize = sortedVisitors.size();
	for (int i = 0; i < visitorsSize - 1; i++) {
		int minIndex = i;
		for (int j = i + 1; j < visitorsSize; j++) {
			if (compareVisitors(sortedVisitors[j], sortedVisitors[minIndex])) {
				minIndex = j;
			}
		}
		swap(sortedVisitors[minIndex], sortedVisitors[i]);
	}

	return sortedVisitors;
}

void displaySelectionSort() {
	bool selectionSortExit = false;
	while (!selectionSortExit)
	{
		system("cls");
		cout << "ОТСОРТИРОВАННЫЙ СПИСОК ПОСЕТИТЕЛЕЙ \n" << endl;
		cout << ".................................................\n" << endl;

		vector<Visitor> sortResult = selectionSort();
		if (sortResult.size() > 0) {
			for (const Visitor& visitor : sortResult) {
				cout << visitor.toString() << "\n" << endl;
			}
		}
		else {
			cout << "Список пуст \n" << endl;
		}

		writeResultToFile(sortResult);

		cout << "................................................." << endl;
		cout << "Введите 0 для выхода: ";

		int exitInput;
		if (cin >> exitInput && exitInput == 0)
		{
			selectionSortExit = true;
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

vector<Visitor> bubbleSort (){
	vector<Visitor> sortedVisitors = getAllVisitors();

	int visitorsSize = sortedVisitors.size();
	for (int i = 0; i < visitorsSize - 1; i++) {
		for (int j = 0; j < visitorsSize - i - 1; j++) {
			if (!compareVisitors(sortedVisitors[j], sortedVisitors[j + 1])) {
				swap(sortedVisitors[j], sortedVisitors[j + 1]);
			}
		}
	}

	return sortedVisitors;
}

void displayBubbleSort (){
	bool bubbleSortExit = false;
	while (!bubbleSortExit)
	{
		system("cls");
		cout << "ОТСОРТИРОВАННЫЙ СПИСОК ПОСЕТИТЕЛЕЙ \n" << endl;
		cout << ".................................................\n" << endl;

		vector<Visitor> sortResult = bubbleSort();
		if (sortResult.size() > 0) {
			for (const Visitor& visitor : sortResult) {
				cout << visitor.toString() << "\n" << endl;
			}
		}
		else {
			cout << "Список пуст \n" << endl;
		}

		writeResultToFile(sortResult);

		cout << "................................................." << endl;
		cout << "Введите 0 для выхода: ";

		int exitInput;
		if (cin >> exitInput && exitInput == 0)
		{
			bubbleSortExit = true;
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

// Функция для сравнения двух посетителей по полю rentalPeriodEnd
bool compareVisitorsByTime(const Visitor& visitor1, const Visitor& visitor2) {
	return visitor1.rentalPeriodEnd > visitor2.rentalPeriodEnd;
}

vector<Visitor> individualTask() {
	vector<Visitor> globalVisitors = getAllVisitors();
	vector<Visitor> result;

	// Текущее время
	time_t currentTime;
	time(&currentTime);

	// Поиск по критериям
	for (const Visitor& visitor : globalVisitors) {
		if (visitor.rentalKit == "Комплект для сноуборда" && difftime(visitor.rentalPeriodEnd, currentTime) > 0) {
			result.push_back(visitor);
		}
	}

	// Сортировка результата по убыванию оставшегося времени
	sort(result.begin(), result.end(), compareVisitorsByTime);

	return result;
}

void displayIndividualTask() {
	bool individualTaskExit = false;
	while (!individualTaskExit)
	{
		system("cls");
		cout << "СПИСОК ПОСЕТИТЕЛЕЙ С КОМПЛЕКТОМ ДЛЯ СНОУБОРДА У КОТОРЫХ ЕЩЕ ДЕЙСТВУЕТ АРЕНДА \n" << endl;
		cout << ".................................................\n" << endl;

		vector<Visitor> sortResult = individualTask();
		if (sortResult.size() > 0) {
			for (const Visitor& visitor : sortResult) {
				cout << visitor.toString() << "\n" << endl;
			}
		}
		else {
			cout << "Список пуст \n" << endl;
		}

		writeResultToFile(sortResult);

		cout << "................................................." << endl;
		cout << "Введите 0 для выхода: ";

		int exitInput;
		if (cin >> exitInput && exitInput == 0)
		{
			individualTaskExit = true;
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

void displayVisitors() {
	bool visitorListExit = false;
	while (!visitorListExit)
	{
		system("cls");
		cout << "СПИСОК ВСЕХ ПОСЕТИТЕЛЕЙ \n" << endl;
		printVisitorList();

		cout << "................................................." << endl;
		cout << "1. Линейный поиск" << endl;
		cout << "2. Бинарный поиск" << endl;
		cout << "3. Быстрая сортировка" << endl;
		cout << "4. Сортировка выбором" << endl;
		cout << "5. Сортировка пузырьком" << endl;
		cout << "6. Индивидуальное задание" << endl;
		cout << "0. Выход" << endl;
		cout << "................................................." << endl;
		cout << "Выберите пункт меню: ";
		int choice;
		cin >> choice;

		switch (choice) {
		case 1:
			displayLinearSearch();
			break;
		case 2:
			displayBinarySearch();
			break;
		case 3:
			displayQuickSort();
			break;
		case 4:
			displaySelectionSort();
			break;
		case 5:
			displayBubbleSort();
			break;
		case 6:
			displayIndividualTask();
			break;
		case 0:
			visitorListExit = true;
			break;
		default:
			cout << "Неверный ввод. Ожидайте..." << endl;
			cin.clear(); // Очистка ошибочного состояния ввода
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка буфер ввода
			this_thread::sleep_for(chrono::milliseconds(1500)); // Задержка приложения, чтобы пользователь увидел сообщение об ошибке
		}
	}
}
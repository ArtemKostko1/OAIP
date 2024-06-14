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
//			cout << "���������� ��� ����������. ����������, ������� ����� ��������� ��� ���: ";
//		}
//		catch (invalid_argument& e) {
//			// ���������� � ������ ������� ��������� �� ������, ������� ������� �� �����
//		}
//	} while (exit);
//	return documentNumber;
//}

string fillingRentalKit() {
	int rentalKitChoice;
	bool validInput = false;

	while (!validInput) {
		cout << "����: ";
		cin >> rentalKitChoice;

		if (rentalKitChoice == 1) {
			return "������ ��������";
		}
		else if (rentalKitChoice == 2) {
			return "�������� ��� ���������";
		}
		else if (rentalKitChoice == 3) {
			return "������";
		}
		else {
			cout << "�������� ����. ��������..." << endl;
			cin.clear(); // ������� ���������� ��������� �����
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ������� ����� �����
			this_thread::sleep_for(chrono::milliseconds(1500)); // �������� ����������, ����� ������������ ������ ��������� �� ������
		}
	}
}

int fillingRentalTime() {
	int rentalTimeChoice;
	bool validInput = false;

	while (!validInput) {
		cout << "����: ";
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
			cout << "�������� ����. ��������..." << endl;
			cin.clear(); // ������� ���������� ��������� �����
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ������� ����� �����
			this_thread::sleep_for(chrono::milliseconds(1500)); // �������� ����������, ����� ������������ ������ ��������� �� ������
		}
	}
}

time_t checkTimeNow() {
	auto timeNow = chrono::system_clock::now();
	time_t timeNow_t = chrono::system_clock::to_time_t(timeNow);
	tm* timeNowInfo = localtime(&timeNow_t);

	// ��������, ���� ������� ����� � ���������� � 22:00 �� 12:00
	if ((timeNowInfo->tm_hour >= 22) || (timeNowInfo->tm_hour < 12)) {
		// ���� ������� ����� � 22:00:00 �� 00:00.00, �� ���� rentalPeriodStart ������������� �������� � 12:00:00 ���������� ���
		if ((timeNowInfo->tm_hour >= 22) || (timeNowInfo->tm_hour < 0)) {
			timeNowInfo->tm_mday += 1;
		}
		// ������������� ����� � 12:00:00
		timeNowInfo->tm_hour = 12;
		timeNowInfo->tm_min = 0;
		timeNowInfo->tm_sec = 0;

		// �������������� � ��� time_t
		return mktime(timeNowInfo);
	}
	else {
		// ���� �� ������� ����� �� ������ � ������ ����������, ���� rentalPeriodStart ������������� �������� ��� ���������
		return timeNow_t;
	}
}

time_t checkRentalPeriodEnd(int& rentalTime, time_t& rentalPeriodStart) {
	// �������� ������������� ���������� ��� �������� ������������ ��������� ������
	time_t rentalPeriodEndTemp = rentalPeriodStart + (rentalTime * 3600);

	// �������������� �������� rentalPeriodEndTemp � ��� ��������� tm � ��������� ���������� ������� �� �������
	struct tm* rpeTimeInfo = localtime(&rentalPeriodEndTemp);
	// ��������, ���� ����� ��������� ������ ����� 22:00:00, �� ������������� �������� 22:00:00
	if ((rpeTimeInfo->tm_hour >= 22) || (rpeTimeInfo->tm_hour < 12)) {
		rpeTimeInfo->tm_hour = 22;
		rpeTimeInfo->tm_min = 0;
		rpeTimeInfo->tm_sec = 0;
	}

	// ����������� ������� � time_t, �������� ����, �� ������� �����
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
			cout << "�������� ����. ��������..." << endl;
			cin.clear(); // ������� ���������� ��������� �����
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ������� ����� �����
			this_thread::sleep_for(chrono::milliseconds(1500)); // �������� ����������, ����� ������������ ������ ��������� �� ������
		}
	}
}

void fillingNewVisitor() {
	system("cls");
	Visitor visitor;

	cout << "������� ���: ";
	cin >> visitor.name;

	visitor.height = checkFloatInput("������� ���� (��): ");

	visitor.weight = checkFloatInput("������� ��� (��): ");

	visitor.footSize = checkFloatInput("������� ������ ����� (EU): ");

	cout << "������� ����� ���������: ";
	//visitor.documentNumber = checkDocumentNumber();
	cin >> visitor.documentNumber;

	cout << "������� ����� ��������: ";
	cin >> visitor.phoneNumber;

	cout << "�������� ��� ������������ (1 - ������ ��������, 2 - �������� ��� ���������, 3 - ������):" << endl;
	visitor.rentalKit = fillingRentalKit();

	cout << "�������� ����� ������ (1 - 2 ����, 2 - 4 ����, 3 - 6 �����, 4 - ���� ���� (� 12:00 �� 22:00)):" << endl;
	visitor.rentalTime = fillingRentalTime();

	visitor.rentalPeriodStart = checkTimeNow();

	visitor.rentalPeriodEnd = checkRentalPeriodEnd(visitor.rentalTime, visitor.rentalPeriodStart);

	createVisitor(visitor);
}

void fillingUpdatedVisitor(const int& id, Visitor& visitor) {
	system("cls");

	cout << "������� ���: ";
	cin >> visitor.name;

	visitor.height = checkFloatInput("������� ���� (��): ");

	visitor.weight = checkFloatInput("������� ��� (��): ");

	visitor.footSize = checkFloatInput("������� ������ ����� (EU): ");

	cout << "������� ����� ���������: ";
	//visitor.documentNumber = checkDocumentNumber();
	cin >> visitor.documentNumber;

	cout << "������� ����� ��������: ";
	cin >> visitor.phoneNumber;

	cout << "�������� ��� ������������ (1 - ������ ��������, 2 - �������� ��� ���������, 3 - ������):" << endl;
	visitor.rentalKit = fillingRentalKit();

	cout << "�������� ����� ������ (1 - 2 ����, 2 - 4 ����, 3 - 6 �����, 4 - ���� ���� (� 12:00 �� 22:00)):" << endl;
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
		cout << "������� ������������� ����������, �������� ������ ���������������: ";
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
		cout << "������� ������������� ����������, �������� ������ �������: ";
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
		cout << "�������� �� ������ ���� ������������ ��������� �� ������ ��������� �����:" << endl;
		cout << "1 - ������ ��������, 2 - �������� ��� ���������, 3 - ������" << endl;
		string searchCriterion = fillingRentalKit();

		cout << "................................................." << "\n" << endl;

		vector<Visitor> searchResult = linearSearch(searchCriterion);
		if (searchResult.size() > 0) {
			for (const Visitor& visitor : searchResult) {
				cout << visitor.toString() << "\n" << endl;
			}
		}
		else {
			cout << "������ ���� \n" << endl;
		}

		writeResultToFile(searchResult);

		cout << "................................................." << endl;
		cout << "������� 0 ��� ������: ";

		int exitInput;
		if (cin >> exitInput && exitInput == 0)
		{
			linearSearchExit = true;
			break;
		}
		else
		{
			cout << "�������� ����. ��������..." << endl;
			cin.clear(); // ������� ���������� ��������� �����
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ������� ����� �����
			this_thread::sleep_for(chrono::milliseconds(1500)); // �������� ����������, ����� ������������ ������ ��������� �� ������
		}
	}
}

// ������� ��� ��������� ���� ����������� �� ���� rentalKit
bool compareVisitors(const Visitor& visitor1, const Visitor& visitor2) {
	return visitor1.rentalKit < visitor2.rentalKit;
}

vector<Visitor> binarySearch(const string& searchCriterion) {
	vector<Visitor> globalVisitors = getAllVisitors();
	vector<Visitor> result;

	// ���������� ������ ����������� �� ���� rentalKit
	sort(globalVisitors.begin(), globalVisitors.end(), compareVisitors);

	int left = 0;
	int right = globalVisitors.size() - 1;

	while (left <= right) {
		int middle = left + (right - left) / 2;

		// ��������, ��������� �� �������� ������ � ����� rentalKit ���������� � ��������
		if (globalVisitors[middle].rentalKit == searchCriterion) {
			result.push_back(globalVisitors[middle]);
			// �������� ��������� ����� � ������ �� ����������
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

		// ���� �������� ������ ������, ������������ ����� ��������
		if (globalVisitors[middle].rentalKit < searchCriterion) {
			left = middle + 1;
		}
		// ���� �������� ������ ������, ������������ ������ ��������
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
		cout << "�������� �� ������ ���� ������������ ��������� �� ������ ��������� �����:" << endl;
		cout << "1 - ������ ��������, 2 - �������� ��� ���������, 3 - ������" << endl;
		string searchCriterion = fillingRentalKit();

		cout << "................................................." << "\n" << endl;

		vector<Visitor> searchResult = binarySearch(searchCriterion);
		if (searchResult.size() > 0) {
			for (const Visitor& visitor : searchResult) {
				cout << visitor.toString() << "\n" << endl;
			}
		}
		else {
			cout << "������ ���� \n" << endl;
		}

		writeResultToFile(searchResult);

		cout << "................................................." << endl;
		cout << "������� 0 ��� ������: ";

		int exitInput;
		if (cin >> exitInput && exitInput == 0)
		{
			binarySearchExit = true;
			break;
		}
		else
		{
			cout << "�������� ����. ��������..." << endl;
			cin.clear(); // ������� ���������� ��������� �����
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ������� ����� �����
			this_thread::sleep_for(chrono::milliseconds(1500)); // �������� ����������, ����� ������������ ������ ��������� �� ������
		}
	}
}

// ������� ��� ���������� ������� �� ��� ����� ��� ������� ����������
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

// ����������� ������� ������� ����������
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
		cout << "��������������� ������ ����������� \n" << endl;
		cout << ".................................................\n" << endl;

		vector<Visitor> sortResult = quickSortDefinition();
		if (sortResult.size() > 0) {
			for (const Visitor& visitor : sortResult) {
				cout << visitor.toString() << "\n" << endl;
			}
		}
		else {
			cout << "������ ���� \n" << endl;
		}

		writeResultToFile(sortResult);

		cout << "................................................." << endl;
		cout << "������� 0 ��� ������: ";

		int exitInput;
		if (cin >> exitInput && exitInput == 0)
		{
			quickSortExit = true;
			break;
		}
		else
		{
			cout << "�������� ����. ��������..." << endl;
			cin.clear(); // ������� ���������� ��������� �����
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ������� ����� �����
			this_thread::sleep_for(chrono::milliseconds(1500)); // �������� ����������, ����� ������������ ������ ��������� �� ������
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
		cout << "��������������� ������ ����������� \n" << endl;
		cout << ".................................................\n" << endl;

		vector<Visitor> sortResult = selectionSort();
		if (sortResult.size() > 0) {
			for (const Visitor& visitor : sortResult) {
				cout << visitor.toString() << "\n" << endl;
			}
		}
		else {
			cout << "������ ���� \n" << endl;
		}

		writeResultToFile(sortResult);

		cout << "................................................." << endl;
		cout << "������� 0 ��� ������: ";

		int exitInput;
		if (cin >> exitInput && exitInput == 0)
		{
			selectionSortExit = true;
			break;
		}
		else
		{
			cout << "�������� ����. ��������..." << endl;
			cin.clear(); // ������� ���������� ��������� �����
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ������� ����� �����
			this_thread::sleep_for(chrono::milliseconds(1500)); // �������� ����������, ����� ������������ ������ ��������� �� ������
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
		cout << "��������������� ������ ����������� \n" << endl;
		cout << ".................................................\n" << endl;

		vector<Visitor> sortResult = bubbleSort();
		if (sortResult.size() > 0) {
			for (const Visitor& visitor : sortResult) {
				cout << visitor.toString() << "\n" << endl;
			}
		}
		else {
			cout << "������ ���� \n" << endl;
		}

		writeResultToFile(sortResult);

		cout << "................................................." << endl;
		cout << "������� 0 ��� ������: ";

		int exitInput;
		if (cin >> exitInput && exitInput == 0)
		{
			bubbleSortExit = true;
			break;
		}
		else
		{
			cout << "�������� ����. ��������..." << endl;
			cin.clear(); // ������� ���������� ��������� �����
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ������� ����� �����
			this_thread::sleep_for(chrono::milliseconds(1500)); // �������� ����������, ����� ������������ ������ ��������� �� ������
		}
	}
}

// ������� ��� ��������� ���� ����������� �� ���� rentalPeriodEnd
bool compareVisitorsByTime(const Visitor& visitor1, const Visitor& visitor2) {
	return visitor1.rentalPeriodEnd > visitor2.rentalPeriodEnd;
}

vector<Visitor> individualTask() {
	vector<Visitor> globalVisitors = getAllVisitors();
	vector<Visitor> result;

	// ������� �����
	time_t currentTime;
	time(&currentTime);

	// ����� �� ���������
	for (const Visitor& visitor : globalVisitors) {
		if (visitor.rentalKit == "�������� ��� ���������" && difftime(visitor.rentalPeriodEnd, currentTime) > 0) {
			result.push_back(visitor);
		}
	}

	// ���������� ���������� �� �������� ����������� �������
	sort(result.begin(), result.end(), compareVisitorsByTime);

	return result;
}

void displayIndividualTask() {
	bool individualTaskExit = false;
	while (!individualTaskExit)
	{
		system("cls");
		cout << "������ ����������� � ���������� ��� ��������� � ������� ��� ��������� ������ \n" << endl;
		cout << ".................................................\n" << endl;

		vector<Visitor> sortResult = individualTask();
		if (sortResult.size() > 0) {
			for (const Visitor& visitor : sortResult) {
				cout << visitor.toString() << "\n" << endl;
			}
		}
		else {
			cout << "������ ���� \n" << endl;
		}

		writeResultToFile(sortResult);

		cout << "................................................." << endl;
		cout << "������� 0 ��� ������: ";

		int exitInput;
		if (cin >> exitInput && exitInput == 0)
		{
			individualTaskExit = true;
			break;
		}
		else
		{
			cout << "�������� ����. ��������..." << endl;
			cin.clear(); // ������� ���������� ��������� �����
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ������� ����� �����
			this_thread::sleep_for(chrono::milliseconds(1500)); // �������� ����������, ����� ������������ ������ ��������� �� ������
		}
	}
}

void displayVisitors() {
	bool visitorListExit = false;
	while (!visitorListExit)
	{
		system("cls");
		cout << "������ ���� ����������� \n" << endl;
		printVisitorList();

		cout << "................................................." << endl;
		cout << "1. �������� �����" << endl;
		cout << "2. �������� �����" << endl;
		cout << "3. ������� ����������" << endl;
		cout << "4. ���������� �������" << endl;
		cout << "5. ���������� ���������" << endl;
		cout << "6. �������������� �������" << endl;
		cout << "0. �����" << endl;
		cout << "................................................." << endl;
		cout << "�������� ����� ����: ";
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
			cout << "�������� ����. ��������..." << endl;
			cin.clear(); // ������� ���������� ��������� �����
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ������� ����� �����
			this_thread::sleep_for(chrono::milliseconds(1500)); // �������� ����������, ����� ������������ ������ ��������� �� ������
		}
	}
}
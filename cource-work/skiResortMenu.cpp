#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <thread>
#include <chrono>
#include <ctime>
#include <iostream>
#include "visitor.h"
#include "skiResortMenu.h"
#include "vectorService.h"

using namespace std;

void fillingNewVisitor() {
	system("cls");
	Visitor visitor;

	cout << "������� ���: ";
	cin >> visitor.name;

	cout << "������� ����: ";
	cin >> visitor.height;

	cout << "������� ���: ";
	cin >> visitor.weight;

	cout << "������� ������ �����: ";
	cin >> visitor.footSize;

	cout << "������� ����� ���������: ";
	cin >> visitor.documentNumber;

	cout << "������� ����� ��������: ";
	cin >> visitor.phoneNumber;

	int rentalKitChoice;
	cout << "�������� ��� ������������ (1 - ������ ��������, 2 - �������� ��� ���������): ";
	cin >> rentalKitChoice;
	if (rentalKitChoice == 1) {
		visitor.rentalKit = "������ ��������";
	}
	else if (rentalKitChoice == 2) {
		visitor.rentalKit = "�������� ��� ���������";
	}

	cout << "�������� ����� ������ (1 - 2�, 2 - 4�, 3 - 6�, 4 - ���� ����): ";
	int rentalTimeChoice;
	cin >> rentalTimeChoice;

	if (rentalTimeChoice == 1) {
		visitor.rentalTime = 2;
	}
	else if (rentalTimeChoice == 2) {
		visitor.rentalTime = 4;
	}
	else if (rentalTimeChoice == 3) {
		visitor.rentalTime = 6;
	}
	else if (rentalTimeChoice == 4) {
		visitor.rentalTime = 10;
	}
	else {
		cout << "�������� �����. ����������, �������� 1, 2, 3 ��� 4.";
	}

	auto timeNow = chrono::system_clock::now();
	time_t timeNow_t = chrono::system_clock::to_time_t(timeNow);
	tm* timeNowInfo = localtime(&timeNow_t);

	if ((timeNowInfo->tm_hour >= 22) || (timeNowInfo->tm_hour < 12)) {
		// ���� ������� ����� � 22:00:00 �� 23.59.59, �� ���� visitor.rentalPeriodStart ������������� �������� � 12:00:00 ���������� ���
		if ((timeNowInfo->tm_hour >= 22) || (timeNowInfo->tm_hour < 0)) {
			timeNowInfo->tm_mday += 1; // ��������� �� ��������� ����
		}
		// ������������� ����� � 12:00:00
		timeNowInfo->tm_hour = 12;
		timeNowInfo->tm_min = 0;
		timeNowInfo->tm_sec = 0;

		visitor.rentalPeriodStart = mktime(timeNowInfo); // ����������� ������� � time_t
	}
	else {
		visitor.rentalPeriodStart = timeNow_t;
	}

	time_t rentalPeriodEndTemp = visitor.rentalPeriodStart + (visitor.rentalTime * 3600);
	// �������� ������� ����� � ������� struct tm
	struct tm* rpeTimeInfo = localtime(&rentalPeriodEndTemp);
	// ���� ����� ������ ��� ����� 22:00
	if ((rpeTimeInfo->tm_hour >= 22) || (rpeTimeInfo->tm_hour < 12)) {
		rpeTimeInfo->tm_hour = 22;
		rpeTimeInfo->tm_min = 0;
		rpeTimeInfo->tm_sec = 0;
	}

	// ����������� ������� � time_t, �������� ����, �� ������� �����
	visitor.rentalPeriodEnd = mktime(rpeTimeInfo);

	addVisitor(visitor);
}

void skiResortMenu() {
	int choice;
	bool exit = false;

	while (!exit) {
		system("cls");
		cout << "���� ������������ ���������:" << endl;
		cout << "................................................." << endl;
		cout << "1. ���������� ������ ����������" << endl;
		cout << "2. �������������� ������ ����������" << endl;
		cout << "3. �������� ������ ����������" << endl;
		cout << "4. ��������� ������ � �����������" << endl;
		// ����� �� ����� �� ������ ���������
		// ���������� ������
		cout << "6. �����" << endl;
		cout << "................................................." << endl;
		cin >> choice;

		switch (choice) {
		case 1:
			fillingNewVisitor();

			break;
		case 2:
			// �������������� �������� ������ ���������

			break;
		case 3:
			// �������� �������� ������ ���������

			break;
		case 4:
			printVisitorList();

			break;
		case 6:
			exit = true;
			break;

		default:
			cout << "�������� ����. ��������..." << endl;
			cin.clear(); // ������� ���������� ��������� �����
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ������� ����� �����
			this_thread::sleep_for(chrono::milliseconds(1500)); // �������� ����������, ����� ������������ ������ ��������� �� ������
		}
	}
}
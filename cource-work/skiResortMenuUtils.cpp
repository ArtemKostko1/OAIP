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
//			cout << "���������� ��� ����������. ����������, ������� ����� ��������� ��� ���: ";
//		}
//		catch (std::invalid_argument& e) {
//			// ���������� � ������ ������� ��������� �� ������, ������� ������� �� �����
//		}
//	} while (exit);
//	return documentNumber;
//}

string fillingRentalKit() {
	int rentalKitChoice;
	cin >> rentalKitChoice;

	if (rentalKitChoice == 1) {
		return "������ ��������";
	}
	else if (rentalKitChoice == 2) {
		return "�������� ��� ���������";
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
		cout << "�������� �����. ����������, �������� 1, 2, 3 ��� 4.";
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

void fillingNewVisitor() {
	system("cls");
	Visitor visitor;

	cout << "������� ���: ";
	cin >> visitor.name;

	cout << "������� ���� (��): ";
	cin >> visitor.height;

	cout << "������� ��� (��): ";
	cin >> visitor.weight;

	cout << "������� ������ ����� (EU): ";
	cin >> visitor.footSize;

	cout << "������� ����� ���������: ";
	//visitor.documentNumber = checkDocumentNumber();
	cin >> visitor.documentNumber;

	cout << "������� ����� ��������: ";
	cin >> visitor.phoneNumber;

	cout << "�������� ��� ������������ (1 - ������ ��������, 2 - �������� ��� ���������): ";
	visitor.rentalKit = fillingRentalKit();

	cout << "�������� ����� ������ (1 - 2 ����, 2 - 4 ����, 3 - 6 �����, 4 - ���� ���� (� 12:00 �� 22:00)): ";
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
	cout << "������� ����� ��������� ����������, �������� ������ �������: ";
	cin >> visitorId;
	removeVisitorById(visitorId);
}

void displayVisitors() {
	bool visitorListExit = false;
	while (!visitorListExit)
	{
		system("cls");
		cout << "������ ���� ����������� \n" << endl;
		printVisitorList();
		cout << "������� 0 ��� ������: ";

		int input;
		if (cin >> input && input == 0)
		{
			visitorListExit = true;
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
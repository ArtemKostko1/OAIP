#include <iostream>
#include <thread>
#include <chrono>
#include "visitor.h"
#include "skiResortMenu.h"
#include "vectorService.h"

using namespace std;

void skiResortMenu() {
	// ������������ ������
	Visitor visitor;
	vector<Visitor> visitors;
	int choice;
	bool exit = false;
	int secondsToAdd = 3600;
	chrono::system_clock::time_point timeNow;

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
			system("cls");

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

			timeNow = chrono::system_clock::now();
			visitor.rentalPeriodStart = chrono::system_clock::to_time_t(timeNow);

			visitor.rentalPeriodEnd = visitor.rentalPeriodStart + (visitor.rentalTime * secondsToAdd);

			addVisitor(visitor);

			// ���������� ������ ���������� � ������ ���������

			break;
		case 2:
			// �������������� �������� ������ ���������

			break;
		case 3:
			// �������� �������� ������ ���������

			break;
		case 4:
			cout << visitor.toString();
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
#include <iostream>
#include <thread>
#include "visitor.h"
#include "skiResortMenu.h"

using namespace std;

void skiResortMenu() {
	// ������������ ������
	Visitor visitor;
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
			cin >> visitor.rentalTime;

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
#include <iostream>
#include <thread>
#include "skiResortMenu.h"

using namespace std;

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
        cout << "4. ���������� ���� � �����" << endl;
        cout << "5. �����" << endl;
        cout << "................................................." << endl;
        cout << "�������� �������� �������: ";
        cin >> choice;

        switch (choice) {
        case 1:
            
            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        case 5:
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
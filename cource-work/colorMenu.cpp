#include <iostream>
#include <thread>
#include "colorMenu.h"

using namespace std;

void colorMenu() {
    int choice;
    bool exit = false;
    
    while (!exit) {
        system("cls");
        cout << "���� ����� �������� �������:" << endl;
        cout << "................................................." << endl;
        cout << "1. �� ���������" << endl;
        cout << "2. ������ ���, ������� �����" << endl;
        cout << "3. ������ ���, ����� �����" << endl;
        cout << "4. ������ ���, ������� �����" << endl;
        cout << "5. ������� ���, ������� �����" << endl;
        cout << "6. �����" << endl;
        cout << "................................................." << endl;
        cout << "�������� �������� �������: ";
        cin >> choice;

        switch (choice) {
        case 1:
            system("color 07"); // ������ ���, ����� �����
            break;
        case 2:
            system("color 0A"); // ������ ���, ������� �����
            break;
        case 3:
            system("color 09"); // ������ ���, ����� �����
            break;
        case 4:
            system("color 0C"); // ������ ���, ������� �����
            break;
        case 5:
            system("color 20"); // ������� ���, ������� �����
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
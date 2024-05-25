#include <iostream>
#include <windows.h>
#include "colorMenu.h"

using namespace std;

void showColorMenu() {
    int choice;
    bool exit = false;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // ���������� �������
    
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
            SetConsoleTextAttribute(hConsole, 0x07); // ������ ���, ����� �����
            break;
        case 2:
            SetConsoleTextAttribute(hConsole, 0x0A); // ������ ���, ������� �����
            break;
        case 3:
            SetConsoleTextAttribute(hConsole, 0x09); // ������ ���, ����� �����
            break;
        case 4:
            SetConsoleTextAttribute(hConsole, 0x0C); // ������ ���, ������� �����
            break;
        case 5:
            SetConsoleTextAttribute(hConsole, 0x20); // ������� ���, ������� �����
            break;
        case 6:
            exit = true;
            break;
        default:
            cout << "�������� �����. ���������� �����." << endl;
            Sleep(2000);
            system("cls");
            break;
        }
    }
}
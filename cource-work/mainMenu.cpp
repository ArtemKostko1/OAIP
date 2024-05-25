#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include "mainMenu.h"
#include "colorMenu.h"

using namespace std;

void showMainMenu() {
    int choice;
    bool exit = false;

    while (!exit) {
        system("cls");
        cout << "������� ����:" << endl;
        cout << "................................................." << endl;
        cout << "1. ����" << endl;
        cout << "2. ��������� �������� �������" << endl;
        cout << "3. �������" << endl;
        cout << "4. �����" << endl;
        cout << "................................................." << endl;
        cout << "�������� ����� ����: ";
        cin >> choice;

        switch (choice) {
            case 1:
                // ����
                break;
            case 2:
                showColorMenu();
                break;
            case 3:
                cout << "���������� ���������� � ����������." << endl;
                break;
            case 4:
                exit = true;
                break;
            default:
                cout << "�������� �����. ���������� �����." << endl;

                // cin.clear(); // ������� ��������� ��������� �����
                // cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ������� ����� �����
                // system("pause"); // ���������������� ���������� ���������, ����� ������������ ��� ��������� ��������� �� ������
        }
    }
}
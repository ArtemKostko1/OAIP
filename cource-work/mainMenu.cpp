#include <iostream>
#include <thread>
#include <vector>
#include "visitor.h"
#include "mainMenu.h"
#include "colorMenu.h"
#include "skiResortMenu.h"
#include "fileService.h"
#include "vectorService.h"

using namespace std;

void mainMenu() {
    vector<Visitor> visitors;
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
            {
                skiResortMenu();
                break;
            }
            case 2:
            {
                colorMenu();
                break;
            }
            case 3:
            {
                bool referenceExit = false;
                while (!referenceExit)
                {
                    system("cls");
                    cout << "................................................." << endl;
                    cout << "�����������: ������ ���� ������������" << endl;
                    cout << "������: 314371" << endl;
                    cout << "�������������: �������������� ������� � ����������" << endl;
                    cout << "�����, �����, 2024" << endl;
                    cout << "................................................." << endl;
                    cout << "������� 0 ��� ������: ";
                    
                    int input;
                    if (cin >> input && input == 0)
                    {
                        referenceExit = true;
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
                break;
            }
            case 4:
            {
                writeVisitorsToFile();

                exit = true;
                break;
            }
            default:
            {
                cout << "�������� ����. ��������..." << endl;
                cin.clear(); // ������� ���������� ��������� �����
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ������� ����� �����
                this_thread::sleep_for(chrono::milliseconds(1500)); // �������� ����������, ����� ������������ ������ ��������� �� ������
            }
        }
    }
}
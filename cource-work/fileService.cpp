#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include "fileService.h"
#include "vectorService.h"
#include "visitor.h"

using namespace std;

const string fileName = "visitorsList.txt";

// ������� ��� ���������� ������ �� �����
void readVisitorsFromFile() {
	vector<Visitor> visitors;
	ifstream inputFile(fileName);

    // �������� ������������� �����
    if (!inputFile.is_open()) {

        ofstream createdFile(fileName);
        if (!createdFile) {
            cerr << "������ ��� �������� �����: " << fileName << endl;
        }
        createdFile.close();
        setAllVisitors(visitors);
    }

    string line;
    Visitor element;
    while (getline(inputFile, line)) {
        if (line == "{") {
            // ������ ������ ��������
            element.clear();
        }
        else if (line == "}") {
            // ����� �������� ��������
            visitors.push_back(element);
        }
        else {
            // ���������� ���� � ������� �������
            element.push_back(line);
        }
    }
    inputFile.close();

    setAllVisitors(visitors);
}

// ������� ��� ������ ������ � ����
void writeVisitorsToFile() {
    vector<Visitor>& visitors = getAllVisitors();

    ofstream outputFile(fileName);
    if (outputFile.is_open()) {
        for (const auto& visitor : visitors) {
            outputFile << visitor.name << endl
                << visitor.height << endl
                << visitor.weight << endl
                << visitor.footSize << endl
                << visitor.documentNumber << endl
                << visitor.phoneNumber << endl
                << visitor.rentalKit << endl
                << visitor.rentalTime << endl
                << visitor.rentalPeriodStart << endl
                << visitor.rentalPeriodEnd << endl
                << "***" << endl; // �����������
        }
        outputFile.close();
    }
    else {
        cerr << "Error writing to file: " << fileName << endl;
    }
}
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include "fileService.h"
#include "visitor.h"

using namespace std;

const string fileName = "visitorsList.txt";

// ������� ��� ���������� ������ �� ����� � �������� ������ Visitor
vector<Visitor> readVisitorsFromFile() {
	vector<Visitor> visitors;
	ifstream inputFile(fileName);

    if (!inputFile.is_open()) {
        ofstream newFile(fileName);
        if (newFile.is_open()) {
            newFile.close();
        }
        else {
            cerr << "Error creating file: " << fileName << endl;
            return visitors; // ����������� ������� �������
        }
    }
    else {
        Visitor visitor;
        while (inputFile >> visitor.name >> visitor.height >> visitor.weight
            >> visitor.footSize >> visitor.documentNumber >> visitor.phoneNumber
            >> visitor.rentalKit >> visitor.rentalTime
            >> visitor.rentalPeriodStart >> visitor.rentalPeriodEnd) {
            visitors.push_back(visitor);
        }
        inputFile.close();
    }

    return visitors;
}

// ������� ��� ������ ������ � ����
void writeVisitorsToFile(const vector<Visitor>& visitors) {
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
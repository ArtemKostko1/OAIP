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

// Функция для считывания данных из файла
void readVisitorsFromFile() {
	vector<Visitor> visitors;
	ifstream inputFile(fileName);

    // Проверка существования файла
    if (!inputFile.is_open()) {

        ofstream createdFile(fileName);
        if (!createdFile) {
            cerr << "Ошибка при создании файла: " << fileName << endl;
        }
        createdFile.close();
        setAllVisitors(visitors);
    }

    string line;
    Visitor element;
    while (getline(inputFile, line)) {
        if (line == "{") {
            // Начало нового элемента
            element.clear();
        }
        else if (line == "}") {
            // Конец текущего элемента
            visitors.push_back(element);
        }
        else {
            // Добавление поля в текущий элемент
            element.push_back(line);
        }
    }
    inputFile.close();

    setAllVisitors(visitors);
}

// Функция для записи данных в файл
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
                << "***" << endl; // Разделитель
        }
        outputFile.close();
    }
    else {
        cerr << "Error writing to file: " << fileName << endl;
    }
}
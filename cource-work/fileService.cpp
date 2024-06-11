#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include <iostream>
#include <sstream>
#include <iomanip>
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
    if (inputFile.is_open()) {
        while (!inputFile.eof()) {
            Visitor visitor;

            inputFile >> visitor.id;
            inputFile.ignore(); // Игнорирование символа новой строки
            getline(inputFile, visitor.name);
            inputFile >> visitor.height;
            inputFile >> visitor.weight;
            inputFile >> visitor.footSize;
            inputFile.ignore();
            getline(inputFile, visitor.documentNumber);
            getline(inputFile, visitor.phoneNumber);
            getline(inputFile, visitor.rentalKit);
            inputFile >> visitor.rentalTime;
            inputFile.ignore();

            // Считывание полей rentalPeriodStart и rentalPeriodEnd и преобразование их в тип time_t
            string timeString;
            tm timeinfo = {};
            istringstream ss;
            
            getline(inputFile, timeString);
            ss.str(timeString);
            ss >> get_time(&timeinfo, "%d.%m.%Y %H:%M:%S");
            visitor.rentalPeriodStart = mktime(&timeinfo);

            getline(inputFile, timeString);
            ss.clear();
            ss.str(timeString);
            ss >> get_time(&timeinfo, "%d.%m.%Y %H:%M:%S");
            visitor.rentalPeriodEnd = mktime(&timeinfo);

            string delimiter;
            getline(inputFile, delimiter); // Считываем разделитель "***"
            if (delimiter == "***") {
                visitors.push_back(visitor);
            }
            else {
                cerr << "Invalid file format." << endl;
                break;
            }
        }
        inputFile.close();
        setAllVisitors(visitors);
    }
    else {
        ofstream createdFile(fileName);
        if (!createdFile) {
            cerr << "Ошибка при создании файла: " << fileName << endl;
        }
        createdFile.close();
        setAllVisitors(visitors);
    }
}

// Функция для записи данных в файл
void writeVisitorsToFile() {
    vector<Visitor>& visitors = getAllVisitors();

    ofstream outputFile(fileName);
    if (outputFile.is_open()) {
        for (const auto& visitor : visitors) {
            outputFile
            << visitor.id << endl
            << visitor.name << endl
            << visitor.height << endl
            << visitor.weight << endl
            << visitor.footSize << endl
            << visitor.documentNumber << endl
            << visitor.phoneNumber << endl
            << visitor.rentalKit << endl
            << visitor.rentalTime << endl;

            // Преобразование и запись в файл полей rentalPeriodStart и rentalPeriodEnd
            char buffer[80];
            struct tm* timeinfo;

            timeinfo = localtime(&visitor.rentalPeriodStart);
            strftime(buffer, 80, "%d.%m.%Y %H:%M:%S", timeinfo);
            outputFile << buffer << endl;

            timeinfo = localtime(&visitor.rentalPeriodEnd);
            strftime(buffer, 80, "%d.%m.%Y %H:%M:%S", timeinfo);
            outputFile << buffer << endl;

            outputFile  << "***" << endl; // Разделитель
        }
        outputFile.close();
    }
    else {
        cerr << "Error writing to file: " << fileName << endl;
    }
}
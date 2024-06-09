#define _CRT_SECURE_NO_WARNINGS
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
    if (inputFile.is_open()) {
        while (!inputFile.eof()) {
            Visitor visitor;

            getline(inputFile, visitor.name);
            inputFile >> visitor.height;
            inputFile >> visitor.weight;
            inputFile >> visitor.footSize;
            inputFile.ignore(); // Игнорируем символ новой строки
            getline(inputFile, visitor.documentNumber);
            getline(inputFile, visitor.phoneNumber);
            getline(inputFile, visitor.rentalKit);
            inputFile >> visitor.rentalTime;
            inputFile >> visitor.rentalPeriodStart;
            inputFile >> visitor.rentalPeriodEnd;
            inputFile.ignore(); // Игнорируем символ новой строки

            string delimiter;
            getline(inputFile, delimiter); // Считываем разделитель ""
            if (delimiter == "***") {
                addVisitor(visitor);
            }
            else {
                cerr << "Invalid file format." << endl;
                break;
            }
        }
        inputFile.close();

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
            << visitor.name << endl
            << visitor.height << endl
            << visitor.weight << endl
            << visitor.footSize << endl
            << visitor.documentNumber << endl
            << visitor.phoneNumber << endl
            << visitor.rentalKit << endl
            << visitor.rentalTime << endl;

            // Преобразование и запись времени начала аренды
            tm* start_tm = localtime(&visitor.rentalPeriodStart);
            char start_buffer[6];
            strftime(start_buffer, sizeof(start_buffer), "%H:%M", start_tm);
            outputFile << start_buffer << endl;

            // Преобразование и запись времени окончания аренды
            tm* end_tm = localtime(&visitor.rentalPeriodEnd);
            char end_buffer[6];
            strftime(end_buffer, sizeof(end_buffer), "%H:%M", end_tm);
            outputFile << end_buffer << endl;

            outputFile  << "***" << endl; // Разделитель
        }
        outputFile.close();
    }
    else {
        cerr << "Error writing to file: " << fileName << endl;
    }
}
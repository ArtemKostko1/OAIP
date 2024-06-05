#include <iostream>
#include <vector>
#include <string>
#include "vectorService.h"
#include "visitor.h"

// Статический вектор для хранения всех объектов Visitor
static vector<Visitor> allVisitors;

// Функция для возврата списка всех объектов типа Visitor
vector<Visitor> getAllVisitors() {
    return allVisitors;
}

// Функция для вывода на консоль всех элементов списка
void printVisitorList(const vector<Visitor>& visitors) {
    for (const auto& visitor : visitors) {
        cout << "Name: " << visitor.name << ", Document: " << visitor.documentNumber << endl;
        // Выводите остальные поля по аналогии
    }
}

// Функция для добавления нового элемента в список
void addVisitor(vector<Visitor>& visitors, const Visitor& newVisitor) {
    visitors.push_back(newVisitor);
}

// Функция для редактирования элемента по ключу documentNumber
void editVisitorByDocumentNumber(vector<Visitor>& visitors, const string& documentNumber, const Visitor& updatedVisitor) {
    for (auto& visitor : visitors) {
        if (visitor.documentNumber == documentNumber) {
            visitor = updatedVisitor;
            break;
        }
    }
}

// Функция для удаления элемента по ключу documentNumber
void removeVisitorByDocumentNumber(vector<Visitor>& visitors, const string& documentNumber) {
    visitors.erase(remove_if(visitors.begin(), visitors.end(),
        documentNumber{
            return visitor.documentNumber == documentNumber;
        }),
        visitors.end());
}
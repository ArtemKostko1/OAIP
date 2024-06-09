#include <iostream>
#include <vector>
#include <string>
#include "vectorService.h"
#include "visitor.h"

// Статический вектор для хранения всех объектов Visitor
static vector<Visitor> globalVisitors;

// Функция для установки списка всех посетителей
void setAllVisitors(const vector<Visitor>& visitors) {
    globalVisitors = visitors;
}

// Функция для возврата списка всех объектов типа Visitor
vector<Visitor>& getAllVisitors() {
    return globalVisitors;
}

// Функция для вывода на консоль всех элементов списка
void printVisitorList() {
    Visitor visitor;
    for (const auto& visitorItem : globalVisitors) {
        cout << visitor.toString() << endl;
    }
}

// Функция для добавления нового элемента в список
void addVisitor(const Visitor& newVisitor) {
    globalVisitors.push_back(newVisitor);
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
//void removeVisitorByDocumentNumber(vector<Visitor>& visitors, const string& documentNumber) {
//    visitors.erase(remove_if(visitors.begin(), visitors.end(),
//        documentNumber{
//            return visitor.documentNumber == documentNumber;
//        },
//        visitors.end());
//}
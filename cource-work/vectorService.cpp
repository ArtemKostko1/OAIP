#include <iostream>
#include <vector>
#include <string>
#include "vectorService.h"
#include "visitor.h"

// ����������� ������ ��� �������� ���� �������� Visitor
static vector<Visitor> globalVisitors;

// ������� ��� ��������� ������ ���� �����������
void setAllVisitors(const vector<Visitor>& visitors) {
    globalVisitors = visitors;
}

// ������� ��� �������� ������ ���� �������� ���� Visitor
vector<Visitor>& getAllVisitors() {
    return globalVisitors;
}

// ������� ��� ��������� �������� �� ������ ���������
Visitor& getVisitorByDocumentNumber(const string& documentNumber) {
    for (Visitor& visitor : globalVisitors) {
        if (visitor.documentNumber == documentNumber) {
            return visitor;
        }
    }
    throw std::invalid_argument("���������� � ������ ������� ��������� �� ������");
}

// ������� ��� ������ �� ������� ���� ��������� ������
void printVisitorList() {
    for (const auto& visitorItem : globalVisitors) {
        cout << visitorItem.toString() << "\n" << endl;
    }
}

// ������� ��� ���������� ������ �������� � ������
void addVisitor(const Visitor& newVisitor) {
    globalVisitors.push_back(newVisitor);
}

// ������� ��� �������������� �������� �� ����� documentNumber
void editVisitorByDocumentNumber(vector<Visitor>& visitors, const string& documentNumber, const Visitor& updatedVisitor) {
    for (auto& visitor : visitors) {
        if (visitor.documentNumber == documentNumber) {
            visitor = updatedVisitor;
            break;
        }
    }
}

// ������� ��� �������� �������� �� ����� documentNumber
//void removeVisitorByDocumentNumber(vector<Visitor>& visitors, const string& documentNumber) {
//    visitors.erase(remove_if(visitors.begin(), visitors.end(),
//        documentNumber{
//            return visitor.documentNumber == documentNumber;
//        },
//        visitors.end());
//}
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

// ������� ��� ������ �� ������� ���� ��������� ������
void printVisitorList(const vector<Visitor>& visitors) {
    for (const auto& visitor : visitors) {
        cout << "Name: " << visitor.name << ", Document: " << visitor.documentNumber << endl;
        // �������� ��������� ���� �� ��������
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
#include <iostream>
#include <vector>
#include <string>
#include "vectorService.h"
#include "visitor.h"

// ����������� ������ ��� �������� ���� �������� Visitor
static vector<Visitor> allVisitors;

// ������� ��� �������� ������ ���� �������� ���� Visitor
vector<Visitor> getAllVisitors() {
    return allVisitors;
}

// ������� ��� ������ �� ������� ���� ��������� ������
void printVisitorList(const vector<Visitor>& visitors) {
    for (const auto& visitor : visitors) {
        cout << "Name: " << visitor.name << ", Document: " << visitor.documentNumber << endl;
        // �������� ��������� ���� �� ��������
    }
}

// ������� ��� ���������� ������ �������� � ������
void addVisitor(vector<Visitor>& visitors, const Visitor& newVisitor) {
    visitors.push_back(newVisitor);
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
void removeVisitorByDocumentNumber(vector<Visitor>& visitors, const string& documentNumber) {
    visitors.erase(remove_if(visitors.begin(), visitors.end(),
        documentNumber{
            return visitor.documentNumber == documentNumber;
        }),
        visitors.end());
}
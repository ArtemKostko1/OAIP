#include <iostream>
#include <vector>
#include <string>
#include "vectorService.h"
#include "visitor.h"


// ������� ��� ������ �� ������� ���� ��������� ������
void printVisitorList(const std::vector<Visitor>& visitors) {
    for (const auto& visitor : visitors) {
        std::cout << "Name: " << visitor.name << ", Document: " << visitor.documentNumber << std::endl;
        // �������� ��������� ���� �� ��������
    }
}

// ������� ��� ���������� ������ �������� � ������
void addVisitor(std::vector<Visitor>& visitors, const Visitor& newVisitor) {
    visitors.push_back(newVisitor);
}

// ������� ��� �������������� �������� �� ����� documentNumber
void editVisitorByDocumentNumber(std::vector<Visitor>& visitors, const std::string& documentNumber, const Visitor& updatedVisitor) {
    for (auto& visitor : visitors) {
        if (visitor.documentNumber == documentNumber) {
            visitor = updatedVisitor;
            break;
        }
    }
}

// ������� ��� �������� �������� �� ����� documentNumber
void removeVisitorByDocumentNumber(std::vector<Visitor>& visitors, const std::string& documentNumber) {
    visitors.erase(std::remove_if(visitors.begin(), visitors.end(),
        documentNumber{
            return visitor.documentNumber == documentNumber;
        }),
        visitors.end());
}
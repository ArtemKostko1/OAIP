#pragma once
#include <vector>
#include <string>
#include "visitor.h"
#ifndef VECTOR_SERVICE
#define VECTOR_SERVICE

using namespace std;

// ������� ��� ��������� ������ ���� �����������
void setAllVisitors(const vector<Visitor>& visitors);

// ������� ��� ��������� ���� ��������� ������
vector<Visitor>& getAllVisitors();

// ������� ��� ��������� �������� �� ������ ���������
Visitor& getVisitorByDocumentNumber(const string& documentNumber);

// ������� ��� ������ �� ������� ���� ��������� ������
void printVisitorList();

// ������� ��� ���������� ������ �������� � ������
void addVisitor(Visitor& newVisitor);

// ������� ��� �������������� �������� �� ����� documentNumber
void editVisitorByDocumentNumber(const int& visitorId, const Visitor& updatedVisitor);

// ������� ��� �������� �������� �� ����� documentNumber
void removeVisitorByDocumentNumber(const int& visitorId);

#endif
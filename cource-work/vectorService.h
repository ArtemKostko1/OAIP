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

// ������� ��� �������������� �������� �� ��������������
void editVisitorById(const int& visitorId, const Visitor& updatedVisitor);

// ������� ��� �������� �������� �� ��������������
void removeVisitorById(const int& visitorId);

#endif
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
//Visitor& getVisitorByDocumentNumber(const string& documentNumber);

// ������� ��� ��������� �������� �� ��������������
Visitor& getVisitorById(const int& visitorId);

// ������� ��� ������ �� ������� ���� ��������� ������
void printVisitorList();

// ������� ��� ���������� ������ �������� � ������
void createVisitor(Visitor& newVisitor);

// ������� ��� �������������� �������� �� ��������������
void updateVisitor(const int& visitorId, const Visitor& updatedVisitor);

// ������� ��� �������� �������� �� ��������������
void deleteVisitor(const int& visitorId);

#endif
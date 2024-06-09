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

// ������� ��� ������ �� ������� ���� ��������� ������
void printVisitorList(const vector<Visitor>& visitors);

// ������� ��� ���������� ������ �������� � ������
void addVisitor(const Visitor& newVisitor);

// ������� ��� �������������� �������� �� ����� documentNumber
void editVisitorByDocumentNumber(vector<Visitor>& visitors, const string& documentNumber, const Visitor& updatedVisitor);

// ������� ��� �������� �������� �� ����� documentNumber
//void removeVisitorByDocumentNumber(vector<Visitor>& visitors, const string& documentNumber);

#endif
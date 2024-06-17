#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "vectorService.h"
#include "visitor.h"

using namespace std;

// ����������� ������ ��� �������� ���� �������� Visitor
static vector<Visitor> globalVisitors;

static int autoIncrement;

// ������� ��� ��������� ������ ���� �����������
void setAllVisitors(const vector<Visitor>& visitors) {
	globalVisitors = visitors;

	// ������� �������� ������������� id �������� � ��������� ��� � ���������� ���������� autoIncrement
	if (!globalVisitors.empty()) {
		auto maxElement = max_element(globalVisitors.begin(), globalVisitors.end(),
			[](const Visitor& visitor1, const Visitor& visitor2){
			   return visitor1.id < visitor2.id;
			});
		autoIncrement = maxElement->id;
	}
	else {
		autoIncrement = 0;
	}
}

// ������� ��� �������� ������ ���� �������� ���� Visitor
vector<Visitor>& getAllVisitors() {
	return globalVisitors;
}

// ������� ��� ��������� �������� �� ��������������
Visitor& getVisitorById(const int& visitorId) {
	for (Visitor& visitor : globalVisitors) {
		if (visitor.id == visitorId) {
			return visitor;
		}
	}
	throw invalid_argument("���������� � ������ ��������������� �� ������. ��������...");
}

// ������� ��� ������ �� ������� ���� ��������� ������
void printVisitorList() {
	if (globalVisitors.size() > 0) {
		for (const auto& visitorItem : globalVisitors) {
			cout << visitorItem.toString() << "\n" << endl;
		}
	}
	else {
		cout << "������ ���� \n" << endl;
	}
}

// ������� ��� ���������� ������ �������� � ������
void createVisitor(Visitor& newVisitor) {
	// ��������� �������������� ������ �������� � ��������� ����������� ������������� id
	newVisitor.id = ++autoIncrement;

	globalVisitors.push_back(newVisitor);

}

// ������� ��� �������������� �������� �� ��������������
void updateVisitor(const int& visitorId, const Visitor& updatedVisitor) {
	for (auto& visitor : globalVisitors) {
		if (visitor.id == visitorId) {
			visitor = updatedVisitor;
			break;
		}
	}
}

// ������� ��� �������� �������� �� ��������������
void deleteVisitor(const int& visitorId) {
	globalVisitors.erase(remove_if(globalVisitors.begin(), globalVisitors.end(),
		[&visitorId](const Visitor& visitor) {
			return visitor.id == visitorId;
		}), globalVisitors.end());
}
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "vectorService.h"
#include "visitor.h"

using namespace std;

// Статический вектор для хранения всех объектов Visitor
static vector<Visitor> globalVisitors;

static int autoIncrement;

// Функция для установки списка всех посетителей
void setAllVisitors(const vector<Visitor>& visitors) {
	globalVisitors = visitors;

	// Находит значение максимального id элемента и сохраняет его в глобальную переменную autoIncrement
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

// Функция для возврата списка всех объектов типа Visitor
vector<Visitor>& getAllVisitors() {
	return globalVisitors;
}

// Функция для получения элемента по номеру документа
Visitor& getVisitorByDocumentNumber(const string& documentNumber) {
	for (Visitor& visitor : globalVisitors) {
		if (visitor.documentNumber == documentNumber) {
			return visitor;
		}
	}
	throw invalid_argument("Посетитель с данным номером документа не найден");
}

// Функция для вывода на консоль всех элементов списка
void printVisitorList() {
	for (const auto& visitorItem : globalVisitors) {
		cout << visitorItem.toString() << "\n" << endl;
	}
}

// Функция для добавления нового элемента в список
void addVisitor(Visitor& newVisitor) {
	// Установка идентификатора новому элементу и изменение глобального максимального id
	newVisitor.id = ++autoIncrement;

	globalVisitors.push_back(newVisitor);

}

// Функция для редактирования элемента по идентификатору
void editVisitorById(const int& visitorId, const Visitor& updatedVisitor) {
	for (auto& visitor : globalVisitors) {
		if (visitor.id == visitorId) {
			visitor = updatedVisitor;
			break;
		}
	}
}

// Функция для удаления элемента по идентификатору
void removeVisitorById(const int& visitorId) {
	globalVisitors.erase(remove_if(globalVisitors.begin(), globalVisitors.end(),
		[&visitorId](const Visitor& visitor) {
			return visitor.id == visitorId;
		}), globalVisitors.end());
}
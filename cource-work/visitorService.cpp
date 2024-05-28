#include "Visitor.h"

string Visitor::GetName()
{
	return name;
}

string Visitor::GetDocumentNumber()
{
	return documentNumber;
}

void Visitor::SetName() {
	cout << "................................................." << endl;
	cout << "Введите имя посетителя: ";
	cin >> name;
}

void Visitor::SetDocumentNumber() {
	cout << "................................................." << endl;
	cout << "Введите номер документа: ";
	cin >> documentNumber;
}

void Visitor::addVisitor() {
	Visitor visitor = new Visitor;
}
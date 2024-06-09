#define _CRT_SECURE_NO_WARNINGS
#include "visitor.h"
#include <ctime>

//void Visitor::createVisitor(
//	string name,
//	float height,
//	float weight,
//	float footSize,
//	string documentNumber, 
//	string phoneNumber, 
//	string rentalKit,
//	int rentalTime,
//	time_t rentalPeriodStart,
//	time_t rentalPeriodEnd)
//{
//	this->name = name;
//	this->height = height;
//	this->weight = weight;
//	this->footSize = footSize;
//	this->documentNumber = documentNumber;
//	this->rentalKit = rentalKit;
//	this->rentalTime = rentalTime;
//	time(&this->rentalPeriodStart);
//	this->rentalPeriodEnd = this->rentalPeriodStart + (rentalTime * 3600);
//}

//void Visitor::editVisitor()
//{
//
//}
//
//void Visitor::deleteVisitor() {
//
//}

string Visitor::toString() {
	return "Имя: " + this->name + "\n" +
		"Рост: " + to_string(this->height) + "\n" +
		"Вес: " + to_string(this->weight) + "\n" +
		"Размер обуви: " + to_string(this->footSize) + "\n" +
		"Номер документа: " + this->documentNumber + "\n" +
		"Тип арендуемого оборудования: " + this->rentalKit + "\n" +
		"Время аренды: " + to_string(this->rentalTime) + "\n" +
		"Время начала аренды: " + ctime(&this->rentalPeriodStart) +
		"Время окончания аренды: " + ctime(&this->rentalPeriodEnd);
}
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
	return "���: " + this->name + "\n" +
		"����: " + to_string(this->height) + "\n" +
		"���: " + to_string(this->weight) + "\n" +
		"������ �����: " + to_string(this->footSize) + "\n" +
		"����� ���������: " + this->documentNumber + "\n" +
		"��� ����������� ������������: " + this->rentalKit + "\n" +
		"����� ������: " + to_string(this->rentalTime) + "\n" +
		"����� ������ ������: " + ctime(&this->rentalPeriodStart) +
		"����� ��������� ������: " + ctime(&this->rentalPeriodEnd);
}
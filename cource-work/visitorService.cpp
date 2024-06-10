#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <ctime>
#include <sstream>
#include "visitor.h"

string Visitor::toString() const {
	char prsBuffer[80];
	char rpeBuffer[80];
	struct tm* rpsTimeInfo;
	struct tm* rpeTimeInfo;

	rpsTimeInfo = localtime(&this->rentalPeriodStart);
	strftime(prsBuffer, 80, "%d.%m.%Y %H:%M:%S", rpsTimeInfo);

	rpeTimeInfo = localtime(&this->rentalPeriodEnd);
	strftime(rpeBuffer, 80, "%d.%m.%Y %H:%M:%S", rpeTimeInfo);

	stringstream ssHeight;
	ssHeight << fixed << setprecision(1) << this->height;
	string heightStr = ssHeight.str();

	stringstream ssWeight;
	ssWeight << fixed << setprecision(1) << this->weight;
	string weightStr = ssWeight.str();

	stringstream ssFootSize;
	ssFootSize << fixed << setprecision(1) << this->footSize;
	string footSizeStr = ssFootSize.str();

	return "Имя: " + this->name + "\n" +
		"Рост: " + heightStr + " см \n" +
		"Вес: " + weightStr + " кг \n" +
		"Размер обуви: " + footSizeStr + "\n" +
		"Номер документа: " + this->documentNumber + "\n" +
		"Тип арендуемого оборудования: " + this->rentalKit + "\n" +
		"Время аренды: " + to_string(this->rentalTime) + " часа/ов \n" +
		"Время начала аренды: " + string(prsBuffer) + "\n" +
		"Время окончания аренды: " + string(rpeBuffer);
}
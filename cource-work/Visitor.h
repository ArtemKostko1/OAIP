#pragma once
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

struct Visitor
{
public:
	string name;
	float height;
	float weight;
	float footSize;
	string documentNumber;
	string phoneNumber;
	string rentalKit;
	string rentalTime;
	time_t rentalPeriodStart;
	time_t rentalPeriodEnd;

	//void createVisitor(string, float, float, float, string, string, string, int, time_t, time_t);

	//void editVisitor();

	//void deleteVisitor();

	string toString();
};
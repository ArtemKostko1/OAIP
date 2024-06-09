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
	int rentalTime;
	time_t rentalPeriodStart;
	time_t rentalPeriodEnd;

	string toString();
};
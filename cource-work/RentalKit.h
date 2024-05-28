#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class RentalKit
{
private:
	vector<string> rentalItems = { "Лыжный комплект", "Комплект для сноуборда" };

public:
	RentalKit() {

	}

	vector<string> getRentalItems() const;
};


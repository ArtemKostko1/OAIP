#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class RentalKit
{
private:
	vector<string> rentalItems = { "������ ��������", "�������� ��� ���������" };

public:
	RentalKit() {

	}

	vector<string> getRentalItems() const;
};


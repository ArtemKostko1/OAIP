#pragma once
#include <iostream>
#include <string>

using namespace std;

class Visitor
{
	public:
		string name;
		string documentNumber;

		Visitor() {

		}

		string GetName();
		void printName();

		string GetDocumentNumber();
		void printDocumentNumber();

		void SetName();
		void SetDocumentNumber();

		void addVisitor();
};


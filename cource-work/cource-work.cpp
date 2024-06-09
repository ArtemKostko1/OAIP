#include <iostream>
#include <vector>
#include "mainMenu.h"
#include "fileService.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru_RU"); //Символы русского алфавита в консоли

	// Считывание данных из файла
	readVisitorsFromFile();

	// Вызов главного меню
	mainMenu();

	return 0;
}
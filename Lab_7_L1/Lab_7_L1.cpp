#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct Student
{
public:
	string name;
	int groupNumber;
	float physics;
	float math;
	float information;
	float gpa;

	string toString() const {
		stringstream ssPhysics;
		ssPhysics << fixed << setprecision(1) << this->physics;
		string physicsStr = ssPhysics.str();

		stringstream ssMath;
		ssMath << fixed << setprecision(1) << this->math;
		string mathStr = ssMath.str();

		stringstream ssInformation;
		ssInformation << fixed << setprecision(1) << this->information;
		string informationStr = ssInformation.str();

		stringstream ssGpa;
		ssGpa << fixed << setprecision(1) << this->gpa;
		string gpaStr = ssGpa.str();

		return
			"Имя: " + this->name + "\n" +
			"Номер группы: " + this->groupNumber + " \n" +
			"Физика: " + physicsStr + " \n" +
			"Математика: " + mmathStrath + "\n" +
			"Информатика: " + this->informationStr + "\n" +
			"Средний балл: " + this->gpaStr + "\n";
	}
};

const string fileName = "_studentList.txt";

void createFile() {
	ofstream file(fileName);
	if (file.is_open()) {
		file.close();
		cout << "Файл " << fileName << " успешно создан. Ожидайте...";
		this_thread::sleep_for(chrono::milliseconds(2000));
	}
	else {
		cout << "Не удалось создать файл " << fileName <<;
	}
}

void mainMenu() {
	vector<Visitor> visitors;
	int choice;
	bool exit = false;

	while (!exit) {
		system("cls");
		cout << "Главное меню:" << endl;
		cout << "................................................." << endl;
		cout << "1. Создание файла" << endl;
		cout << "2. Просмотр списка" << endl;
		cout << "3. Добавление студента" << endl;
		cout << "4. Решение индивидуального задания" << endl;
		cout << "0. Выход" << endl;
		cout << "................................................." << endl;
		cout << "Выберите пункт меню: ";
		cin >> choice;

		switch (choice) {
		case 1:
		{
			ofstream createdFile(fileName);
			break;
		}
		case 2:
		{

			break;
		}
		case 3:
		{
			bool referenceExit = false;
			while (!referenceExit)
			{
				system("cls");
				cout << "................................................." << endl;
				cout << "Тема: Структура списка посетителей горнолыжного комплекса" << endl;
				cout << "Разработчик: Костко Артём Владимирович" << endl;
				cout << "Группа: 314371" << endl;
				cout << "Специальность: Информационные системы и технологии" << endl;
				cout << "БГУИР, Минск, 2024" << endl;
				cout << "................................................." << endl;
				cout << "Введите 0 для выхода: ";

				int input;
				if (cin >> input && input == 0)
				{
					referenceExit = true;
					break;
				}
				else
				{
					cout << "Неверный ввод. Ожидайте..." << endl;
					cin.clear(); // Очистка ошибочного состояния ввода
					cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка буфер ввода
					this_thread::sleep_for(chrono::milliseconds(1500)); // Задержка приложения, чтобы пользователь увидел сообщение об ошибке
				}
			}
			break;
		}
		case 0:
		{
			writeVisitorsToFile();

			exit = true;
			break;
		}
		default:
		{
			cout << "Неверный ввод. Ожидайте..." << endl;
			cin.clear(); // Очистка ошибочного состояния ввода
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка буфер ввода
			this_thread::sleep_for(chrono::milliseconds(1500)); // Задержка приложения, чтобы пользователь увидел сообщение об ошибке
		}
		}
	}
}

int main()
{
	mainMenu();
}
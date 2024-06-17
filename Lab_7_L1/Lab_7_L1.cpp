#include <iostream>
#include <fstream>
#include <thread>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <cctype>
#include <algorithm>

using namespace std;

struct Student
{
public:
	string name;
	int groupNumber;
	int physics;
	int math;
	int information;
	float gpa;

	string toString() const {
		stringstream ssGpa;
		ssGpa << fixed << setprecision(1) << this->gpa;
		string gpaStr = ssGpa.str();

		return
			"Имя: " + this->name + "\n" +
			"Номер группы: " + to_string(this->groupNumber) + " \n" +
			"Физика: " + to_string(this->physics) + " \n" +
			"Математика: " + to_string(this->math) + "\n" +
			"Информатика: " + to_string(this->information) + "\n" +
			"Средний балл: " + gpaStr + "\n";
	}
};

// Статический вектор для хранения всех объектов Student
static vector<Student> globalStudents;

// Функция для возврата списка всех объектов типа Student
vector<Student>& getAllStudents() {
	return globalStudents;
}

// Функция для установки списка всех посетителей
void setAllVisitors(const vector<Student>& students) {
	globalStudents = students;
}

// Функция для добавления нового элемента в список
void createStudent(Student& newStudent) {
	globalStudents.push_back(newStudent);
}

const string fileName = "_studentList.txt";

void createFile() {
	system("cls");
	ofstream file(fileName);
	if (file.is_open()) {
		file.close();
		cout << "Файл " << fileName << " успешно создан. Ожидайте...";
		this_thread::sleep_for(chrono::milliseconds(3000));
	}
	else {
		cout << "Не удалось создать файл " << fileName;
	}
}

// Функция для вывода на консоль всех элементов списка
void printStudentList() {
	if (globalStudents.size() > 0) {
		for (const auto& studentItem : globalStudents) {
			cout << studentItem.toString() << endl;
		}
	}
	else {
		cout << "Список пуст \n" << endl;
	}
}

// Функция для считывания данных из файла
void readStudentsFromFile() {
	vector<Student> students;
	ifstream inputFile(fileName);

	// Проверка существования файла
	if (inputFile.is_open()) {
		while (!inputFile.eof()) {
			Student student;

			getline(inputFile, student.name);
			inputFile >> student.groupNumber;
			inputFile >> student.physics;
			inputFile >> student.math;
			inputFile >> student.information;
			inputFile >> student.gpa;
			inputFile.ignore(); // Игнорирование символа новой строки после считывания числа

			string delimiter;
			getline(inputFile, delimiter); // Считываем разделитель "***"
			if (delimiter == "***") {
				students.push_back(student);
			}
			else {
				cerr << "Invalid file format." << endl;
				break;
			}
		}
		inputFile.close();
		setAllVisitors(students);
	}
	else {
		cerr << "Ошибка при считывании файла. Сначла создайте его. Ожидайте..." << endl;
		this_thread::sleep_for(chrono::milliseconds(3000));
	}
}

// Функция для записи данных в файл
void writeStudentsToFile() {
	vector<Student>& students = getAllStudents();

	ofstream outputFile(fileName);
	if (outputFile.is_open()) {
		for (const auto& student : students) {
			outputFile
				<< student.name << endl
				<< student.groupNumber << endl
				<< student.physics << endl
				<< student.math << endl
				<< student.information << endl
				<< student.gpa << endl
				<< "***" << endl; // Разделитель
		}
		outputFile.close();
	}
	else {
		cerr << "Error writing to file: " << fileName << endl;
	}
}

int chekInput() {
	int value;
	while (true) {
		if ((cin >> value) && (value > 0)) {
			// Введено корректное целое число больше 0, выходим из цикла
			break;
		}
		else {
			// Некорректный ввод или число не больше 0, очищаем флаг ошибки и игнорируем остальной ввод
			cout << "Некорректный ввод или число меньше 0. Введите еще раз: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
	return value;
}

float calculateAverage(int physics, int math, int information) {
	return (physics + math + information) / 3.0f;
}

void ctreateStudent() {
	system("cls");
	Student student;

	cout << "Введите имя: ";
	cin >> student.name;

	cout << "Введите номер группы: ";
	cin >> student.groupNumber;

	cout << "Введите оценку по физике: ";
	student.physics = chekInput();

	cout << "Введите оценку по математике: ";
	student.math = chekInput();

	cout << "Введите оценку по информатике: ";
	student.information = chekInput();

	student.gpa = calculateAverage(student.physics, student.math, student.information);

	createStudent(student);
}

void displayStudents() {
	bool studentListExit = false;
	while (!studentListExit)
	{
		system("cls");
		cout << "СПИСОК ВСЕХ СТУДЕНТОВ" << endl;
		cout << ".................................................\n" << endl;

		printStudentList();

		cout << "................................................." << endl;
		cout << "Введите 0 для выхода: ";

		int exitInput;
		if (cin >> exitInput && exitInput == 0)
		{
			studentListExit = true;
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
}

void individualTask() {
	bool individualTaskExit = false;
	while (!individualTaskExit)
	{
		system("cls");
		int groupNumberInput;
		cout << "Введите номер группы, из которой хотите найти студентов отличников: ";
		cin >> groupNumberInput;

		system("cls");
		cout << "СПИСОК СТУДЕНТОВ" << endl;
		cout << "................................................." << endl;

		vector<Student>& students = getAllStudents();
		for (const Student& student : students) {
			if (
				student.groupNumber == groupNumberInput && 
				student.physics >= 9.0 && student.math >= 9.0 && 
				student.information >= 9.0) 
			{
				cout << student.toString() + "\n";
			}
		}

		cout << "................................................." << endl;
		cout << "Введите 0 для выхода: " << endl;

		int exitInput;
		if (cin >> exitInput && exitInput == 0)
		{
			individualTaskExit = true;
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
}

void mainMenu() {
	vector<Student> studens;
	int choice;
	bool exit = false;

	while (!exit) {
		system("cls");
		cout << "Главное меню:" << endl;
		cout << "................................................." << endl;
		cout << "1. Создание файла" << endl;
		cout << "2. Просмотр студентов" << endl;
		cout << "3. Добавление студента" << endl;
		cout << "4. Решение индивидуального задания" << endl;
		cout << "0. Выход" << endl;
		cout << "................................................." << endl;
		cout << "Выберите пункт меню: ";
		cin >> choice;

		switch (choice) {
		case 1:
		{
			createFile();
			break;
		}
		case 2:
		{
			displayStudents();
			break;
		}
		case 3:
		{
			ctreateStudent();
			break;
		}
		case 4:
		{
			individualTask();
			break;
		}
		case 0:
		{
			writeStudentsToFile();

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
	system("CHCP 1251");

	readStudentsFromFile();

	mainMenu();

	return 0;
}
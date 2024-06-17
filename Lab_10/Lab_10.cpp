#include <iostream>
#include <thread>
#include <ctime>

using namespace std;

struct Spis2 {
	int info;
	Spis2* next, * prev;
} *begin, * end, * t;

//------------------- Создание первого элемента -----------------------------
void create_Spis2(Spis2** b, Spis2** e, int in) {
	t = new Spis2;
	t->info = in;
	t->next = t->prev = NULL;
	*b = *e = t;
}
//------------------- Добавление элемента в список --------------------------
void add_Spis2(int kod, Spis2** b, Spis2** e, int in) {
	t = new Spis2;
	t->info = in;
	if (kod == 0) {
		t->prev = NULL;
		t->next = *b;
		(*b)->prev = t;
		*b = t;
	}
	else {
		t->next = NULL;
		t->prev = *e;
		(*e)->next = t;
		*e = t;
	}
}
// --------------------- Удаление элемента ---------------------
void deleteFirst(Spis2** p) {
	t = *p;
	*p = (*p)->next;
	delete t;
}
//--------------------- Просмотр элементов списка ---------------------------
void view_Spis2(int kod, Spis2* t) {
	while (t != NULL) {
		cout << t->info << endl;
		if (kod == 0) t = t->next;
		else t = t->prev;
	}
}

void del_All(Spis2** p) {
	while (*p != NULL) {
		t = *p;
		*p = (*p)->next;
		delete t;
	}
}

void sort_p(Spis2** p) {
	Spis2* t = NULL, * t1, * r;
	if ((*p)->next->next == NULL) return;
	do {
		for (t1 = *p; t1->next->next != t; t1 = t1->next)
			if (t1->next->info > t1->next->next->info) {
				r = t1->next->next;
				t1->next->next = r->next;
				r->next = t1->next;
				t1->next = r;
			}
		t = t1->next;
	} while ((*p)->next->next != t);
}

void sort_info(Spis2* p) {
	Spis2* t = NULL, * t1;
	int r;
	do {
		for (t1 = p; t1->next != t; t1 = t1->next)
			if (t1->info > t1->next->info) {
				r = t1->info;
				t1->info = t1->next->info;
				t1->next->info = r;
			}
		t = t1;
	} while (p->next != t);
}

void individualTask(Spis2** b, Spis2** e) {
	Spis2* current = *b;
	Spis2* prev = NULL;
	int count = 0;

	while (current != NULL) {
		count++;
		if (count % 2 == 0) {
			// Удаление текущего элемента
			if (prev != NULL) {
				prev->next = current->next;
				if (current->next != NULL) {
					current->next->prev = prev;
				}
				else {
					*e = prev; // Обновляем конец, если удаляется последний элемент
				}
			}
			else {
				*b = current->next; // Обновляем начало, если удаляется первый элемент
				if (*b != NULL) {
					(*b)->prev = NULL;
				}
			}
			delete current;
			current = prev ? prev->next : *b;
		}
		else {
			prev = current;
			current = current->next;
		}
	}
	if (*b == NULL) *e = NULL; // Обновляем конец, если очередь пуста
}

void mainMenu() {
	bool exit = false;
	int choice, choice2, i, in, n, out;

	Spis2* begin = NULL;
	Spis2* end = NULL;

	while (!exit) {
		system("cls");
		cout << "Главное меню:" << endl;
		cout << "................................................." << endl;
		cout << "1. Создать список" << endl;
		cout << "2. Добавть в список элемент" << endl;
		cout << "3. Просмотреть список" << endl;
		cout << "4. Удалить список" << endl;
		cout << "5. Сортировка перестановкой двух соседних элементов" << endl;
		cout << "6. Сортировка обменом информацией между текущим и следующим элементами" << endl;
		cout << "7. Решение индивидулаьного задания" << endl;
		cout << "0. Выход" << endl;
		cout << "................................................." << endl;
		cout << "Выберите пункт меню: ";
		cin >> choice;

		switch (choice) {
		case 111: {
			create_Spis2(&begin, &end, -1);
			add_Spis2(1, &begin, &end, 9);
			add_Spis2(1, &begin, &end, 5);
			add_Spis2(1, &begin, &end, 2);
			add_Spis2(1, &begin, &end, 6);
			add_Spis2(1, &begin, &end, -5);
			add_Spis2(1, &begin, &end, 10);

			break;
		}
		case 222:
		{
			create_Spis2(&begin, &end, 1);
			add_Spis2(1, &begin, &end, -4);
			add_Spis2(1, &begin, &end, 10);
			add_Spis2(1, &begin, &end, 2);
			add_Spis2(1, &begin, &end, 6);
			add_Spis2(1, &begin, &end, 6);
			add_Spis2(1, &begin, &end, 5);
			add_Spis2(1, &begin, &end, -2);

			break;
		}
		case 1: {
			if (begin != NULL) {
				cout << "Для начала удалите предудщий список и очистите память. Ожидайте..." << endl;
				this_thread::sleep_for(chrono::milliseconds(2500));
				break;
			}
			cout << "Введите элемент, который будет добавлен в начало списка: ";
			cin >> in;
			create_Spis2(&begin, &end, in);
			cout << "Список создан. Ожидайте..." << endl;
			this_thread::sleep_for(chrono::milliseconds(2500));
			break;
		}
		case 2: {
			if (begin == NULL) {
				cout << "Сначала создайте список." << endl;
				this_thread::sleep_for(chrono::milliseconds(2500));
				break;
			}
			cout << "Введите элемент = ";
			cin >> in;
			cout << "\n0. Добавить в начало. \n1. Добавить в конец." << endl;
			cin >> choice2;
			add_Spis2(choice2, &begin, &end, in);
			if (choice2 == 0)
			{
				t = begin;
				cout << "Элемент добавлен в начало списка. Ожидайте..." << endl;
				this_thread::sleep_for(chrono::milliseconds(2500));
			}
			else {
				t = end;
				cout << "Элемент добавлен в конец списка. Ожидайте..." << endl;
				this_thread::sleep_for(chrono::milliseconds(2500));
			}
			break;
		}
		case 3:
		{
			bool displayListExit = false;
			while (!displayListExit)
			{
				system("cls");
				if (!begin) {
					cout << "Список пуст." << endl;
				}
				cout << "\n0. Посмотреть с начала. \n1. Посмотреть с конца." << endl;
				cin >> choice;
				if (choice == 0) {
					t = begin;
					cout << "Список с начала:" << endl;
				}
				else {
					t = end;
					cout << "Список с конца:" << endl;
				}
				view_Spis2(choice, t);

				cout << "................................................." << endl;
				cout << "Введите 0 для выхода: ";

				int input;
				if (cin >> input && input == 0)
				{
					displayListExit = true;
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
		case 4:
		{
			if (begin != NULL) {
				del_All(&begin);
				cout << "Стек удален с очисткой памяти. Ожидайте..." << endl;
				this_thread::sleep_for(chrono::milliseconds(2500));
			}
			else {
				cout << "Стек пустой. Удаление невозможно. Ожидайте..." << endl;
				this_thread::sleep_for(chrono::milliseconds(2500));
			}

			break;
		}
		case 5:
		{
			if (begin != NULL) {
				add_Spis2(0, &begin, &end, -100);
				sort_p(&begin);
				deleteFirst(&begin);
				cout << "Список был отсортирован. Ожидайте..." << endl;
				this_thread::sleep_for(chrono::milliseconds(2500));
			}
			else {
				cout << "Сортировка невозможна так как список пуст. Ожидайте..." << endl;
				this_thread::sleep_for(chrono::milliseconds(2500));
			}

			break;
		}
		case 6:
		{
			if (begin != NULL) {
				sort_info(begin);
				cout << "Список был отсортирован. Ожидайте..." << endl;
				this_thread::sleep_for(chrono::milliseconds(2500));
			}
			else {
				cout << "Сортировка невозможна так как список пуст. Ожидайте..." << endl;
				this_thread::sleep_for(chrono::milliseconds(2500));
			}
			break;
		}
		case 7:
		{
			if (begin != NULL) {
				individualTask(&begin, &end);
				cout << "Каждый второй элимент удален. Ожидайте..." << endl;
				this_thread::sleep_for(chrono::milliseconds(2500));
			}
			else {
				cout << "Индивидуальное задание невозможно выполнить так как стек пуст." << endl;
				this_thread::sleep_for(chrono::milliseconds(2500));
			}
			break;
		}
		case 0:
		{
			if (begin != NULL)
				del_All(&begin);

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

		mainMenu();

		return 0;
	}
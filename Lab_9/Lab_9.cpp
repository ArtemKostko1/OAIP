#include <iostream>
#include <thread>
#include <ctime> 

using namespace std;

struct Stack {
	int info;
	Stack* next;
} *begin, * t;

//--------------- Функция добавления элемента в Стек ------------------------
Stack* inStack(Stack* p, int in) {
	Stack* t = new Stack;
	t->info = in;
	t->next = p;
	return t;
}

//----------------- Функция просмотра Стека----------------------------------
void view(Stack* p) {
	Stack* t = p;
	while (t != NULL) {
		cout << t->info << endl;
		t = t->next;
	}
	cout << endl;
}

//----------------------- Функция освобождения памяти -----------------------
void del_All(Stack** p) {
	while (*p != NULL) {
		t = *p;
		*p = (*p)->next;
		delete t;
	}
}

int getRandomNumber(int min, int max) {
	int randomNumber = rand() % (max - min + 1) + min;
	return randomNumber;
}

void permutationSort(Stack** p) {
	Stack* t = NULL, * t1, * r;
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

void informationSort(Stack* p) {
	Stack* t = NULL, * t1;
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

Stack* outStack(Stack* p, int* out) {
	Stack* t = p; // Устанавливаем указатель t на вершину p
	*out = p->info;
	p = p->next; // Переставляем вершину p на следующий элемент
	delete t; // Удаляем бывшую вершину t
	return p; // Возвращаем новую вершину p
}

void individualTask(Stack* p) {
	Stack* current = p;
	Stack* prev = NULL;
	int count = 0;

	while (current != NULL) {
		count++;
		if (count % 2 == 0) {
			// Удаление текущего элемента
			if (prev != NULL) {
				prev->next = current->next;
			}
			delete current;
			current = prev->next;
		}
		else {
			prev = current;
			current = current->next;
		}
	}
}

void mainMenu() {
	bool exit = false;
	int choice, i, in, n, kod, out;
	Stack* begin = NULL;
	srand(time(NULL));

	while (!exit) {
		system("cls");
		cout << "Главное меню:" << endl;
		cout << "................................................." << endl;
		cout << "1. Создать стек" << endl;
		cout << "2. Добавть в стек элемент" << endl;
		cout << "3. Просмотреть стек" << endl;
		cout << "4. Удалить стек" << endl;
		cout << "5. Сортировка перестановкой двух соседних элементов" << endl;
		cout << "6. Сортировка обменом информацией между текущим и следующим элементами" << endl;
		cout << "7. Решение индивидулаьного задания" << endl;
		cout << "0. Выход" << endl;
		cout << "................................................." << endl;
		cout << "Выберите пункт меню: ";
		cin >> choice;

		switch (choice) {
			case 1:
			case 2:
			{
				bool addStackExit = false;
				while (!addStackExit)
				{
					system("cls");
					if (choice == 1 && begin != nullptr) {
						cout << "Удалите предудщий стек и очистите память." << endl;
					}
					cout << "Введите количество элементов стека: "; cin >> n;
					for (i = 1; i <= n; i++) {
						in = getRandomNumber(-10, 10);
						begin = inStack(begin, in);
					}

					if (choice == 1)
						cout << "Создано " << n << " случайных элементов." << endl;
					else
						cout << "Добавлено " << n << " случайных элементов." << endl;

					cout << "................................................." << endl;
					cout << "Введите 0 для выхода: ";

					int input;
					if (cin >> input && input == 0)
					{
						addStackExit = true;
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
			case 3:
			{
				bool disolayStackExit = false;
				while (!disolayStackExit)
				{
					system("cls");
					cout << endl << "Элементы стека" << endl;
					cout << ".................................................\n" << endl;

					if (!begin) {
						cout << "Стек пуст." << endl;
					}

					view(begin);

					cout << "................................................." << endl;
					cout << "Введите 0 для выхода: ";

					int input;
					if (cin >> input && input == 0)
					{
						disolayStackExit = true;
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
					begin = inStack(begin, -100);
					permutationSort(&begin);
					begin = outStack(begin, &out);
					cout << "Стек отсортирован. Ожидайте..." << endl;
					this_thread::sleep_for(chrono::milliseconds(2500));
				}
				else {
					cout << "Стек пустой. Сортировка невозможна. Ожидайте..." << endl;
					this_thread::sleep_for(chrono::milliseconds(2500));
				}

				break;
			}
			case 6:
			{
				if (begin != NULL) {
					informationSort(begin);
					cout << "Стек отсортирован. Ожидайте..." << endl;
					this_thread::sleep_for(chrono::milliseconds(2500));
				}
				else {
					cout << "Стек пустой. Сортировка невозможна. Ожидайте..." << endl;
					this_thread::sleep_for(chrono::milliseconds(2500));
				}
				break;
			}
			case 7:
			{
				if (begin != NULL) {
					individualTask(begin);
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
#include <iostream> 
#include <ctime> 
#include <Windows.h>

using namespace std;

struct Stack { 
	int info;
	Stack* next;
} *begin, * t;

//--------------- Функция добавления элемента в Стек ------------------------
Stack* InStack(Stack* p, int in) {
	Stack* t = new Stack;
	t->info = in;
	t->next = p;
	return t;
}
//----------------- Функция просмотра Стека----------------------------------
void View(Stack* p) {
	Stack* t = p;
	while (t != NULL) {
		cout << t->info << endl;
		t = t->next;
	}
	cout << endl;
}
//----------------------- Функция освобождения памяти -----------------------
void Del_All(Stack** p) {
	while (*p != NULL) {
		t = *p;
		*p = (*p)->next;
		delete t;
	}
}

void Sort_p(Stack** p) {
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

void Sort_info(Stack* p) {
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

Stack* OutStack(Stack* p, int* out) {
	Stack* t = p; // Устанавливаем указатель t на вершину p
	*out = p->info;
	p = p->next; // Переставляем вершину p на следующий элемент
	delete t; // Удаляем бывшую вершину t
	return p; // Возвращаем новую вершину p
}

int findMax(Stack* p) {
	Stack* t = p;
	int max = t->info;
	while (t != NULL) {
		if (t->info > max) {
			max = t->info;
		}
		t = t->next;
	}
	return max;
}

void IndividualTask(Stack* p) {
	Stack* begin2 = NULL;
	Stack* t = p;
	Stack* t2 = p;

	int first = t2->info;
	int max = findMax(p);
	int counter= 0;

	if (t->info == max || t->next->info == max) {
		cout << "Количество элементов между вершиной и max = 0" << endl;
		return;
	}

	while (t != NULL) {
		if (max == t->info) {
			counter++;
		}
		t = t->next;
	}

	if (counter >1) {
		cout << "Невозможно выполнить задание, так как найден не один max." << endl;
		return;
	}

	while (t2 != NULL) {
		if (t2->info == first) {
			t2 = t2->next;
			continue;
		}
		if (max != t2->info) {
			begin2 = InStack(begin2, t2->info);
			t2 = t2->next;
		}
		else {
			break;
		}
	}

	cout  <<endl;
	cout << "Новый стек:" << endl;
	View(begin2);
}

int getRandomNumber(int min, int max) {
	int randomNumber = rand() % (max - min + 1) + min;
	return randomNumber;
}

void main()
{
	setlocale(LC_ALL, "Russian");
	int i, in, n, kod, out;
	Stack* begin = NULL;
	srand(time(NULL));

	while (true) {
		cout << "\nВыберите номер пункта: \n\t1. Создать стек. \n\t2. Добавить элемент в стек. \n\t3. Вывести стек на экран.\n\t"
			"4. Удалить стек. \n\t5. Сортировка перестановкой двух соседних элементов. \n\t"
			"6. Сортировка обменом информацией между текущим и следующим элементами. \n\t7. Индивидуальное задание \n\t0. Выход. " << endl;
		cin >> kod;
		switch (kod) {
		case 1: 
		case 2:
			if (kod == 1 && begin != NULL) {
				cout << "Для начала удалите предудщий стек и очистите память." << endl;
				break;
			}
			cout << "Введите количество элементов: "; cin >> n;
			for (i = 1; i <= n; i++) {
				in = getRandomNumber(-10, 10);
				//cin >> in;
				begin = InStack(begin, in);
			}
			if (kod == 1) cout << "Создано " << n  << " рандомных элементов." << endl;
			else cout << "Добавлено " << n << " рандомных элементов." << endl;
			break;
		case 3: 
			if (!begin) {
				cout << "Стек пуст." << endl;
				break;
			}
			cout << endl << "--- Stack ---" << endl;
			View(begin);
			break;
		case 4:
			Del_All(&begin);
			cout << "Стек удален и память очищена." << endl;
			break;
		case 5:
			if (begin != NULL) {
				begin = InStack(begin, -100);
				Sort_p(&begin);
				begin = OutStack(begin, &out);
				cout << "Стек был отсортирован." << endl;
			} 
			else {
				cout << "Сортировка невозможна так как стек пуст." << endl;
			}
			break;
		case 6:
			if (begin != NULL) {
				Sort_info(begin);
				cout << "Стек был отсортирован." << endl;
			}
			else {
				cout << "Сортировка невозможна так как стек пуст." << endl;
			}
			break;
		case 7:
			cout << "Необходимо перенести из созданного списка в новый список все элементы, находящиеся между вершиной и максимальным элементом." << endl;
			if (begin != NULL) {
				IndividualTask(begin);
			}
			else {
				cout << "Индивидуальное задание невозможно выполнить так как стек пуст." << endl;
			}
			break;
		case 0:
			if (begin != NULL)
				Del_All(&begin);
			return;
		}
	}
}

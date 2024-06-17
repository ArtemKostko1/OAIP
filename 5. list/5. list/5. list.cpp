#include <iostream> 
#include <ctime> 
#include <Windows.h>
using namespace std;

struct Spis2 {
	int info;
	Spis2* next, * prev;
} *begin, * end, * t;

//------------------- Создание первого элемента -----------------------------
void Create_Spis2(Spis2** b, Spis2** e, int in) {
	t = new Spis2;
	t->info = in;
	t->next = t->prev = NULL;
	*b = *e = t;
}
//------------------- Добавление элемента в список --------------------------
void Add_Spis2(int kod, Spis2** b, Spis2** e, int in) {
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
void DeleteFirst(Spis2** p) {
	t = *p;
	*p = (*p)->next;
	delete t;
}
//--------------------- Просмотр элементов списка ---------------------------
void View_Spis2(int kod, Spis2* t) {
	while (t != NULL) {
		cout << t->info << endl;
		if (kod == 0) t = t->next;
		else t = t->prev;
	}
}

void Del_All(Spis2** p) {
	while (*p != NULL) {
		t = *p;
		*p = (*p)->next;
		delete t;
	}
}

void Sort_p(Spis2** p) {
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

void Sort_info(Spis2* p) {
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

int findMax(int kod, Spis2* p) {
	Spis2* t = p;
	int max = t->info;
	while (t != NULL) {
		if (t->info > max) {
			max = t->info;
		}
		t = (kod ==0) ? t->next : t->prev;
	}
	return max;
}

void IndividualTask(int kod, Spis2* t) {
	Spis2* begin2 = NULL;
	Spis2* end2 = NULL;
	Spis2* el = t;
	Spis2* el2 = t;

	int first = el->info;
	bool isFirst = true;
	int max = findMax(kod, t);
	int counter = 0;

	int nextElemInfo = (kod == 0) ? el->next->info : el->prev->info;
	if (el->info == max || nextElemInfo == max) {
		cout << "Количество элементов между вершиной и max = 0" << endl;
		return;
	}

	while (el != NULL) {
		if (max == el->info) {
			counter++;
		}
		el = (kod == 0) ? el->next : el->prev;
	}


	if (counter > 1) {
		cout << "Невозможно выполнить задание, так как найден не один max." << endl;
		return;
	}
	
	while (el2 != NULL) {
		if (el2->info == first && isFirst) {
			el2 = (kod == 0) ? el2->next : el2->prev;
			isFirst = false;
			continue;
		}
		if (max != el2->info) {
			if (begin2 == NULL) {
				Create_Spis2(&begin2, &end2, el2->info);
			}
			else {
				Add_Spis2(0, &begin2, &end2, el2->info);
			}
			el2 = (kod == 0) ? el2->next : el2->prev;
		}
		else {
			break;
		}
	}

	cout << endl;
	cout << "Новый стек:" << endl;

	View_Spis2(0, begin2);
}

void main()
{
	setlocale(LC_ALL, "Russian");
	int i, in, n, kod, kod1, out;

	Spis2* begin = NULL;
	Spis2* end = NULL;

	while (true) {
		cout << "\nВыберите номер пункта: \n\t1. Создать список. \n\t2. Добавить элемент в список. \n\t3. Вывести список на экран.\n\t4. Удалить список. \n\t5. Сортировка перестановкой двух соседних элементов. \n\t6. Сортировка обменом информацией между текущим и следующим элементами. \n\t7. Индивидуальное задание \n\t0. Выход. " << endl;
		cin >> kod;
		switch (kod) {
		case 111:
			Create_Spis2(&begin, &end, 1);
			Add_Spis2(1, &begin, &end, 2);
			Add_Spis2(1, &begin, &end, 3);
			Add_Spis2(1, &begin, &end, 3);
			Add_Spis2(1, &begin, &end, 3);
			Add_Spis2(1, &begin, &end, 2);
			Add_Spis2(1, &begin, &end, 1);
			break;
		case 222:
			Create_Spis2(&begin, &end, 1);
			Add_Spis2(1, &begin, &end, 3);
			Add_Spis2(1, &begin, &end, 1);
			Add_Spis2(1, &begin, &end, 2);
			Add_Spis2(1, &begin, &end, 1);
			Add_Spis2(1, &begin, &end, 5);
			Add_Spis2(1, &begin, &end, 4);
			Add_Spis2(1, &begin, &end, 3);
			break;
		case 1: 
			if (begin != NULL) {
				cout << "Для начала удалите предудщий список и очистите память." << endl;
				break;
			}
			cout << "Введите элемент, который будет добавлен в начало списка = "; 
			cin >> in;
			Create_Spis2(&begin, &end, in);
			cout << "Список создан:  " << endl;
			break;
		case 2:
			if (begin == NULL) {
				cout << "Сначала создайте список." << endl;
				break;
			}
			cout << "Введите элемент = "; 
			cin >> in;
			cout << "\n0. Добавить в начало. \n1. Добавить в конец" << endl;
			cin >> kod1;
			Add_Spis2(kod1, &begin, &end, in);
			if (kod1 == 0) 
			{ 
				t = begin; 
				cout << "Элемент добавлен в начало списка." << endl;
			}
			else { 
				t = end; 
				cout << "Элемент добавлен в конец списка" << endl;
			}
			break;
		case 3: 
			if (!begin) {
				cout << "Список пуст." << endl;
				break;
			}
			cout << "\n0. Посмотреть с начала. \n1. Посмотреть с конца." << endl;
			cin >> kod1;
			if (kod1 == 0) {
				t = begin;
				cout << "Ваш список, просмотренный с начала:" << endl;
			}
			else {
				t = end;
				cout << "Ваш список, просмотренный с конца:" << endl;
			}
			View_Spis2(kod1, t);
			break;
		case 4:
			Del_All(&begin);
			cout << "Список удален и память очищена." << endl;
			break;
		case 5:
			if (begin != NULL) {
				Add_Spis2(0, &begin, &end, -100);
				Sort_p(&begin);
				DeleteFirst(&begin);
				cout << "Список был отсортирован." << endl;
			}
			else {
				cout << "Сортировка невозможна так как список пуст." << endl;
			}
			break;
		case 6:
			if (begin != NULL) {
				Sort_info(begin);
				cout << "Список был отсортирован." << endl;
			}
			else {
				cout << "Сортировка невозможна так как список пуст." << endl;
			}
			break;
		case 7:
			if (begin == NULL) {
				cout << "Индивидуальное задание невозможно выполнить так как список пуст." << endl;
				break;
			}

			cout << "Необходимо перенести из созданного списка в новый список все элементы, находящиеся между вершиной и максимальным элементом." << endl;
			cout << "\n0. Вершина - начало. \n1. Вершина - конец" << endl;
			cin >> kod1;
			if (kod1 == 0)
			{
				t = begin;
			}
			else {
				t = end;
			}
			IndividualTask(kod1, t);
			break;
		case 0: if (begin != NULL)
			Del_All(&begin);
			return;
		}
	}
}

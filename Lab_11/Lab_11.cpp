#include <iostream>
#include <vector>
#include <thread>

using namespace std;

// Определение неленейного списка (дерева)
struct Tree {
	int key;
	string info;
	Tree* left, * right;
};

// Создание узла дерева с указателями на его потомки
Tree* createTreeNode(int elementKey, string value) {
	Tree* tree = new Tree;
	tree->info = value;
	tree->key = elementKey;
	tree->left = tree->right = NULL;
	return tree;
}

// Добавление узла дерева с уникальным ключом и значением
void addElement(Tree* rootTree, int elemtntKey, string value) {
	Tree* prevTree = NULL, * tree;
	bool find = true;

	tree = rootTree;

	while (tree && find) {
		prevTree = tree;
		if (elemtntKey == tree->key) {
			find = false;
			cout << "Ключ должен быть уникальный!";
		}
		else {
			if (elemtntKey < tree->key)
				tree = tree->left;
			else
				tree = tree->right;
		}
	}

	if (find) {
		tree = createTreeNode(elemtntKey, value);
		if (elemtntKey < prevTree->key)
			prevTree->left = tree;
		else
			prevTree->right = tree;
	}
}

// Удаление узла с заданным ключом из дерева
Tree* deleteTreeNode(Tree* rootTree, int elementKey) {
	Tree* Del, * Prev_Del, * R, * Prev_R;

	Del = rootTree;
	Prev_Del = NULL;

	while (Del != NULL && Del->key != elementKey) {
		Prev_Del = Del;
		if (Del->key > elementKey)  Del = Del->left;
		else Del = Del->right;
	}
	if (Del == NULL) {
		cout << "Ключ не найден";
		return rootTree;
	}

	if (Del->right == NULL) R = Del->left;
	else
		if (Del->left == NULL) R = Del->right;
		else {

			Prev_R = Del;
			R = Del->left;
			while (R->right != NULL) {
				Prev_R = R;
				R = R->right;
			}
			if (Prev_R == Del)  R->right = Del->right;
			else {
				R->right = Del->right;
				Prev_R->right = R->left;
				R->left = Prev_R;
			}
		}
	if (Del == rootTree) rootTree = R;
	else
		if (Del->info < Prev_Del->info)
			Prev_Del->left = R;
		else Prev_Del->right = R;
	delete Del;
	return rootTree;
}

// Поиск узла по ключу
void findTreeNode(Tree* rootTree, int elementKey) {
	bool exit = false;
	while (!exit)
	{
		system("cls");
		cout << "Найденный элемент\n";
		cout << ".................................................\n" << endl;

		Tree* tmp = rootTree;

		while (tmp != NULL && tmp->key != elementKey) {
			if (tmp->key > elementKey)  tmp = tmp->left;
			else tmp = tmp->right;
		}
		if (tmp == NULL)
			cout << "Ключ не найден" << endl;
		else
			cout << tmp->info << endl;

		cout << "\n................................................." << endl;
		cout << "Введите 0 для выхода: ";

		int input;
		if (cin >> input && input == 0)
		{
			exit = true;
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

	// Удаление дерева рекурсивно по каждому узлу
	void deleteTree(Tree * tree) {
		if (tree != NULL) {
			deleteTree(tree->left);
			deleteTree(tree->right);
			delete tree;
		}
	}

	void printPreOrder(Tree * rootTree) {
		if (rootTree != nullptr) {
			cout << rootTree->key << ": " << rootTree->info << endl;
			printPreOrder(rootTree->left);
			printPreOrder(rootTree->right);
		}
		else {
			cout << "Список пуст" << endl;
		}
	}

	// Обход дерева в префиксном порядке (корень, левое поддерево, правое поддерево)
	void displayPreOrder(Tree * rootTree) {
		bool exit = false;
		while (!exit)
		{
			system("cls");
			cout << "Элементы списка:\n";
			cout << ".................................................\n" << endl;

			printPreOrder(rootTree);

			cout << "\n................................................." << endl;
			cout << "Введите 0 для выхода: ";

			int input;
			if (cin >> input && input == 0)
			{
				exit = true;
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

	void printPostOrder(Tree * rootTree) {
		if (rootTree != nullptr) {
			printPostOrder(rootTree->left);
			printPostOrder(rootTree->right);
			cout << rootTree->key << ": " << rootTree->info << endl;
		}
		else {
			cout << "Список пуст" << endl;
		}
	}

	// Обход дерева в постфиксном порядке (левое поддерево, правое поддерево, корень)
	void displayPostOrder(Tree * rootTree) {
		bool exit = false;
		while (!exit)
		{
			system("cls");
			cout << "Элементы списка:\n";
			cout << ".................................................\n" << endl;

			printPostOrder(rootTree);

			cout << "\n................................................." << endl;
			cout << "Введите 0 для выхода: ";

			int input;
			if (cin >> input && input == 0)
			{
				exit = true;
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

	void printInOrder(Tree * rootTree) {
		if (rootTree != nullptr) {
			printPostOrder(rootTree->left);
			printPostOrder(rootTree->right);
			cout << rootTree->key << ": " << rootTree->info << endl;
		}
		else {
			cout << "Список пуст" << endl;
		}
	}

	// Обход дерева в инфиксном порядке (левое поддерево, корень, правое поддерево)
	void displayInOrder(Tree * rootTree) {
		bool exit = false;

		while (!exit)
		{
			system("cls");
			cout << "Элементы списка:\n";
			cout << ".................................................\n" << endl;

			printInOrder(rootTree);

			cout << "\n................................................." << endl;
			cout << "Введите 0 для выхода: ";

			int input;
			if (cin >> input && input == 0)
			{
				exit = true;
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

	void displayTree(Tree * rootTree) {
		bool displayTreeExit = false;
		int choice;
		while (!displayTreeExit) {
			system("cls");
			cout << "................................................." << endl;
			cout << "1. Прямой обход" << endl;
			cout << "2. Обратный обход" << endl;
			cout << "3. В порядке возрастания ключа" << endl;
			cout << "0. Выход" << endl;
			cout << "................................................." << endl;
			cout << "Выберите пункт меню: ";
			cin >> choice;

			switch (choice)
			{
			case 1:
				displayPreOrder(rootTree);
				break;
			case 2:
				displayPostOrder(rootTree);
				break;
			case 3:
				displayInOrder(rootTree);
				break;
			case 0:
				displayTreeExit = true;
				break;
			default:
				cout << "Неверный ввод. Ожидайте..." << endl;
				cin.clear(); // Очистка ошибочного состояния ввода
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка буфер ввода
				this_thread::sleep_for(chrono::milliseconds(1500)); // Задержка приложения, чтобы пользователь увидел сообщение об ошибке
				break;
			}
		}
	}

	int main()
	{
		system("CHCP 1251");

		Tree* rootTree = NULL;
		int choice, elementKey;
		bool exit = false;
		string element;
		vector<int> charCounts;

		while (!exit) {
			system("cls");
			cout << "Главное меню:" << endl;
			cout << "................................................." << endl;
			cout << "1. Добавить элемент" << endl;
			cout << "2. Удалить элемент" << endl;
			cout << "3. Поиск элемента" << endl;
			cout << "4. Вывести список" << endl;
			cout << "5. Решение индивидуального задания" << endl;
			cout << "0. Выход" << endl;
			cout << "................................................." << endl;
			cout << "Выберите пункт меню: ";
			cin >> choice;

			switch (choice) {
			case 1:
			{
				cout << "Введите новый элемент: ";
				cin >> element;
				cout << "Введите ключ элемента: ";
				cin >> elementKey;

				if (rootTree == NULL)
					rootTree = createTreeNode(elementKey, element);
				else
					addElement(rootTree, elementKey, element);

				break;
			}
			case 2:
			{
				cout << "Введите ключ элемента: ";
				cin >> elementKey;
				deleteTreeNode(rootTree, elementKey);
				break;
			}
			case 3:
			{
				cout << "Введите ключ элемента: ";
				cin >> elementKey;
				findTreeNode(rootTree, elementKey);

				break;
			}
			case 4:
			{
				displayTree(rootTree);
				break;
			}
			case 0:
			{
				deleteTree(rootTree);
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

		return 0;
	}
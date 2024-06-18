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
	tree->left = tree->right = nullptr;
	return tree;
}

// Добавление узла дерева с уникальным ключом и значением
void addElement(Tree* rootTree, int elemtntKey, string value) {
	Tree* prevTree, * tree;
	bool find = true;

	tree = rootTree;
	prevTree = tree;

	while (tree && find) {
		prevTree = tree;
		if (elemtntKey == tree->key) {
			find = false;
			cout << "Ключ должен быть уникальный! Ожидайте...";
			this_thread::sleep_for(chrono::milliseconds(2500));
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
	Prev_Del = nullptr;

	while (Del != nullptr && Del->key != elementKey) {
		Prev_Del = Del;
		if (Del->key > elementKey)  Del = Del->left;
		else Del = Del->right;
	}
	if (Del == nullptr) {
		cout << "Ключ не найден! Ожидайте...";
		this_thread::sleep_for(chrono::milliseconds(2500));
		return rootTree;
	}

	if (Del->right == nullptr) R = Del->left;
	else
		if (Del->left == nullptr) R = Del->right;
		else {

			Prev_R = Del;
			R = Del->left;
			while (R->right != nullptr) {
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
		if (Del->key < Prev_Del->key)
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

		while (tmp != nullptr && tmp->key != elementKey) {
			if (tmp->key > elementKey)  tmp = tmp->left;
			else tmp = tmp->right;
		}
		if (tmp == nullptr)
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
void deleteTree(Tree* tree) {
	if (tree != nullptr) {
		deleteTree(tree->left);
		deleteTree(tree->right);
		delete tree;
	}
}

// Обход дерева в префиксном порядке (корень, левое поддерево, правое поддерево)
void printPreOrder(Tree* rootTree) {
	if (rootTree != nullptr) {
		cout << rootTree->key << ": " << rootTree->info << endl;
		printPreOrder(rootTree->left);
		printPreOrder(rootTree->right);
	}
}

void displayPreOrder(Tree* rootTree) {
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

// Обход дерева в постфиксном порядке (левое поддерево, правое поддерево, корень)
void printPostOrder(Tree* rootTree) {
	if (rootTree != nullptr) {
		printPostOrder(rootTree->left);
		printPostOrder(rootTree->right);
		cout << rootTree->key << ": " << rootTree->info << endl;
	}
}

void displayPostOrder(Tree* rootTree) {
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

// Обход дерева в инфиксном порядке (левое поддерево, корень, правое поддерево)
void printInOrder(Tree* root) {
	if (root != nullptr) {
		printInOrder(root->left);
		cout << root->key << ": " << root->info << endl;
		printInOrder(root->right);
	}
}

void displayInOrder(Tree* rootTree) {
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

void displayTree(Tree* rootTree) {
	bool displayTreeExit = false;
	int choice;
	while (!displayTreeExit) {
		system("cls");
		cout << "................................................." << endl;
		cout << "1. Прямой обход (корень, лево, право)" << endl;
		cout << "2. Обратный обход (лево, право, корень)" << endl;
		cout << "3. В порядке возрастания ключа (лево, корень, право)" << endl;
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

void individualTask(Tree*& rootTree, bool& flag) {
	if (rootTree != nullptr) {
		individualTask(rootTree->left, flag);

		if (flag) {
			// Сохраняем указатель на правое поддерево перед удалением текущего узла
			Tree* rightSubtree = rootTree->right;
			rootTree = deleteTreeNode(rootTree, rootTree->key);
			flag = !flag; // Переключение флага для удаления каждого второго узла
			// Продолжаем обход с сохраненного правого поддерева
			individualTask(rightSubtree, flag);
		}
		else {
			flag = !flag; // Переключение флага если узел не был удален
			individualTask(rootTree->right, flag);
		}
	}
}

// Функция для вызова individualTask
void deleteEverySecondNode(Tree*& rootTree) {
	bool flag = false; // Начинаем с первого узла
	individualTask(rootTree, flag);

	cout << "Удаление каждого второго элемента произошло успешно. Ожидайте... ";
	this_thread::sleep_for(chrono::milliseconds(2500));
}

	int main()
	{
		system("CHCP 1251");

		Tree* rootTree = nullptr;
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

				if (rootTree == nullptr)
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
			case 5:
			{
				deleteEverySecondNode(rootTree);
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
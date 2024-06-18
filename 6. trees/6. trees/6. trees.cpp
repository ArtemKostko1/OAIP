#include <iostream>
#include <vector>
using namespace std;


struct Tree {
    int key;
    string info;
    Tree* left, * right;
};

Tree* List(int key, string value) {
    Tree* t = new Tree;
    t->info = value;
    t->key = key;
    t->left = t->right = NULL;
    return t;
}

void AddElement(Tree* root, int key, string value) {
    Tree* prev = NULL, * t;
    bool find = true;

    t = root;

    while (t && find) {
        prev = t;
        if (key == t->key) {
            find = false;
            cout << "Ключ должен быть уникальный!";
        }
        else {
            if (key < t->key)
                t = t->left;
            else
                t = t->right;
        }
    }

    if (find) {
        t = List(key, value);
        if (key < prev->key)
            prev->left = t;
        else
            prev->right = t;
    }
}

Tree* Del_Info(Tree* root, int key) {
    Tree* Del, * Prev_Del, * R, * Prev_R;

    Del = root;
    Prev_Del = NULL;

    while (Del != NULL && Del->key != key) {
        Prev_Del = Del;
        if (Del->key > key)  Del = Del->left;
        else Del = Del->right;
    }
    if (Del == NULL) {
        cout << "Ключ не найден";
        return root;
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
    if (Del == root) root = R;
    else
        if (Del->info < Prev_Del->info)
            Prev_Del->left = R;
        else Prev_Del->right = R;
    delete Del;
    return root;
}

void PrintPreOrder(Tree* root) {
    if (root != nullptr) {
        cout << root->key << ": " << root->info << endl;
        PrintPreOrder(root->left);
        PrintPreOrder(root->right);
    }
}

void PrintPostOrder(Tree* root) {
    if (root != nullptr) {
        PrintPostOrder(root->left);
        PrintPostOrder(root->right);
        cout << root->key << ": " << root->info << endl;
    }
}

void PrintInOrder(Tree* root) {
    if (root != nullptr) {
        PrintInOrder(root->left);
        cout << root->key << ": " << root->info << endl;
        PrintInOrder(root->right);
    }
}

void Del_Tree(Tree* t) {
    if (t != NULL) {
        Del_Tree(t->left);
        Del_Tree(t->right);
        delete t;
    }
}
void Find(Tree* r, int key) {
    Tree* tmp = r;

    while (tmp != NULL && tmp->key != key) {
        if (tmp->key > key)  tmp = tmp->left;
        else tmp = tmp->right;
    }
    if (tmp == NULL)
        cout << "Ключ не найден";
    else
        cout << tmp->info;
}

void CountCharsAtEachLevel(Tree* root, int level, vector<int>& charCounts) {
    if (root == NULL) return;

    if (level == charCounts.size())
        charCounts.push_back(0);

    charCounts[level] += root->info.length();

    CountCharsAtEachLevel(root->left, level + 1, charCounts);
    CountCharsAtEachLevel(root->right, level + 1, charCounts);
}


int main()
{
    setlocale(LC_ALL, "");

    Tree* root = NULL;
    int choice, key;
    string info;
    vector<int> charCounts;

    do {
        cout << "\nМеню:" << endl;
        cout << "1. Добавить элемент" << endl;
        cout << "2. Удалить элемент" << endl;
        cout << "3. Поиск элемента" << endl;
        cout << "4. Вывести список" << endl;
        cout << "5. Выполнить индивидуальное задание" << endl;
        cout << "6. Выйти" << endl;
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Введите значение элемента для добавления: ";
            cin >> info;
            cout << "Введите ключ элемента для добавления: ";
            cin >> key;

            if (root == NULL)
                root = List(key, info);
            else
                AddElement(root, key, info);
            break;
        case 2:
            cout << "Введите ключ элемента для удаления: ";
            cin >> key;
            Del_Info(root, key);
            break;
        case 3:
            cout << "Введите ключ элемента для поиска: ";
            cin >> key;
            Find(root, key);

            break;
        case 4:
            cout << "1.Прямой обход\n2.Обратный обход\n3.В порядке возрастания ключа\n";
            int n;
            cin >> n;
            cout << "Элементы списка:\n";

            switch (n)
            {
            case 1:
                PrintPreOrder(root);
                break;
            case 2:
                PrintPostOrder(root);
                break;
            case 3:
                PrintInOrder(root);
            default:
                break;
            }
            break;
        case 5:
            CountCharsAtEachLevel(root, 0, charCounts);
            for (int i = 0; i < charCounts.size(); i++) {
                cout << "Символов на " << i + 1 << " уровне: " << charCounts[i] << "\n";
            }
            break;
        case 6:
            Del_Tree(root);
            cout << "Выход из программы" << endl;
            break;
        default:
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Некорректный выбор" << endl;
        }
    } while (choice != 6);
}

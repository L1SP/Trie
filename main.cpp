#include <iostream>
#include <fstream>
#include <conio.h>
#include <Windows.h>
#include "Trie.h"
using namespace std;

void printMenu();

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	Trie* tr = new Trie;
	ifstream ifs("A.txt");
	uint8_t c = 0;
	bool isInitialized = 0;
	printMenu();
	while (c != '8') {
		c = _getch();
		switch (c) {
		case '1': {
			system("CLS");
			printMenu();
			if (!isInitialized) {
				tr->readFromFile(ifs);
				cout << "Дерево прочтено из файла.\n";
				isInitialized = 1;
			}
			else {
				cout << "Дерево уже было прочтено.\n";
			}
			break;
		}
		case '2': {
			system("CLS");
			printMenu();
			if (!isInitialized) {
				cout << "Дерево не инициализировано.\n";
				break;
			}
			cout << "Введите слово для добавления:\n";
			string tmp;
			cin >> tmp;
			tr->insert(tmp);
			cout << "Слово успешно добавлено.\n";
			break;
		}
		case '3': {
			system("CLS");
			printMenu();
			if (!isInitialized) {
				cout << "Дерево не инициализировано.\n";
				break;
			}
			cout << "Введите слово:\n";
			string tmp;
			cin >> tmp;
			if (tr->remove(tmp))
				cout << "Слово удалено из дерева.\n";
			else
				cout << "Такого слова в дереве нет.\n";
			break;
		}
		case '4': {
			system("CLS");
			printMenu();
			if (!isInitialized) {
				cout << "Дерево не инициализировано.\n";
				break;
			}
			cout << "Введите слово:\n";
			string tmp;
			cin >> tmp;
			if (tr->find(tmp))
				cout << "Такое слово есть дереве.\n";
			else
				cout << "Такого слова в дереве нет.\n";
			break;
		}
		case '5': {
			system("CLS");
			printMenu();
			if (!isInitialized) {
				cout << "Дерево не инициализировано.\n";
				break;
			}
			tr->print();
			break;
		}
		case '6': {
			system("CLS");
			printMenu();
			if (!isInitialized) {
				cout << "Дерево не инициализировано.\n";
				break;
			}
			tr->clear();
			cout << "Дерево очищено.\n";
			break;
		}
		case '7': {
			system("CLS");
			printMenu();
			if (!isInitialized) {
				cout << "Дерево не инициализировано.\n";
				break;
			}
			cout << "Введите подстроку для удаления:\n";
			string tmp;
			cin >> tmp;
			tr->deleteWordsWithSubstring(tmp);
			system("CLS");
			printMenu();
			cout << "Слова, содержащие такую подстроку удалены.\n";
			break;
		}
		}
	}
	delete tr;
	return 0;
}

void printMenu() {
	cout << "Выберите пункт меню:\n";
	cout << "1. Инициализировать дерево(из файла)\n";
	cout << "2. Добавить элемент в дерево.\n";
	cout << "3. Удалить в дереве.\n";
	cout << "4. Найти элемент в дереве.\n";
	cout << "5. Напечатать дерево.\n";
	cout << "6. Очистить дерево.\n";
	cout << "7. Удалить все слова, содержащие заданную подстроку.\n";
	cout << "8. Завершить работу программы.\n";
}
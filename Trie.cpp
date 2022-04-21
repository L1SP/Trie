#include "Trie.h"
#include <iostream>
using namespace std;

bool Trie::hasChilds(Node* node) {
	bool hasChilds = 0;
	size_t i = 0;
	while (!hasChilds && i < ALPHABET_SIZE) {
		hasChilds = node->symbols[i] != nullptr;
		i++;
	}
	return hasChilds;
}

bool Trie::remove(Node* node, string word, size_t h)
{
	if (node == nullptr && word.length() > 0) {
		return 0;
	}
	else if (node != nullptr && word.length() == h) {
		node->eow = 0;
		if (!hasChilds(node)) {
			delete node;
			node = nullptr;
		}
		return 1;
	}
	else if (node!=nullptr) {
		uint8_t symbol = word[h];
		size_t index = symbol - 'a';
		return remove(node->symbols[index], word, h + 1);
	}
}

Trie::Trie()
{
	root = new Node('/');
}

Trie::~Trie()
{
	clear();
	delete root;
}

void Trie::insert(string word) {
	Node* current = root;
	for (size_t i = 0; i < word.size(); ++i)
	{
		char symbol = word[i];
		size_t index = symbol - 'a';
		if (current->symbols[index] == nullptr)
		{
			current->symbols[index] = new Node(symbol);
		}

		current = current->symbols[index];
	}
	current->eow = 1;
}

bool Trie::find(string word)
{
	Node* current = root;
	for (size_t i = 0; i < word.size(); ++i)
	{
		char symbol = word[i];
		size_t index = symbol - 'a';
		if (current->symbols[index] == nullptr) {
			return 0;
		}
		current = current->symbols[index];
	}
	return current->eow;
}


bool Trie::remove(string word)
{
	return remove(root, word, 0);
}


void Trie::clear()
{
	if(root)
		clearRecursive(root);
	root = new Node('/');
}

void Trie::clearRecursive(Node*& node) {
	for (size_t i = 0; i < ALPHABET_SIZE; i++) {
		if(node->symbols[i])
			clearRecursive(node->symbols[i]);
	}
	delete node;
}

void printRecursive(Node* node, string word, size_t h) {
	if (node != nullptr) {
		if (node->eow) {
			cout << word+node->c << endl;
		}

		for (size_t i = 0; i < ALPHABET_SIZE; i++) {
			printRecursive(node->symbols[i], word + node->c, h + 1);
		}
	}
}

void Trie::print() {
	if (!hasChilds(root))
		cout << "Дерево пусто.\n";
	else {
		cout << "Дерево:\n";
		for (size_t i = 0; i < ALPHABET_SIZE; i++) {
			printRecursive(root->symbols[i], "", 1);
		}
	}
}
void Trie::deleteWordsWithSubstring(const string& substr) {
	deleteWordsWithSubstringRecursive(root, substr, "");
}
void Trie::deleteWordsWithSubstringRecursive(Node*& node, const string& substr, string cur) {
	if (cur.contains(substr)) {
		clearRecursive(node);
		node = nullptr;
	}
	else {
		for (size_t i = 0; i < ALPHABET_SIZE; i++) {
			if (node->symbols[i]) {
				deleteWordsWithSubstringRecursive(node->symbols[i], substr, cur + node->symbols[i]->c);
				if (!hasChilds(node) && !node->eow && node!=root) {
					delete node;
					node = nullptr;
					return;
				}
			}
		}
	}
}
void Trie::readFromFile(ifstream& ifs){
	string tmp;
	while (!ifs.eof()) {
		ifs >> tmp;
		insert(tmp);
	}
}
#pragma once
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

const uint8_t ALPHABET_SIZE = 26;
struct Node {
    char c;
    bool eow;
    Node* symbols[ALPHABET_SIZE];
public:
    Node(char symbol)
    {
        c = symbol;
        eow = 0;
        for (size_t i = 0; i < ALPHABET_SIZE; ++i)
            symbols[i] = nullptr;
    }
    Node(const Node& node)
    {
        c = node.c;
        eow = node.eow;
        for (size_t i = 0; i < ALPHABET_SIZE; ++i)
            symbols[i] = node.symbols[i];
    }
};

class Trie {
    Node* root;
    bool remove(Node* node, string word, size_t h);
    bool hasChilds(Node* node);
    void deleteWordsWithSubstringRecursive(Node*& node, const string& substr, string cur);
    void clearRecursive(Node*& node);
public:
    Trie();
    ~Trie();
    void insert(string s);
    bool find(string s);
    bool remove(string s);
    void clear();
    void deleteWordsWithSubstring(const string& substr);
    void print();
    void readFromFile(ifstream& ifs);
};
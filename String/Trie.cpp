#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    char c;
    unordered_map<char, node *> children;
    string word;
    bool isTerminal;

    node(char c)
    {
        this->c = c;
        word = "";
        isTerminal = false;
    }
};

class Trie
{
public:
    node *root;

    Trie()
    {
        root = new node('\0');
    }

    void addWord(string word)
    {

        node *temp = root;
        for (auto ch : word)
        {
            if (temp->children.count(ch) == 0)
            {
                temp->children[ch] = new node(ch);
            }
            temp = temp->children[ch];
        }
        // last node
        temp->isTerminal = true;
        temp->word = word;
    }
};

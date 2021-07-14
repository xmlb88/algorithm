#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>
using namespace std;

class Trie {
public:
    vector<Trie*> next;
    bool isEnd = false;

    Trie() : next(26) {}
};

void split(const string& sentence, vector<string>& res, const char flag = ' ') {
    stringstream ss(sentence);
    string word;
    while (getline(ss, word, flag)) {
        res.push_back(word);
    }
}

void insertTrie(Trie* root, const string& prefix) {
    Trie* node = root;
    for (char c : prefix) {
        c = c - 'a';
        if (node->next[c] == nullptr) {
            node->next[c] = new Trie();
        }
        node = node->next[c];
    }
    node->isEnd = true;
}

void hasPrefix(Trie* root, string& word) {
    int len = 0;
    Trie* node = root;
    for (char c : word) {
        c = c - 'a';
        if (node->next[c] == nullptr) {
            return;
        }
        node = node->next[c];
        ++len;
        if (node->isEnd) {
            word = word.substr(0, len);
            return;
        }
    }
}

string replaceWords(vector<string>& dictionary, string sentence) {
    Trie* root = new Trie();
    for (const string& prefix : dictionary) {
        insertTrie(root, prefix);
    }

    vector<string> words;
    split(sentence, words);
    for(string& word : words) {
        hasPrefix(root, word);
    }

    string res;
    for (const string& word : words) {
        res += word + " ";
    }
    res.pop_back();
    return res;
}
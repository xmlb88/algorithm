#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class WordDictionary {
public:
    unordered_set<string> dic;

    WordDictionary() {

    }

    void addWord(string word) {
        dic.insert(word);
    }

    bool replaceSearch(string word, int index) {
        if (index == word.size()) {
            return dic.find(word) != dic.end();
        }

        if (word[index] != '.') {
            return replaceSearch(word, index + 1);
        } else {
            for (char c = 'a'; c <= 'z'; ++c) {
                word[index] = c;
                if (replaceSearch(word, index + 1)) return true;
            }
        }

        return false;
    }

    bool search(string word) {
        return replaceSearch(word, 0);
    }
};



struct Trie {
    vector<Trie*> next;
    bool isEnd = false;

    Trie() : next(26) {}
};

class WordDictionary {
public:
    Trie* root;
    WordDictionary() {
        root = new Trie();
    }

    void addWord(string word) {
        Trie* node = root;
        for (char c : word) {
            c = c - 'a';
            if (node->next[c] == nullptr) {
                node->next[c] = new Trie();
            }
            node = node->next[c];
        }
        node->isEnd = true;
    }

    bool dfs(string& word, int index, Trie* node) {
        if (index == word.size()) {
            return node->isEnd;
        }

        char c = word[index];
        if (c == '.') {
            for (Trie* nextNode : node->next) {
                if (nextNode && dfs(word, index + 1, nextNode)) return true;
            }
        } else {
            c = c - 'a';
            if (node->next[c] == nullptr) return false;
            else return dfs(word, index + 1, node->next[c]);
        }
        return false;
    }

    bool search(string word) {
        return dfs(word, 0, root);
    }
};

int main() {
    vector<string> words = {"bad", "dad", "mad"};
    WordDictionary wd;
    for (const string& word : words) {
        wd.addWord(word);
    }

    cout << boolalpha << wd.search("bad") << endl;
    cout << boolalpha << wd.search("pad") << endl;
    cout << boolalpha << wd.search(".ad") << endl;
    cout << boolalpha << wd.search("b..") << endl;
}
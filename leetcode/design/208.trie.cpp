#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <map>
using namespace std;

// ???
// class Trie {
// public:
//     unordered_set<string> st;
//     unordered_set<string> trie;
//     Trie() {

//     }

//     void insert(string word) {
//         st.insert(word);
//         for (int i = 1; i <= word.size(); ++i) {
//             trie.insert(word.substr(0, i));
//         }
//     }

//     bool search(string word) {
//         return st.find(word) != st.end();
//     }

//     bool startsWith(string prefix) {
//         return trie.find(prefix) != trie.end();
//     }
// };


// Ç°×ºÊ÷

// µÝ¹é

/*
class Trie {
private:
    struct Node {
        map<char, int> next;
        bool end = false;
    };
    vector<Node> trie;

public:
    Trie() {
        trie.clear();
        trie.push_back(Node());
    }

    void insert(const string& word) {
        insert(0, word, 0);
    }

    bool search(const string& word) {
        return search(0, word, 0);
    }

    bool startsWith(const string& prefix) {
        return startsWith(0, prefix, 0);
    }

private:
    void insert(int treeID, const string& word, int index) {
        if (index == word.size()) {
            trie[treeID].end = true;
            return;
        }

        if (trie[treeID].next.find(word[index]) == trie[treeID].next.end()) {
            trie[treeID].next[word[index]] = trie.size();
            trie.push_back(Node());
        }

        insert(trie[treeID].next[word[index]], word, index + 1);
    }

    bool search(int treeID, const string& word, int index) {
        if (index == word.size()) {
            return trie[treeID].end;
        }

        if (trie[treeID].next.find(word[index]) == trie[treeID].next.end()) {
            return false;
        }

        return search(trie[treeID].next[word[index]], word, index + 1);
    }

    bool startsWith(int treeID, const string& prefix, int index) {
        if (index == prefix.size()) {
            return true;
        }

        if (trie[treeID].next.find(prefix[index]) == trie[treeID].next.end()) {
            return false;
        }

        return startsWith(trie[treeID].next[prefix[index]], prefix, index + 1);
    }
};

*/

class Trie {
private:
    struct Node {
        unordered_map<char, int> next;
        bool end = false;
    };
    vector<Node> trie;

public:
    Trie() {
        trie.clear();
        trie.push_back(Node());
    }

    void insert(const string& word) {
        insert(0, word, 0);
    }

    bool search(const string& word) {
        return search(0, word, 0);
    }

    bool startsWith(const string& prefix) {
        return startsWith(0, prefix, 0);
    }

private:
    void insert(int treeID, const string& word, int index) {
        if (index == word.size()) {
            trie[treeID].end = true;
            return;
        }

        if (trie[treeID].next.find(word[index]) == trie[treeID].next.end()) {
            trie[treeID].next[word[index]] = trie.size();
            trie.push_back(Node());
        }

        insert(trie[treeID].next[word[index]], word, index + 1);
    }

    bool search(int treeID, const string& word, int index) {
        if (index == word.size()) {
            return trie[treeID].end;
        }

        if (trie[treeID].next.find(word[index]) == trie[treeID].next.end()) {
            return false;
        }

        return search(trie[treeID].next[word[index]], word, index + 1);
    }

    bool startsWith(int treeID, const string& word, int index) {
        if (index == word.size()) {
            return true;
        }

        if (trie[treeID].next.find(word[index]) == trie[treeID].next.end()) {
            return false;
        }

        return startsWith(trie[treeID].next[word[index]], word, index + 1);
    }
};

// int main() {
//     Trie trie;
//     trie.insert("abck");
//     cout << trie.startsWith("ab") << endl;
//     cout << trie.search("abc") << endl;
// }

class Trie {
private:
    struct Node {
        unordered_map<char, int> next;
        bool end = false;
    };

    vector<Node> trie;
public:
    Trie() {
        trie.clear();
        trie.push_back(Node());
    }

    void insert(const string& word) {
        int treeID = 0;
        for (char c : word) {
            if (trie[treeID].next.find(c) == trie[treeID].next.end()) {
                trie[treeID].next[c] = trie.size();
                trie.push_back(Node());
            }
            treeID = trie[treeID].next[c];
        }
        trie[treeID].end = true;
    }

    bool search(const string& word) {
        int treeID = 0;
        for (char c : word) {
            if (trie[treeID].next.find(c) == trie[treeID].next.end()) {
                return false;
            }
            treeID = trie[treeID].next[c];
        }
        return trie[treeID].end;
    }

    bool startsWith(const string& prefix) {
        int treeID = 0;
        for (char c : prefix) {
            if (trie[treeID].next.find(c) == trie[treeID].next.end()) {
                return false;
            }
            treeID = trie[treeID].next[c];
        }
        return true;
    }
};

class Trie {
private:
    vector<Trie*> children;
    bool isEnd;

    Trie* searchPrefix(string prefix) {
        Trie* node = this;
        for (char ch : prefix) {
            ch -= 'a';
            if (node->children[ch] == nullptr) {
                return nullptr;
            }
            node = node->children[ch];
        }
        return node;
    }

public:
    Trie() : children(26), isEnd(false) {}

    void insert(string word) {
        Trie* node = this;
        for (char ch : word) {
            ch -= 'a';
            if (node->children[ch] == nullptr) {
                node->children[ch] = new Trie();
            }
            node = node->children[ch];
        }
        node->isEnd = true;
    }

    bool search(string word) {
        Trie* node = this->searchPrefix(word);
        if (node == nullptr) return false;
        return node->isEnd;
    }

    bool startsWith(string prefix) {
        Trie* node = this->searchPrefix(prefix);
        return node != nullptr;
    }
};


class Trie {
private:
    vector<Trie*> next;
    bool isEnd;

    Trie* searchPrefix(const string& prefix) {
        Trie* node = this;
        for (char c : prefix) {
            c -= 'a';
            if (node->next[c] == nullptr) {
                return nullptr;
            }
            node = node->next[c];
        }
        return node;
    }

public:
    Trie() : next(26), isEnd(false) {}

    void insert(const string& word) {
        Trie* node = this;
        for (char c : word) {
            c -= 'a';
            if (node->next[c] == nullptr) {
                node->next[c] = new Trie();
            }
            node = node->next[c];
        }
        node->isEnd = true;
    }

    bool search(const string& word) {
        Trie* node = searchPrefix(word);
        if (node == nullptr) return false;
        return node->isEnd;
    }

    bool startsWith(const string& word) {
        Trie* node = searchPrefix(word);
        return node != nullptr;
    }
};
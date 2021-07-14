#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <numeric>
#include <iterator>
using namespace std;

struct Trie {
    unordered_map<char, Trie*> next;
    bool isEnd = false;
    int times = 0;
};

class AutocompleteSystem {
public:
    Trie* root;
    string query;

    void insertTrie(const string& sentence, int times) {
        Trie* node = root;
        for (char c : sentence) {
            if (node->next.find(c) == node->next.end()) {
                node->next[c] = new Trie();
            }
            node = node->next[c];
        }
        node->isEnd = true;
        node->times = times;
    }

    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        root = new Trie();
        query.clear();
        int n = sentences.size();
        for (int i = 0; i < n; ++i) {
            insertTrie(sentences[i], times[i]);
        }
    }

    Trie* getPrefix(const string& prefix) {
        Trie* node = root;
        for (char c : prefix) {
            if (node->next.find(c) == node->next.end()) {
                return nullptr;
            }
            node = node->next[c];
        }
        return node;
    }

    void getAllSentences(Trie* node, string& prefix, vector<pair<string, int>>& result) {
        if (node->isEnd) {
            result.push_back(make_pair(prefix, node->times));
        }

        for (auto& [c, nextNode] : node->next) {
            prefix.push_back(c);
            getAllSentences(nextNode, prefix, result);
            prefix.pop_back();
        }
    }

    void addSentence(const string& sentence) {
        Trie* node = root;
        for (char c : sentence) {
            if (node->next.find(c) == node->next.end()) {
                node->next[c] = new Trie();
            }
            node = node->next[c];
        }
        if (!node->isEnd) node->isEnd = true;
        node->times += 1;
    }

    vector<string> input(char c) {
        if (c == '#') {
            addSentence(query);
            query.clear();
            return {};
        }
        query.push_back(c);
        Trie* node = getPrefix(query);
        if (!node) return {};
        string sentence = query;
        vector<pair<string, int>> result;
        getAllSentences(node, sentence, result);
        sort(result.begin(), result.end(), [] (const pair<string, int>& a, pair<string, int>& b) {
            return a.second == b.second ? a.first < b.first : a.second > b.second;
        });

        vector<string> queryRes;
        for (auto& [s, _] : result) {
            queryRes.push_back(s);
            if (queryRes.size() == 3) break;
        }
        return queryRes;
    }
};

void printRes(vector<string>& result) {
    for (const string& s : result) {
        cout << s << "####";
    }
    cout << endl;
}

int main() {

    vector<string> sentences = {"i love you","island","iroman","i love leetcode"};
    vector<int> times = {5, 3, 2, 2};
    AutocompleteSystem ac(sentences, times);

    vector<string> queryResult;
    cout << "first query:" << endl;
    queryResult = ac.input('i');
    printRes(queryResult);
    cout << "second query:" << endl;
    queryResult = ac.input(' ');
    printRes(queryResult);
    cout << "third query:" << endl;
    queryResult = ac.input('a');
    printRes(queryResult);
    cout << "last:" << endl;
    queryResult = ac.input('#');
    printRes(queryResult);
}
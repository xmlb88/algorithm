#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// KMP
void search(string s, string p, vector<int>& getPos) {
    int n = s.size(), m = p.size();
    if (m == 0) return;

    s.insert(s.begin(), ' ');
    p.insert(p.begin(), ' ');
    vector<int> next(m + 1);

    for (int i = 2, j = 0; i <= m; ++i) {
        while (j && p[i] != p[j + 1]) j = next[j];
        if (p[i] == p[j + 1]) ++j;
        next[i] = j;
    }

    for (int i = 0, j = 0; i <= n; ++i) {
        while (j && s[i] != p[j + 1]) j = next[j];
        if (s[i] == p[j + 1]) ++j;
        if (j == m) getPos.push_back(i - m);
    }
}

// sliding window
// miss is
void search(string s, string p, vector<int>& getPos) {
    int n = s.size(), m = p.size();
    if (m == 0) return;

    for (int i = 0; i <= n - m; ++i) {
        if (s.substr(i, m) == p) getPos.push_back(i);
    }
}

vector<vector<int>> multiSearch(string big, vector<string>& smalls) {
    vector<vector<int>> res;
    vector<int> getPos;
    for (const string& pattern : smalls) {
        getPos.clear();
        search(big, pattern, getPos);
        res.push_back(getPos);
    }
    return res;
}

// Trie

struct Trie {
    vector<Trie*> next;
    int index = -1;

    Trie() : next(26) {}
};

vector<vector<int>> multiSearch(string big, vector<string>& smalls) {
    int n = big.size(), m = smalls.size();
    Trie* root = new Trie();
    for (int i = 0; i < m; ++i) {
        Trie* node = root;
        for (char c : smalls[i]) {
            c = c - 'a';
            if (node->next[c] == nullptr) {
                node->next[c] = new Trie();
            }
            node = node->next[c];
        }
        node->index = i;
    }

    vector<vector<int>> res(m);
    for (int i = 0; i < n; ++i) {
        Trie* node = root;
        int j = i;
        while (j < n && node->next[big[j] - 'a'] != nullptr) {
            node = node->next[big[j] - 'a'];
            if (node->index != -1) res[node->index].push_back(i);
            ++j;
        }
    }
    return res;
}



int main() {
    string s = "mississippi";
    string p = "is";
    vector<int> getPos;
    search(s, p, getPos);
    for (int i : getPos) {
        cout << i << " ";
    }
}
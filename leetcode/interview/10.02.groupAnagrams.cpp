#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// ³¬Ê± 100/101
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> res;
    vector<bool> visited(strs.size(), false);
    for (int i = 0; i < strs.size(); i++) {
        if (!visited[i]) {
            vector<string> store;
            store.push_back(strs[i]);
            visited[i] = true;
            for (int j = 0; j < strs.size(); j++) {
                if (!visited[j] && isAnagrams(strs[i], strs[j])) {
                    store.push_back(strs[j]);
                    visited[j] = true;
                }
            }
            res.push_back(store);
        }
    }
    return res;
}

bool isAnagrams(string& a, string& b) {
    if (a.size() != b.size()) return false;
    vector<int> vec(26, 0);
    for (int i = 0; i < a.size(); i++) {
        vec[a[i] - 'a']++;
    }

    for (int i = 0; i < b.size(); i++) {
        vec[b[i] - 'a']--;
        if (vec[b[i] - 'a'] < 0) return false;
    }

    for (int i = 0; i < 26; i++) {
        if (vec[i] != 0) return false;
    }

    return true;
}

// ¹þÏ£±í + sort
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> m;
    for (string i : strs) {
        string t = i;
        sort(t.begin(), t.end());
        auto it = m.find(t);
        if (it == m.end()) m[t] = vector<string> {i};
        else m[t].push_back(i);
    }

    for (auto i : m) {
        ans.push_back(i.second);
    }
    return ans;
}
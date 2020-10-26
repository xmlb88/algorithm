#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

vector<string> res;
vector<string> permutation(string s) {
    string t;
    vector<int> used;
    dfs(s, t, used);
    return res;
}

void dfs(string s, string& t, vector<int>& used) {
    if (t.size() == s.size() && find(res.begin(), res.end(), t) == res.end()) {
        res.push_back(t);
        return;
    }

    for (int i = 0; i < s.size(); i++) {
        if (find(used.begin(), used.end(), i) == used.end()) {
            t.push_back(s[i]);
            used.push_back(i);
            dfs(s, t, used);
            t.pop_back();
            used.pop_back();
        }
    }
}

// ÓÅ»¯
vector<string> res;
vector<string> permutation(string s) {
    sort(s.begin(), s.end());
    string t;
    vector<bool> used(s.size(), false);
    dfs(s, t, used);
    return res;
}

void dfs(string s, string& t, vector<bool>& used) {
    if (t.size() == s.size()) {
        res.push_back(t);
        return;
    }

    for (int i = 0; i < s.size(); i++) {
        if (used[i]) continue;
        if (i > 0 && !used[i - 1] && s[i - 1] == s[i]) continue;
        t.push_back(s[i]);
        used[i] = true;
        dfs(s, t, used);
        t.pop_back();
        used[i] = false;
    }
}

// ½»»»
set<string> res;
vector<string> permutation(string s) {
    dfs(s, 0);
    return vector<string>(res.begin(), res.end());
}

void dfs(string s, int start) {
    if (start == s.size()) {
        res.insert(s);
        return;
    }

    for (int i = start; i < s.size(); i++) {
        swap(s[i], s[start]);
        dfs(s, start + 1);
        swap(s[i], s[start]);
    }
}
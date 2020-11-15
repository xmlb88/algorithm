#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string, bool> memo;
bool isMatch(string s, string p) {
    return dfs(s, 0, p, 0);
}

bool dfs(string s, int i, string p, int j) {
    // base case
    if (i == s.size()) {
        if (j == p.size()) return true;

        for (int k = j; k < p.size(); k++) {
            if (p[k] != '*') return false;
        }

        return true;
    }

    if (j == p.size()) {
        if (i == s.size()) return true;
        else return false;
    }

    string key = to_string(i) + ',' + to_string(j);
    if (memo.count(key)) return memo[key];

    if (s[i] == p[j] || p[j] == '?') {
        // 匹配单个字符
        memo[key] = dfs(s, i + 1, p, j + 1);
    } else if (p[j] == '*') {
        // 字符没匹配上但是有*
        memo[key] = dfs(s, i + 1, p, j) || dfs(s, i, p, j + 1);
    } else memo[key] = false;

    return memo[key];
}

// abcabcd
// *abcd

// 优化
unordered_map<int, bool> memo;
bool isMatch(string s, string p) {
    return dfs(s, 0, p, 0);
}

bool dfs(string s, int i, string p, int j) {
    // base case
    if (i == s.size()) {
        if (j == p.size()) return true;

        for (int k = j; k < p.size(); k++) {
            if (p[k] != '*') return false;
        }

        return true;
    }

    if (j == p.size()) {
        if (i == s.size()) return true;
        else return false;
    }

    // string key = to_string(i) + ',' + to_string(j);
    // pair<int, int> key{i, j};
    int key = i * 1000000 + j;
    if (memo.count(key)) return memo[key];

    if (s[i] == p[j] || p[j] == '?') {
        // 匹配单个字符
        memo[key] = dfs(s, i + 1, p, j + 1);
    } else if (p[j] == '*') {
        // 字符没匹配上但是有*
        memo[key] = dfs(s, i + 1, p, j) || dfs(s, i, p, j + 1);
    } else memo[key] = false;

    return memo[key];
}

// dp数组
bool isMatch(string s, string p) {
    int n = s.size(), int m = p.size();

    
}
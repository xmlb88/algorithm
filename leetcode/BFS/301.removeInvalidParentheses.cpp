#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <unordered_set>
using namespace std;

// TODO:
bool check(string s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(') {
            st.push(c);
        } else if (c == ')') {
            if (st.empty()) return false;
            else st.pop();
        }
    }
    return st.empty();
}

unordered_set<string> res;
void dfs(string s, int remove, int start, string str) {
    if (remove < 0) return;
    if (start == s.size() && remove == 0) {
        if (check(str)) {
            res.insert(str);
        }
        return;
    }

    if (start == s.size()) return;

    if (s[start] == '(' || s[start] == ')') {
        dfs(s, remove - 1, start + 1, str);
    }
    str.push_back(s[start]);
    dfs(s, remove, start + 1, str);
}

vector<string> removeInvalidParentheses(string s) {
    if (check(s)) return {s};
    int n = s.size();
    string str = "";
    for (int i = 1; i <= n; ++i) {
        dfs(s, i, 0, str);
        if (!res.empty()) {
            return vector<string>(res.begin(), res.end());
        }
    }
    return {};
}

int main() {
    // string s = ")()(e()))))))((((";
    string s = ")k)))())()())))())";
    for (auto& str : removeInvalidParentheses(s)) {
        cout << str << endl;
    }
}

// TLE ¼ôÖ¦
unordered_set<string> st;

void dfs(string s, int index, int left_count, int right_count, int left_remove, int right_remove, string path) {
    if (right_count > left_count) return;
    if (left_remove < 0 || right_remove < 0) return;
    if (index == s.size()) {
        if (left_remove == 0 && right_remove == 0) st.insert(path);
        return;
    }

    if (s[index] == '(') {
        dfs(s, index + 1, left_count, right_count, left_remove - 1, right_remove, path);
        path.push_back(s[index]);
        dfs(s, index + 1, left_count + 1, right_count, left_remove, right_remove, path);
    } else if (s[index] == ')') {
        dfs(s, index + 1, left_count, right_count, left_remove, right_remove - 1, path);
        path.push_back(s[index]);
        dfs(s, index + 1, left_count, right_count + 1, left_remove, right_remove, path);
    } else {
        path.push_back(s[index]);
        dfs(s, index + 1, left_count, right_count, left_remove, right_remove, path);
    }
}

vector<string> removeInvalidParentheses(string s) {
    int left_remove = 0, right_remove = 0;
    for (char c : s) {
        if (c == '(') {
            ++left_remove;
        } else if (c == ')') {
            if (left_remove == 0) {
                ++right_remove;
            } else {
                --left_remove;
            }
        }
    }

    if (left_remove == 0 && right_remove == 0) return {s};
    dfs(s, 0, 0, 0, left_remove, right_remove, string(""));
    return vector<string> (st.begin(), st.end());
}

// BFS TODO:
#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

// 2个栈
bool backspaceCompare(string S, string T) {
    stack<char> s_st;
    stack<char> t_st;

    for (int i = 0; i < S.size(); i++) {
        if (S[i] == '#' && !s_st.empty()) {
            s_st.pop();
        } else if (S[i] == '#' && s_st.empty()) {
            continue;
        } else s_st.push(S[i]);
    }

    for (int i = 0; i < T.size(); i++) {
        if (T[i] == '#' && !t_st.empty()) {
            t_st.pop();
        } else if (T[i] == '#' && t_st.empty()) {
            continue;
        } else t_st.push(T[i]);
    }

    if (s_st.size() != t_st.size()) return false;

    while (!s_st.empty() && !t_st.empty()) {
        if (s_st.top() != t_st.top()) {
            return false;
        }
        s_st.pop();
        t_st.pop();
    }

    return true;
}

// 用string代替栈，并且直接比较
bool backspaceCompare(string S, string T) {
    return build(S) == build(T);
}

string build(string s) {
    string res;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != '#') {
            res.push_back(s[i]);
        } else if (!res.empty()) {
            res.pop_back();
        }
    }
    return res;
}

// 双指针从后往前遍历
bool backspaceCompare(string S, string T) {
    int i = S.size(), j = T.size();
    int i_bs = 0, j_bs = 0;
    string res_i, res_j;

    while (i >= 0) {
        if (S[i] == '#') {
            i_bs++;
        } else if (i_bs > 0) {
            i_bs--;
        } else {
            res_i.push_back(S[i]);
        }
        i--;
    }

    while (j >= 0) {
        if (T[j] == '#') {
            j_bs++;
        } else if (j_bs > 0) {
            j_bs--;
        } else {
            res_j.push_back(T[j]);
        }
        j--;
    }

    return res_i == res_j;
}
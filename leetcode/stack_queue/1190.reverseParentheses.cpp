#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

string reverseParentheses(string s) {
    stack<char> st;
    for (const char& c : s) {
        if (c == ')') {
            string s;
            while (st.top() != '(') {
                s.push_back(st.top());
                st.pop();
            }
            st.pop();
            for (int i = 0; i < s.size(); ++i) {
                st.push(s[i]);
            }

        } else st.push(c);
    }

    string res;
    while (!st.empty()) {
        res.push_back(st.top());
        st.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}


// 
string reverseParentheses(string s) {
    stack<string> st;
    string str;
    for (char c : s) {
        if (c == '(') {
            st.push(str);
            str = "";
        } else if (c == ')') {
            reverse(str.begin(), str.end());
            str = st.top() + str;
            st.pop();
        } else {
            str.push_back(c);
        }
    }
    return str;
}

string reverseParentheses(string s) {
    stack<string> st;
    string str;
    for (char c : s) {
        if (c == ')') {
            reverse(str.begin(), str.end());
            str = st.top() + str;
            st.pop();
        } else if (c == '(') {
            st.push(str);
            str = "";
        } else str.push_back(c);
    }
    return str;
}


string reverseParentheses(string s) {
    int n = s.size();
    vector<int> pair(n);
    stack<int> st;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            st.push(i);
        } else if (s[i] == ')') {
            int j = st.top();
            st.pop();
            pair[i] = j;
            pair[j] = i;
        }
    }

    string ret;
    int index = 0, step = 1;
    while (index < n) {
        if (s[index] == '(' || s[index] == ')') {
            index = pair[index];
            step = -step;
        } else ret.push_back(s[index]);
        index += step;
    }
    return ret;
}
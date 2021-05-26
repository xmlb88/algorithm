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
            while (!s.empty()) {
                st.push(s.back());
                s.pop_back();
            }

        } else st.push(c);
    }

    string res;
    while (!st.empty()) {
        res.push_back(st.top());
        st.pop();
    }

    return res;
}
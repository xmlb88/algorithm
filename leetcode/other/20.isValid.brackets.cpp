#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isValid(string s) {
    stack<char> st;
    for (char c : s) {
        if (!st.empty() && ((st.top() == '(' && c == ')') || (st.top() == '[' && c == ']') || (st.top() == '{' && c == '}'))) {
            st.pop();
        } else st.push(c);
    }

    return st.empty();
}

// review 2020Äê11ÔÂ26ÈÕ17:41:16
bool isValid(string s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else {
            if (!st.empty() && st.top() == leftOf(c)) {
                st.pop();
            } else return false;
        }
    }

    return st.empty();
}

char leftOf(char c) {
    if (c == ')') return '(';
    if (c == ']') return '[';
    return '{';
}

bool isValid(string s) {
    stack<char> st;
    for (char c : s) {
        if (!st.empty() && ((c == ')' && st.top() == '(') || (c == ']' && st.top() == '[') || (c == '}' && st.top() == '{'))) {
            st.pop();
        } else st.push(c);
    }
    return st.empty();
}
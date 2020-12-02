#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

string removeDuplicateLetters(string s) {
    vector<bool> instack(256, false);
    vector<int> count(256, 0);
    for (int i = 0; i < s.length(); i++) {
        count[s[i]]++;
    }

    stack<char> st;
    string result;

    for (int i = 0; i < s.length(); i++) {
        count[s[i]]--;

        if (instack[s[i]]) continue;
        while (!st.empty() && st.top() > s[i] && count[st.top()] > 0) {
            instack[st.top()] = false;
            st.pop();
        }

        st.push(s[i]);
        instack[s[i]] = true;
    }

    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    reverse(result.begin(), result.end());
    return result;
}


string removeDuplicateLetters(string s) {
    vector<bool> instack(256, false);
    vector<int> count(256, 0);
    stack<char> st;

    for (int i = 0; i < s.length(); i++) {
        count[s[i]]++;
    }

    for (int i = 0; i < s.length(); i++) {
        count[s[i]]--;
        if (instack[s[i]]) continue;
        
        while (!st.empty() && st.top() > s[i] && count[st.top()] > 0) {
            instack[st.top()] = false;
            st.pop();
        }

        st.push(s[i]);
        instack[s[i]] = true;
    }

    string result;
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    reverse(result.begin(), result.end());
    return result;
}

string removeDuplicateLetters(string s) {
    vector<bool> instack(256, false);
    vector<int> count(256, 0);
    stack<char> st;

    for (char c : s) {
        count[c]++;
    }

    for (char c : s) {
        count[c]--;
        if (instack[c]) continue;

        while (!st.empty() && count[st.top()] > 0 && st.top() > c) {
            instack[st.top()] = false;
            st.pop();
        }

        st.push(c);
        instack[c] = true;
    }

    string result;
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    reverse(result.begin(), result.end());
    return result;
}


// 同1081
// review 2020年11月16日10:45:03
string removeDuplicateLetters(string s) {
    if (s.empty()) return s;
    vector<bool> inStack(256, false);
    vector<int> count(256, 0);
    stack<char> st;

    for (char c : s) {
        count[c]++;
    }

    for (char c : s) {
        count[c]--;
        if (inStack[c]) continue;

        while (!st.empty() && st.top() > c && count[st.top()] > 0) {
            inStack[st.top()] = false;
            st.pop();
        }

        st.push(c);
        inStack[c] = true;
    }

    string res;
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }

    reverse(res.begin(), res.end());
    return res;
}
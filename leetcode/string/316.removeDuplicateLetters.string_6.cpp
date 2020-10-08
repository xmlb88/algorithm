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
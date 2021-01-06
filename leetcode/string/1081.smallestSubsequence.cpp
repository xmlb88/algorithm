#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

string smallestSubsequence(string s) {
    vector<bool> inStack(256, false);
    vector<int> count(256, 0);
    stack<char> st;

    for (char c : s) {
        count[c]++;
    }

    for (char c : s) {
        count[c]--;

        if (inStack[c]) continue;

        while (!st.empty() && count[st.top()] > 0 && st.top() > c) {
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
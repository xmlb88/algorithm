#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

// :( TLE
bool check(string& s, stack<char> st, int i) {
    if (i == s.size()) {
        return st.empty();
    }

    if (s[i] != '*') {
        if (s[i] == '(') st.push(s[i]);
        else if (s[i] == ')') {
            if (st.empty()) return false;
            st.pop();
        }
        return check(s, st, i + 1);
    } else {
        string s1 = s;
        s1[i] = '(';
        string s2 = s;
        s2[i] = ')';
        return check(s1, st, i) || check(s2, st, i) || check(s, st, i + 1);
    }
}

bool checkValidString(string s) {
    int n = s.size();
    stack<char> st;
    return check(s, st, 0);
}


bool checkValidString(string s) {
    int n = s.size();
     
}

int main() {
    string s = "(*))";
    cout << boolalpha << checkValidString(s) << endl;
}
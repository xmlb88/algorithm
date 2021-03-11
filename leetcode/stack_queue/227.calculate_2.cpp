#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <numeric>
using namespace std;

int calculate(string s) {
    int n = s.size();
    char sign = '+';
    stack<int> st;
    int num = 0;
    for (int i = 0; i < n; i++) {
        char c = s[i];
        if (isdigit(c)) {
            num = num * 10 + (c - '0');
        }

        if ((!isdigit(c) && c != ' ') || i == n - 1) {
            switch(sign) {
                case '+':
                    st.push(num);
                    break;
                case '-':
                    st.push(-num);
                    break;
                case '*':
                    num = num * st.top();
                    st.pop();
                    st.push(num);
                    break;
                case '/':
                    num = st.top() / num;
                    st.pop();
                    st.push(num);
                    break;
            }
            num = 0;
            sign = c;
        }
    }

    int res = 0;
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }
    return res;
}


int calculate(string s) {
    vector<int> stk;
    char sign = '+';
    int num = 0;
    int n = s.size();
    for(int i = 0; i < n; ++i) {
        char c = s[i];
        if (isdigit(c)) {
            num = num * 10 + (c - '0');
        }

        if (!isdigit(c) && c != ' ' || i == n - 1) {
            switch(sign) {
                case '+':
                    stk.push_back(num);
                    break;
                case '-':
                    stk.push_back(-num);
                    break;
                case '*':
                    stk.back() *= num;
                    break;
                case '/':
                    stk.back() /= num;
            }
            sign = c;
            num = 0;
        }
    }
    return accumulate(stk.begin(), stk.end(), 0);
}
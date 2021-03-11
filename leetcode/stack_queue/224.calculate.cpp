#include <iostream>
#include <string>
#include <stack>
using namespace std;

// 字符串转换int
string s = "458";
int n = 0;
for (int i = 0; i < s.size(); ++i) {
    char c = s[i];
    n = 10 * n + (c - '0');
}

// 加减法
int calculate(string s) {
    stack<int> st;
    int num = 0;

    char sign = '+';
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (isdigit(c))
            num = 10 * num + (c - '0');
        if (!isdigit(c) || i == size() - 1) {
            switch(sign) {
                case '+':
                    st.push(num);
                    break;
                case '-':
                    st.push(-num);
                    break;
            }
            sign = c;
            num = 0;
        }
    }

    int res = 0;
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }
    return res;
}

// 题解1
int calculate(string s) {
    stack<int> ops;
    ops.push(1);
    int sign = 1;

    int ret = 0;
    int n = s.length();
    int i = 0;
    while (i < n) {
        if (s[i] == ' ') {
            ++i;
            continue;
        } 

        if (s[i] == '+') {
            sign = ops.top();
            ++i;
        } else if (s[i] == '-') {
            sign = -ops.top();
            ++i;
        } else if (s[i] == '(') {
            ops.push(sign);
            ++i;
        } else if (s[i] == ')') {
            ops.pop();
            ++i;
        } else {
            int num = 0;
            while (i < n && isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
                ++i;
            }
            ret += sign * num;
        }
    }
    return ret;
}

// own thought
int calculate(string s) {

}

// 9 + (3 - 1) * 3 + 10 / 2
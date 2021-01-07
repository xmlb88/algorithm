#include <iostream>
#include <string>
#include <stack>
using namespace std;

// DP
int longestValidParentheses(string s) {
    int n = s.size(), maxans = 0;
    vector<int> dp(n, 0);
    for (int i = 1; i < n; i++) {
        if (s[i] == ')') {
            if (s[i - 1] == '(') {
                dp[i] = i >= 2 ? dp[i - 2] + 2 : 2;
            } else if (i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(') {
                dp[i] = dp[i - 1] + ((i - dp[i - 1] - 2 >= 0) ? dp[i - dp[i - 1] - 2] : 0) + 2;
            }
        }
        maxans = max(maxans, dp[i]);
    }
    return maxans;
}

// 栈
int longestValidParentheses(string s) {
    int maxans = 0;
    stack<int> stk;
    stk.push(-1);
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            stk.push(i);
        } else {
            stk.pop();
            if (stk.empty()) {
                stk.push(i);
            } else {
                maxans = max(maxans, i - stk.top());
            }
        }
    }
    return maxans;
}

// 贪心 左 -> 右，右 -> 左2次遍历
int longestValidParentheses(string s) {
    int left = 0, right = 0;
    int maxans = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') left++;
        else if (s[i] == ')') right++;

        if (left == right) maxans = max(maxans, 2 * right);
        else if (right > left) {
            left = 0;
            right = 0;
        }
    }

    left = 0; right = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == '(') left++;
        else if (s[i] == ')') right++;

        if (left == right) maxans = max(maxans, 2 * left);
        else if (left > right) {
            left = 0;
            right = 0;
        }
    }
    return maxans;
}

// review 2021年1月7日15:54:37
// dp
int longestValidParentheses(string s) {
    int n = s.size();
    vector<int> dp(n, 0);
    int res = 0;
    for (int i = 1; i < n; i++) {
        if (s[i] == ')') {
            if (s[i - 1] == '(') {
                dp[i] = i >= 2? dp[i - 2] + 2 : 2;
            } else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
                dp[i] = dp[i - 1] + (i - dp[i - 1] - 2 >= 0? dp[i - dp[i - 1] - 2] : 0) + 2;
            }
        }
        res = max(res, dp[i]);
    }
    return res;
}

// ()((...))
// 栈
int longestValidParentheses(string s) {
    int maxans = 0;
    stack<int> stk;
    stk.push(-1);
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            stk.push(i);
        } else {
            stk.pop();
            if (stk.empty()) {
                stk.push(i);
            } else {
                maxans = max(maxans, i - stk.top());
            }
        }
    }
    return maxans;
}

// 正向逆向
int longestValidParentheses(string s) {
    int n = s.size();
    int left = 0, right = 0;
    int maxlen = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') left++;
        if (s[i] == ')') right++;

        if (left == right) {
            maxlen = max(maxlen, left + right);
        } else if (right > left) {
            left = 0;
            right = 0;
        }
    }

    left = 0; right = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '(') left++;
        if (s[i] == ')') right++;

        if (left == right) {
            maxlen = max(maxlen, left + right);
        } else if (left > right) {
            left = 0;
            right = 0;
        }
    }
    return maxlen;
}
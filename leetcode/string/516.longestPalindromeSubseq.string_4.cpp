#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 递归
int longestPalindromeSubseq(string s) {
    return palindromeSubseq(s, 0, s.length() - 1);
}

int palindromeSubseq(string s, int l, int r) {
    // base case
    if (l > r) return 0;
    if (l == r) return 1;

    if (s[l] == s[r]) {
        return palindromeSubseq(s, l + 1, r - 1) + 2;
    } else {
        return max(palindromeSubseq(s, l + 1, r), palindromeSubseq(s, l, r - 1));
    }
}

// 备忘录优化
vector<vector<int>> dp;
int longestPalindromeSubseq(string s) {
    dp.resize(s.length(), vector<int> (s.length(), -1));
    return palindromeSubseq(s, 0, s.length() - 1);
}

int palindromeSubseq(string s, int l, int r) {
    // base case 
    if (l > r) return 0;
    if (l == r) return 1;

    if (dp[l][r] != -1) return dp[l][r];

    if (s[l] == s[r]) {
        dp[l][r] = palindromeSubseq(s, l + 1, r - 1) + 2;
    } else {
        dp[l][r] = max(palindromeSubseq(s, l + 1, r), palindromeSubseq(s, l, r - 1));
    }

    return dp[l][r];
}

// dp数组迭代
int longestPalindromeSubseq(string s) {
    vector<vector<int>> dp(s.length(), vector<int> (s.length(), 0));
    for (int i = 0; i < s.length(); i++) {
        dp[i][i] = 1;
    }

    for (int i = s.length() - 1; i >= 0; i--) {
        for (int j = i + 1; j < s.length(); j++) {
            if (s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            } else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[0][s.length() - 1];
}

int longestPalindromeSubseq(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int> (n, 0));

    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            if (s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            } else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[0][n - 1];
}

int longestPalindromeSubsuq(string s) {
    int n = s.length();
    vector<vector<int>> dp(n, vector<int> (n, 0));

    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            if (s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            } else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[0][n - 1];
}

// review 2020年10月29日11:07:25
int longestPalindromeSubseq(string s) {
    return dp(s, 0, s.length() - 1);
}

int dp(string s, int i, int j) {
    // base case
    if (i > j) return 0;
    if (i == j) return 1;

    if (s[i] == s[j]) return 2 + dp(s, i + 1, j - 1);
    else return max(dp(s, i + 1, j), dp(s, i, j - 1));
}

// 备忘录
vector<vector<int>> memo;
int longestPalindromeSubseq(string s) {
    int n = s.size();
    memo.resize(n, vector<int> (n, -1));
    return dp(s, 0, n - 1);
}

int dp(string s, int i, int j) {
    // base case 
    if (i > j) return 0;
    if (i == j) return 1;

    if (memo[i][j] != -1) return memo[i][j];
    if (s[i] == s[j]) memo[i][j] = 2 + dp(s, i + 1, j - 1);
    else memo[i][j] = max(dp(s, i + 1, j), dp(s, i, j - 1));

    return memo[i][j];
}

// 迭代
int longestPalindromeSubseq(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int> (n, 0));

    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }

    for (int i = n - 2; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            if (s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1] + 2;
            else dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
    }

    return dp[0][n - 1];
}

// 状态压缩一维
int longestPalindromeSubseq(string s) {
    int n = s.size();
    // base case: 一维dp数组全初始化为1
    vector<int> dp(n, 1);

    for (int i = n - 2; i >= 0; i--) {
        // 存储dp[i + 1][j - 1] 的变量
        int pre = 0;
        for (int j = i + 1; j < n; j++) {
            int temp = dp[j];
            if (s[i] == s[j]){
                // dp[i][j] = 2 + dp[i + 1][j - 1];
                dp[j] = pre + 2;
            } else dp[j] = max(dp[j], dp[j - 1]);
            // 到下一轮循环 pre就是dp[i + 1][j - 1]了
            pre = temp;
        }
    }
    return dp[n - 1];
}
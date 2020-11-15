#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 递归
vector<vector<int>> memo;
int minimumDeleteSum(string s1, string s2) {
    int m = s1.size(), n = s2.size();
    memo.resize(m, vector<int> (n, -1));
    return dp(s1, 0, s2, 0);
}

int dp(string s1, int i, string s2, int j) {
    int m = s1.length(), n = s2.length();
    if (i == m) {
        int rest = 0;
        while (j < n) {
            rest += s2[j];
            j++;
        }
        return rest;
    }

    if (j == n) {
        int rest = 0;
        while (i < m) {
            rest += s1[i];
            i++;
        }
        return rest;
    }

    if (memo[i][j] != -1) return memo[i][j];

    if (s1[i] == s2[j]) {
        memo[i][j] = dp(s1, i + 1, s2, j + 1);
    } else {
        memo[i][j] = min((int)s1[i] + dp(s1, i + 1, s2, j), (int)s2[j] + dp(s1, i, s2, j + 1));
    }
    return memo[i][j];
}

// 迭代
int minimumDeleteSum(string s1, string s2) {
    int m = s1.length(), n = s2.length();
    vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));
    
    // 初始化[...,0]和[0, ...]
    for (int i = 1; i <= n; i++) {
        dp[0][i] = dp[0][i - 1] + (int)s2[i - 1];
    }

    for (int i = 1; i <= m; i++) {
        dp[i][0] = dp[i - 1][0] + (int)s1[i - 1];
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
            else {
                dp[i][j] = min((int)s1[i - 1] + dp[i - 1][j], (int)s2[j - 1] + dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}
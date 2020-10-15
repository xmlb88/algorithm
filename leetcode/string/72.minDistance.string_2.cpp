#include <iostream>
#include <string>
using namespace std;

// 递归 超出时间限制
int minDistance(string word1, string word2) {
    return dp(word1, word2, word1.length() - 1, word2.length() - 1);
}

int dp(string word1, string word2, int i, int j) {
    // base case
    if (i == -1) return j + 1;
    if (j == -1) return i + 1;

    if (word1[i] == word2[j]) {
        return dp(word1, word2, i - 1, j - 1);
    } else {
        // return min(
        //     dp(word1, word2, i, j - 1) + 1, // 插入
        //     dp(word1, word2, i - 1, j) + 1, // 删除
        //     dp(word1, word2, i - 1, j - 1) + 1 // 替换
        // );

        int insert = dp(word1, word2, i, j - 1);
        int del = dp(word1, word2, i - 1, j);
        int replace = dp(word1, word2, i - 1, j - 1);
        return min(insert, min(del, replace)) + 1;
    }
}

// 备忘录优化
int minDistance(string word1, string word2) {
    int n = word1.length();
    int m = word2.length();
    vector<vector<int>> memo(n, vector<int>(m, -1));
    return dp(word1, word2, n - 1, m - 1, memo);
}

int dp(string word1, string word2, int i, int j, vector<vector<int>>& memo) {
    // base case
    if (i == -1) return j + 1;
    if (j == -1) return i + 1;
    
    if (memo[i][j] != -1) return memo[i][j];

    // 相等 skip
    if (word1[i] == word2[j]) {
        memo[i][j] = dp(word1, word2, i - 1, j - 1, memo);
    } else {
        int insert = dp(word1, word2, i, j - 1, memo) + 1;
        int del = dp(word1, word2, i - 1, j, memo) + 1;
        int replace = dp(word1, word2, i - 1, j - 1, memo) + 1;
        memo[i][j] = min(insert, min(del, replace));
    }

    return memo[i][j];
}

// dp数组迭代

int minDistance(string word1, string word2) {
    int m = word1.length();
    int n = word2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // base case
    for (int i = 1; i <= m; i++) {
        dp[i][0] = i;
    }

    for (int j = 1; j <= n; j++) {
        dp[0][j] = j;
    }

    // 自底向上求解
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = min(
                    dp[i][j - 1] + 1,
                    min(dp[i - 1][j] + 1, dp[i - 1][j - 1] + 1)
                );
            }
        }
    }

    return dp[m][n];
}


int minDistance(string word1, string word2) {
    int m = word1.length();
    int n = word2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // base case
    for (int i = 1; i <= m; i++) {
        dp[i][0] = i;
    }

    for (int j = 1; j <= n; j++) {
        dp[0][j] = j;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = min(dp[i][j - 1] + 1, min(dp[i - 1][j] + 1, dp[i - 1][j - 1] + 1));
            }
        }
    }

    return dp[m][n];
}
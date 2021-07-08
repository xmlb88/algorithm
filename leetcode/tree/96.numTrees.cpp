#include <iostream>
#include <vector>
#include "treeNode.h"
using namespace std;

vector<int> memo;
int numTrees(int n) {
    memo.assign(n + 1, -1);
    return dfs(n);
}

int dfs(int n)  {
    if (n <= 1) return 1;

    if (memo[n] != -1) return memo[n];
    int num = 0;
    for (int i = 1; i <= n; ++i) {
        num += dfs(i - 1) * dfs(n - i);
    }
    memo[n] = num;
    return num;
}


// dp
int numTrees(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1, dp[1] = 1;

    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            dp[i] += dp[j - 1] * dp[i - j];
        }
    }
    return dp[n];
}


// review 2021Äê7ÔÂ8ÈÕ10:11:00

vector<int> memo;
int dfs(int n) {
    if (n <= 1) return 1;
    if (memo[n] != -1) return memo[n];

    int num = 0;
    for (int i = 1; i <= n; ++i) {
        num += dfs(i - 1) * dfs(n - i);
    }
    memo[n] = num;
    return memo[n];
}

int numTrees(int n) {
    memo.resize(n + 1, -1);
    return dfs(n);
}

int numTrees(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1, dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            dp[i] += dp[j - 1] * dp[i - j];
        }
    }
    return dp[n];
}
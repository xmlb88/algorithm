#include <iostream>
#include <vector>
using namespace std;

int uniquePaths(int m, int n) {
    vector<vector<int>> path(m, vector<int> (n, 1));
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            path[i][j] = path[i - 1][j] + path[i][j - 1];
        }
    }
    return path[m - 1][n - 1];
}

int uniquePaths(int m, int n) {
    vector<int> path(n, 1);
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            path[j] = path[j - 1] + path[j];
        }
    }
    return path[n - 1];
}

// review 2020��12��9��16:50:14
int uniquePaths(int m, int n) {
    vector<vector<int>> path(m, vector<int> (n, 1));
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            path[i][j] = path[i - 1][j] + path[i][j - 1];
        }
    }
    return path[m - 1][n - 1];
}

int uniquePaths(int m, int n) {
    vector<int> path(m, 1);
    for (int j = 1; j < n; j++) {
        for (int i = 1; i < m; i++) {
            path[i] += path[i - 1];
        }
    }
    return path[m - 1];
}

// review 2021��5��6��18:15:41
int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int> (n, 1));
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[m - 1][n - 1];
}

// �ռ��Ż�
int uniquePaths(int m, int n) {
    vector<int> dp(m, 1);
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            dp[j] += dp[j - 1];
        }
    }
    return dp[m - 1];
}

// review 2021��7��12��15:39:11
// use DP
int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int> (n, 1));
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    return dp[m - 1][n - 1];
}

// �������� �Ż�
int uniquePaths(int m, int n) {
    vector<int> dp(n, 1);
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            dp[j] += dp[j - 1];
        }
    }
    return dp[n - 1];
}
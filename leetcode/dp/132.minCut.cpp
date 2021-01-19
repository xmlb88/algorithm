#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 131 的思路dfs，超时
// vector<string> path;
vector<vector<bool>> isPalind;
int minNumber = INT_MAX;
int cut = 0;

void dfs(string& s, int start) {
    if (start >= s.size()) {
        // int n = path.size();
        // size = min(size, n);
        minNumber = min(minNumber, cut);
        return;
    }

    for (int i = start; i < s.size(); i++) {
        if (isPalind[start][i]) {
            // path.push_back(s.substr(start, i - start + 1));
            cut++;
            dfs(s, i + 1);
            cut--;
        }
    }
} 

int minCut(string s) {
    int n = s.size();
    isPalind.resize(n, vector<bool> (n, false));

    for (int i = n - 1; i >= 0; i--) {
        for (int j = i; j < n; j++) {
            if (s[i] == s[j]) {
                if (j - i + 1 <= 2) isPalind[i][j] = true;
                else isPalind[i][j] = isPalind[i + 1][j - 1];
            }
        }
    }

    dfs(s, 0);
    return minNumber - 1;
}

// dp
int minCut(string s) {
    // 先构建isPalind数组
    int n = s.size();
    vector<vector<bool>> isPalind(n, vector<bool> (n, false));

    for (int i = n - 1; i >= 0; i--) {
        for (int j = i; j < n; j++) {
            if (s[i] == s[j]) {
                if (j - i <= 1) isPalind[i][j] = true;
                else isPalind[i][j] = isPalind[i + 1][j - 1];
            }
        }
    }

    vector<int> dp(n);
    for (int i = 0; i < n; i++) {
        dp[i] = i;
    }

    for (int i = 1; i < n; i++) {
        if (isPalind[0][i]) {
            dp[i] = 0;
            continue;
        }

        for (int j = 0; j < i; j++) {
            if (isPalind[j + 1][i]) {
                dp[i] = min(dp[i], dp[j] + 1);
            }
        }
    }

    return dp[n - 1];
}

// review
int minCut(string s) {
    // 先构造isPalind数组，O(1)判断s[i, j]是否是回文串
    int n = s.size();
    vector<vector<bool>> isPalind(n, vector<bool> (n, false));

    for (int i = n - 1; i >= 0; i--) {
        for (int j = i; j < n; j++) {
            if (s[i] == s[j]) {
                if (j - i <= 1) isPalind[i][j] = true;
                else isPalind[i][j] = isPalind[i + 1][j - 1];
            }
        }
    }

    // dp[i] 与dp[0...i - 1]比较
    vector<int> dp(n);
    iota(dp.begin(), dp.end(), 0);
    for (int i = 1; i < n; i++) {
        if (isPalind[0][i]) {
            dp[i] = 0;
            continue;
        }

        for (int j = 0; j < i; j++) {
            if (isPalind[j + 1][i]) {
                dp[i] = min(dp[i], dp[j] + 1);
            }
        }
    }

    return dp[n - 1];
}
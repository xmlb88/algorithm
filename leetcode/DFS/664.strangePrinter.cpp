#include <iostream>
#include <vector>
#include <string>
using namespace std;

int strangePrinter(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 1));

    for (int i = n - 1; i >= 0; --i) {
        for (int j = i + 1; j < n; ++j) {
            if (s[i] == s[j]) {
                dp[i][j] = dp[i][j - 1];
            } else {
                int minn = INT_MAX;
                for (int k = i; k < j; k++) {
                    minn = min(minn, dp[i][k] + dp[k + 1][j]);
                }
                dp[i][j] = minn;
            }
        }
    }
    return dp[0][n - 1];
}

// dp[i][j] = dp[i + 1][j - 1] | dp[i + 1][j] | dp[i][j - 1]
// tbgtgb

// aaabbbbssffzzaa
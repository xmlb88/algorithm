#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// DFS ³¬Ê±
unordered_map<string, int> count;
void backtrack(string& s, string& substr, int index) {
    count[substr] += 1;
    if (index == s.size()) return;

    for (int i = index; i < s.size(); ++i) {
        substr.push_back(s[i]);
        backtrack(s, substr, i + 1);
        substr.pop_back();
    }
}

int numDistinct(string s, string t) {
    string substr;
    backtrack(s, substr, 0);
    return count[t];
}

// dp own thought
int numDistinct(string s, string t) {
    int n = s.size(), m = t.size();
    vector<vector<long>> dp(m, vector<int> (n, 0));
    for (int i = 0; i < n; ++i) {
        if (s[i] == t[0]) dp[0][i] = 1;
    }

    for (int i = 1; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (s[j] == t[i]) {
                for (int k = 0; k < j; k++) {
                    dp[i][j] += dp[i - 1][k];
                }
            }
        }
    }

    return accumulate(dp[m - 1].begin(), dp[m - 1].end(), 0);
}

int numDistinct(string s, string t) {
    int n = s.size(), m = t.size();
    vector<vector<long>> dp(n + 1, vector<long> (m + 1, 0));

    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][m];
}

int numDistinct(string s, string t) {
    int n = s.size(), m = t.size();
    vector<long> dp(m + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= 1; --j) {
            if (s[i - 1] == t[j - 1]) {
                dp[j] += dp[j - 1];
            }
        }
    }

    return dp[m];
}
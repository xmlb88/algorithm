#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// 与873类似
int longestArithSeqLength(vector<int>& A) {
    int n = A.size();
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
        mp[A[i]] = i;
    }

    vector<vector<int>> dp(n, vector<int> (n, 2));
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int target = A[i] - (A[j] - A[i]);
            for (int k = i - 1; k >= 0; k--) {
                if (A[k] == target) {
                    dp[i][j] = dp[k][i] + 1;
                    break;
                }
            }
            ans = max(ans, dp[i][j]);
        }
    }
    return ans;
}

// map优化
int longestArithSeqLength(vector<int>& A) {
    int n = A.size();

    // A中数字可以重复，一边查找一边增加map
    unordered_map<int, int> index;
    vector<vector<int>> dp(n, vector<int>(n, 2));
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int target = 2 * A[i] - A[j];
            if (index.count(target)) {
                dp[i][j] = dp[index[target]][i] + 1;
            }
            res = max(res, dp[i][j]);
        }
        index[A[i]] = i;
    }
    return res;
}
#include <iostream>
#include <vector>
using namespace std;


// DP
int videoStitching(vector<vector<int>>& clips, int T) {
    vector<int> dp(T + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= T; i++) {
        for (auto& it : clips) {
            if (it[0] < i && i <= it[1]) {
                dp[i] = min(dp[i], dp[it[0]] + 1);
            }
        }
    }
    return dp[T] == INT_MAX? -1 : dp[T];
}

// Ì°ÐÄ
int videoStitching(vector<vector<int>>& clips, int T) {
    vector<int> maxn(T);
    int last = 0, ret = 0, pre = 0;
    for (vector<int>& it : clips) {
        if (it[0] < T) {
            maxn[it[0]] = max(maxn[it[0]], it[1]);
        }
    }

    for (int i = 0; i < T; i++) {
        last = max(last, maxn[i]);
        if (i == last) {
            return -1;
        }
        if (i == pre) {
            ret++;
            pre = last;
        }
    }
    return ret;
}

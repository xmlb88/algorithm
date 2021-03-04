#include <iostream>
#include <vector>
using namespace std;

int maxEnvelopes(vector<vector<int>>& envelopes) {
    int n = envelopes.size();
    if (n == 0) return 0;
    sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b)
    {return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];});

    vector<int> dp(n, 1);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int res = 1;
    for (int i = 0; i < n; i++) {
        res = max(res, dp[i]);
    }

    return res;
}


int maxEnvelopes(vector<vector<int>>& envelopes) {
    int n = envelopes.size();
    if (n == 0) return 0;
    sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b)
    {return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];});

    vector<int> dp(n, 1);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (envelopes[i][1] > envelopes[j][1]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    return *max_element(dp.begin(), dp.end());
}


// review 2021年3月4日
int maxEnvelopes(vector<vector<int>>& envelopes) {
    if (envelopes.empty()) return 0;
    sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b)
    {
        if (a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    });

    int n = envelopes.size();
    vector<int> dp(n, 1);
    int maxLen = 1;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (envelopes[i][1] > envelopes[j][1]) dp[i] = max(dp[i], dp[j] + 1);
        }
        maxLen = max(maxLen, dp[i]);
    }

    return maxLen;
}

// 二分查找 + dp
// TODO:
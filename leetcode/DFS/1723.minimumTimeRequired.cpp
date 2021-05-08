#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

vector<int> time;
int minimum_time = INT_MAX;
int minimumTimeRequired(vector<int>& jobs, int k) {
    time.resize(k, 0);
    backtrace(jobs, k, 0, 0);
    return minimum_time;
}

void backtrace(vector<int>& jobs, int k, int index, int used) {
    if (index == jobs.size()) {
        minimum_time = min(minimum_time, *max_element(time.begin(), time.end()));
        return;
    }

    if (used < k) {
        time[used] = jobs[index];
        backtrace(jobs, k, index + 1, used + 1);
        time[used] = 0;
    }
    for (int i = 0; i < used; ++i) {
        if (time[i] + jobs[index] > minimum_time) continue;
        time[i] += jobs[index];
        backtrace(jobs, k, index + 1, used);
        time[i] -= jobs[index];
    }
}

// 二分查找 + DFS + 剪枝

bool dfs(vector<int>& jobs, int idx, int limit, vector<int>& workload) {
    if (idx >= jobs.size()) {
        return true;
    }

    int cur = jobs[idx];
    for (auto& work : workload) {
        if (work + cur <= limit) {
            work += cur;
            if (dfs(jobs, idx + 1, limit, workload)) {
                return true;
            }
            work -= cur;
        }

        if (work == 0 || work + cur == limit) {
            break;
        }
    }
    return false;
}

bool check(vector<int>& jobs, int k, int limit) {
    vector<int> workload(k, 0);
    return dfs(jobs, 0, limit, workload);
}

int minimumTimeRequired(vector<int>& jobs, int k) {
    sort(jobs.begin(), jobs.end(), greater<int>());
    int left = jobs[0];
    int right = accumulate(jobs.begin(), jobs.end(), 0);
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (check(jobs, k, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

// dp + 状态压缩
// __builtin_clz 前导0
// __builtin_ctz 后面0
// __builtin_popcount 1的个数
// dp[i][j]  dp[i - 1][s- j]

int minimumTimeRequired(vector<int>& jobs, int k) {
    int n = jobs.size();
    vector<int> tot(1 << n, 0);
    for (int i = 1; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            if ((i & (1 << j)) == 0) continue;
            int left = (i - (1 << j));
            tot[i] = tot[left] + jobs[j];
            break;
        }
    }

    vector<vector<int>> dp(k, vector<int> (1 << n, -1));
    for (int i = 0; i < (1 << n); i++) {
        dp[0][i] = tot[i];
    }

    for (int j = 1; j < k; j++) {
        for (int i = 0; i < (1 << n); i++) {
            int minv = INT_MAX;
            for (int s = i; s; s = (s - 1) & i) {   // 枚举i的全部子集
                int left = i - s;
                int val = max(dp[j - 1][left], tot[s]);
                minv = min(minv, val);
            }
            dp[j][i] = minv;
        }
    }
    return dp[k - 1][(1 << n) - 1];
}

int minimumTimeRequired(vector<int>& jobs, int k) {
    int n = jobs.size();
    vector<int> tot(1 << n, 0);
    for (int i = 1; i < (1 << n); ++i) {
        int x = __builtin_ctz(i), left = i - (1 << x);
        tot[i] = tot[left] + jobs[x];
    }

    vector<vector<int>> dp(k, vector<int> (1 << n));
    for (int i = 0; i < (1 << n); ++i) {
        dp[0][i] = tot[i];
    }

    for (int i = 1; i < k; ++i) {
        for (int j = 0; j < (1 << n); ++j) {
            int minv = INT_MAX;
            for (int s = j; s; s = (s - 1) & j) {
                int left = j - s;
                int val = max(dp[i - 1][left], tot[s]);
                minv = min(minv, val);
            }
            dp[i][j] = minv;
        }
    }
    return dp[k - 1][(1 << n) - 1];
}
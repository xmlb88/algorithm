#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;

// TLE
bool can = false;
vector<int> step = {-1, 0, 1};
bool canCross(vector<int>& stones) {
    dfs(stones, stones[0], 0);
    return can;
}

void dfs(vector<int>& stones, int start, int k) {
    int n = stones.size();
    if (start == stones[n - 1]) {
        can = true;
        return;
    }

    for (auto s : step) {
        if (k + s > 0) {
            auto it = find(stones.begin(), stones.end(), start + k + s);
            if (it == stones.end()) continue;
            dfs(stones, start + k + s, k + s);
        }
    }
}

// 
bool canCross(vector<int>& stones) {
    vector<int> step = {-1, 0, 1};
    stack<pair<int, int>> st;
    st.push(make_pair(stones[0], 0));
    while (!st.empty()) {
        auto p = st.top();
        st.pop();
        int start = p.first;
        if (start == stones[stones.size() - 1]) {
            return true;
        }
        int k = p.second;
        for (auto s : step) {
            if (k + s > 0) {
                if (find(stones.begin(), stones.end(), start + k + s) != stones.end()) {
                    st.push(make_pair(start + k + s, k + s));
                }
            }
        }
    }
    return false;
}

// int main() {
//     vector<int> stones = {0,1,2,3,4,8,9,11};
//     canCross(stones);
// }

// https://leetcode-cn.com/problems/frog-jump/solution/qing-wa-guo-he-by-leetcode-solution-mbuo/
vector<unordered_map<int, int>> rec;
bool dfs(vector<int>& stones, int i, int lastDis) {
    if (i == stones.size() - 1) {
        return true;
    }

    if (rec[i].count(lastDis)) {
        return rec[i][lastDis];
    }

    for (int curDis = lastDis - 1; curDis <= lastDis + 1; curDis++) {
        if (curDis > 0) {
            int j = lower_bound(stones.begin(), stones.end(), stones[i] + curDis) - stones.begin();
            if (j != stones.size() && stones[j] == curDis + stones[i] && dfs(stones, j, curDis)) {
                return rec[i][lastDis] = true;
            }
        }
    }
    return rec[i][lastDis] = false;
}

bool canCross(vector<int>& stones) {
    int n = stones.size();
    rec.resize(n);
    return dfs(stones, 0, 0);
}

// dp
bool canCross(vector<int>& stones) {
    int n = stones.size();
    vector<vector<int>> dp(n, vector<int> (n));
    dp[0][0] = true;
    for (int i = 1; i < n; ++i) {
        if (stones[i] - stones[i - 1] > i) return false;
    }

    for (int i = 1; i < n; ++i) {
        for (int j = i - 1; j >= 0; --j) {
            int k = stones[i] - stones[j];
            if (k > j + 1) break;
            dp[i][k] = dp[j][k - 1] || dp[j][k] || dp[j][k + 1];
            if (i == n - 1 && dp[i][k]) {
                return true;
            }
        }
    }
    return false;
}
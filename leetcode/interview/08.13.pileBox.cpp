#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// 超时
int res = 0;
int pileBox(vector<vector<int>>& box) {
    int n = box.size();
    vector<bool> used(n, false);
    vector<vector<int>> usedBoxes;
    dfs(box, 0, used, usedBoxes);
    return res;
}

void dfs(vector<vector<int>>& box, int height, vector<bool>& used, vector<vector<int>>& usedBoxes) {
    bool flag = false;
    int n = box.size();
    for (int i = 0; i < box.size(); i++) {
        if (usedBoxes.empty()) {
            flag = true;
            height += box[i][2];
            usedBoxes.push_back(box[i]);
            used[i] = true;
            dfs(box, height, used, usedBoxes);
            height -= box[i][2];
            usedBoxes.pop_back();
            used[i] = false;
        } else if (!used[i]) {
            auto last_box = usedBoxes.back();
            if (box[i][0] > last_box[0] && box[i][1] > last_box[1] && box[i][2] > last_box[2]) {
                flag = true;
                height += box[i][2];
                usedBoxes.push_back(box[i]);
                used[i] = true;
                dfs(box, height, used, usedBoxes);
                height -= box[i][2];
                usedBoxes.pop_back();
                used[i] = false;
            }
        }
    }
    if (!flag) {
        res = max(res, height);
        return;
    }
}


int res = 0;
int pileBox(vector<vector<int>>& box) {
    if (box.empty()) return 0;
    sort(box.begin(), box.end(), [](const vector<int>& a, const vector<int>& b)
                                    {return a[0] > b[0];});
    vector<int> last;
    dfs(box, last, 0, 0);
    return res;
}

void dfs(vector<vector<int>>& box, vector<int>& last, int n, int height) {
    // base case
    if (n == box.size()) {
        res = max(res, height);
        return;
    }

    // 选择箱子
    if (last.empty() || (box[n][0] < last[0] && box[n][1] < last[1] && box[n][2] < last[2])) { // 可以选的条件
        dfs(box, box[n], n + 1, height + box[n][2]);
    }

    // 不选择箱子
    dfs(box, last, n + 1, height);
}

// DFS超时？
// DP
int pileBox(vector<vector<int>>& box) {
    sort(box.begin(), box.end(), [](const vector<int>& a, const vector<int>& b) {return a[0] > b[0];});
    vector<int> dp(box.size(), 0);
    dp[0] = box[0][2];
    int ans = dp[0];
    for (int i = 1; i < box.size(); i++) {
        int maxh = 0;
        for (int j = 0; j < i; j++) {
            if (box[j][0] > box[i][0] && box[j][1] > box[i][1] && box[j][2] > box[i][2]) {
                maxh = max(maxh, dp[j]);
            }
        }
        dp[i] = maxh + box[i][2];
        ans = max(ans, dp[i]);
    }
    return ans;
}
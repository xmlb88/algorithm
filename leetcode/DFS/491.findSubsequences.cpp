#include <iostream>
#include <vector>
using namespace std;

// WA
vector<vector<int>> res;
vector<vector<int>> findSubsequences(vector<int>& nums) {
    vector<int> seq;
    dfs(nums, seq, 0);
    return res;
}

void dfs(vector<int>& nums, vector<int>& seq, int i) {
    // base case
    if (i == nums.size()) {
        if (seq.size() < 2) return;

        if (find(res.begin(), res.end(), seq) == res.end()) {
            res.push_back(seq);
        }
        return;
    }

    if (seq.empty() || nums[i] >= seq.back()) {
        seq.push_back(nums[i]);
        dfs(nums, seq, i + 1);
        seq.pop_back();
    }
    dfs(nums, seq, i + 1);
}


// 判断去重
vector<int> seq;
vector<vector<int>> res;
vector<vector<int>> findSubsequences(vector<int>& nums) {
    dfs(nums, 0, INT_MIN);
    return res;
}

void dfs(vector<int>& nums, int cur, int last) {
    if (cur == nums.size()) {
        if (seq.size() >= 2) {
            res.push_back(seq);
        }
        return;
    }

    if (nums[cur] >= last) {
        seq.push_back(nums[cur]);
        dfs(nums, cur + 1, nums[cur]);
        seq.pop_back();
    }

    // 在这里判断重复
    if (nums[cur] != last) {
        dfs(nums, cur + 1, last);
    }
}
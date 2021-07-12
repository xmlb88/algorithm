#include <iostream>
#include <vector>
using namespace std;

// 递归
vector<vector<int>> subsets(vector<int>& nums) {
    if (nums.size() == 0) return {{}};
    int n = nums.back();
    nums.pop_back();

    vector<vector<int>> res = subsets(nums);
    int size = res.size();
    for (int i = 0; i < size; i++) {
        vector<int> tmp = res[i];
        tmp.push_back(n);
        res.push_back(tmp);
    }

    return res;
}


// 回溯
vector<vector<int>> res;
vector<vector<int>> subsets(vector<int>& nums) {
    vector<int> track;
    backtrace(nums, 0, track);
    return res;
}

void backtrace(vector<int>& nums, int start, vector<int>& track) {
    res.push_back(track);

    for (int i = start; i < nums.size(); i++) {
        track.push_back(nums[i]);
        backtrace(nums, i + 1, track);
        track.pop_back();
    }
}

// 回溯 DFS
vector<vector<int>> res;
vector<vector<int>> subsets(vector<int>& nums) {
    vector<int> track;
    backtrace(nums, track, 0);
    return res;
}

void backtrace(vector<int>& nums, vector<int>& track, int start) {
    res.push_back(track);

    for (int i = start; i < nums.size(); i++) {
        track.push_back(nums[i]);
        backtrace(nums, track, i + 1);
        track.pop_back();
    }
}

// 递归
vector<vector<int>> subsets(vector<int>& nums) {
    if (nums.size() == 0) return {{}};
    int n = nums.back();
    nums.pop_back();

    vector<vector<int>> res = subsets(nums);
    int size = res.size();
    for (int i = 0; i < size; i++) {
        vector<int> temp = res[i];
        temp.push_back(n);
        res.push_back(temp);
    }
    return res;
}

// 二进制
vector<vector<int>> subsets(vector<int>& nums) {
    int n = nums.size();
    vectotr<vector<int>> res;
    
}


// review 2021年7月12日10:15:39

vector<vector<int>> res;
void dfs(vector<int>& nums, int i, vector<int>& track) {
    if (i == nums.size()) {
        res.push_back(track);
        return;
    }

    dfs(nums, i + 1, track);
    track.push_back(nums[i]);
    dfs(nums, i + 1, track);
    track.pop_back();
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<int> track;
    dfs(nums, 0, track);
    return res;
}


// 位运算
vector<vector<int>> subsets(vector<int>& nums) {
    int n = nums.size();
    vector<int> t;
    vector<vector<int>> res;
    for (int i = 0; i < (1 << n); ++i) {
        t.clear();
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                t.push_back(nums[j]);
            }
        }
        res.push_back(t);
    }
    return res;
}
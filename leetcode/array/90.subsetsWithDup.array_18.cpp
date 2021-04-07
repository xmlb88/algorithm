#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
using namespace std;

vector<vector<int>> res;
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<int> track;
    traceback(nums, 0, track);
    return res;
}

void traceback(vector<int>& nums, int start, vector<int>& track) {
    res.push_back(track);

    for (int i = start; i < nums.size(); i++) {
        if (i >= 1 && nums[i] == nums[i - 1]) continue;
        track.push_back(nums[i]);
        traceback(nums, i + 1, track);
        track.pop_back();
    }
}


// review 2021年3月31日09:18:07
// 递归
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    if (nums.empty()) return {{}};

    int num = nums.back();
    nums.pop_back();
    vector<vector<int>> res = subsetsWithDup(nums);
    int size = res.size();
    for (int i = 0; i < size; ++i) {
        vector<int> temp = res[i];
        temp.push_back(num);
        sort(temp.begin(), temp.end());
        if (find(res.begin(), res.end(), temp) == res.end()) {
            res.push_back(temp);
        }
    }
    return res;
}

// DFS
vector<vector<int>> res;
vector<int> vec;

void backtrack(vector<int>& nums, int index) {
    res.push_back(vec);

    for (int i = index; i < nums.size(); ++i) {
        if (i > index && nums[i] == nums[i - 1]) continue;
        vec.push_back(nums[i]);
        backtrack(nums, i + 1);
        vec.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    backtrack(nums, 0);
    return res;
}

// used数组去重
vector<vector<int>> res;
vector<int> path;

void backtrack(vector<int>& nums, int index, vector<bool>& used) {
    res.push_back(path);
    for (int i = index; i < nums.size(); ++i) {
        if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) continue; // false为同一层，true为分支
        path.push_back(nums[i]);
        used[i] = true;
        backtrack(nums, i + 1, used);
        used[i] = false;
        path.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<bool> used(nums.size(), false);
    backtrack(nums, 0, used);
    return res;
}

// set去重
vector<vector<int>> res;
vector<int> path;

void backtrack(vector<int>& nums, int index) {
    res.push_back(path);
    unordered_set<int> used;
    for (int i = index; i < nums.size(); ++i) {
        if (used.find(nums[i]) != used.end()) continue;
        used.insert(nums[i]);
        path.push_back(nums[i]);
        backtrack(nums, i + 1);
        path.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    backtrack(nums, 0);
    return res;
}

// 子集II
// review 2021年4月7日09:31:29
// DFS 重点如何去重

vector<int> vec;
vector<vector<int>> res;

void backtrack(vector<int>& nums, int index) {
    res.push_back(vec);

    for (int i = index; i < nums.size(); ++i) {
        if (i > index && nums[i] == nums[i - 1]) continue;
        vec.push_back(nums[i]);
        backtrack(nums, i + 1);
        vec.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    backtrack(nums, 0);
    return res;
}
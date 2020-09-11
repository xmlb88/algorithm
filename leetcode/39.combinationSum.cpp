#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> result;
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<int> res;
    helper(candidates, target, res, 0);
    return result;
}

void helper(vector<int>& candidates, int target, vector<int>& res, int idx) {
    if (target == 0) {
        result.push_back(res);
        return;
    }

    for (int i = idx; i < candidates.size(); i++) {
        if (target - candidates[i] < 0) continue;
        else {
            res.push_back(candidates[i]);
            helper(candidates, target - candidates[i], res, i);
            res.pop_back();
        }
    }
}

vector<vector<int>> result;
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<int> ans;
    helper(candidates, target, 0, ans);
    return result;
}

void helper(vector<int>& candidates, int target, int idx, vector<int>& ans) {
    if (idx == candidates.size()) return;

    if (target == 0) {
        result.push_back(ans);
        return;
    }

    helper(candidates, target, idx + 1, ans);

    if (target - candidates[idx] >= 0) {
        ans.push_back(candidates[idx]);
        helper(candidates, target - candidates[idx], idx, ans);
        ans.pop_back();
    }
}
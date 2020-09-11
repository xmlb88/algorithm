#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> result;
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<int> ans;
    sort(candidates.begin(), candidates.end());
    helper(candidates, target, 0, ans);
    return result;
}

void helper(vector<int>& candidates, int target, int idx, vector<int>& ans) {
    if (target == 0) {
        result.push_back(ans);
        return;
    }

    for (int i = idx; i < candidates.size(); i++) {
        if (i > idx && candidates[i] == candidates[i - 1]) continue;
        if (target - candidates[i] < 0) continue;
        ans.push_back(candidates[i]);
        helper(candidates, target - candidates[i], i + 1, ans);
        ans.pop_back();
    }
}
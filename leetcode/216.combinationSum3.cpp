#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> result;
vector<vector<int>> combinationSum3(int k, int n) {
    vector<int> ans;
    helper(k, n, ans, 1);
    return result;
}

void helper(int k, int n, vector<int>& ans, int idx) {
    if (ans.size() == k && n == 0) {
        result.push_back(ans);
        return;
    }

    for (int i = idx; i <= 9; i++) {
        if (n - i < 0) continue;

        ans.push_back(i);
        helper(k, n - i, ans, i + 1);
        ans.pop_back();
    }
}
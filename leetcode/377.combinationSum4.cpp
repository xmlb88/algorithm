#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> result;
void helper(vector<int>& nums, int target, vector<int>& ans) {
    if (target == 0) {
        // count += 1;
        result.push_back(ans);
        return;
    }

    for (int i = 0; i < nums.size(); i++) {
        if (target - nums[i] < 0) continue;
        else {
            ans.push_back(nums[i]);
            helper(nums, target - nums[i], ans);
            ans.pop_back();
        }
    }
}

int combinationSum4(vector<int>& nums, int target) {
    vector<int> ans;
    helper(nums, target, ans);
    return result.size();
}

int main() {
    vector<int> nums = {1, 2, 3};
    int target = 4;
    int answer = combinationSum4(nums, target);
    cout << answer << endl;
}

// dp Î´Íê³É

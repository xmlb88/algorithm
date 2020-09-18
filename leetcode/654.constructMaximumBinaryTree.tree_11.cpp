#include<iostream>
#include<vector>
using namespace std;

TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    return dfs(nums, 0, nums.size() - 1);
}

TreeNode* dfs(vector<int>& nums, int l, int r) {
    if (l > r) return NULL;
    int idx = l;
    for (int i = l + 1; i <= r; i++) {
        if (nums[i] > nums[idx]) idx = i;
    }

    TreeNode* root = new TreeNode(nums[idx]);
    root -> left = dfs(nums, l, idx - 1);
    root -> right = dfs(nums, idx + 1, r);
    return root;
}
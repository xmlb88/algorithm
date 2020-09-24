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
















// review

TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    return construct(nums, 0, nums.size() - 1);
}

TreeNode* construct(vector<int>& nums, int l, int r) {
    if (l > r) return NULL;
    int max = 0;
    int max_index = 0;
    for (int i = l; i <= r; i++) {
        if (nums[i] >= max) {
            max = nums[i];
            max_index = i;
        }
    }

    TreeNode* root = new TreeNode(max);
    root -> left = construct(nums, l, max_index - 1);
    root -> right = construct(nums, max_index + 1, r);
    return root;
}
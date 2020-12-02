#include <iostream>
#include <vector>
#include "tree/treeNode.h"
using namespace std;

TreeNode* sortedArrayToBST(vector<int>& nums) {
    return dfs(nums, 0, nums.size() - 1);
}

TreeNode* dfs(vector<int>& nums, int i, int j) {
    if (i > j) return nullptr;

    TreeNode* root = new TreeNode(nums[i + (j - i) / 2]);
    root -> left = dfs(nums, i, i + (j - i) / 2 - 1);
    root -> right = dfs(nums, i + (j - i) / 2 + 1, j);
    return root;
} 
#include <iostream>
#include "treeNode.h"
using namespace std;

bool hasPathSum(TreeNode* root, int sum) {
    if (root == NULL) return false;
    if (!root -> left && !root -> right && sum - root -> val == 0) return true;
    return hasPathSum(root -> left, sum - root -> val) || hasPathSum(root -> right, sum - root -> val);
}


// review 2021年5月27日17:05:04
bool hasPathSum(TreeNode* root, int sum) {
    if (!root) return false;
    sum -= root -> val;
    if (!root -> left && !root -> right && sum == 0) return true;
    return hasPathSum(root -> left, sum) || hasPathSum(root -> right, sum);
}


// 回溯
bool dfs(TreeNode* root, int sum, int preSum) {
    if (!root) return fasle;
    preSum += root -> val;
    if (!root -> left && !root -> right && preSum == sum) return true;
    bool left = dfs(root -> left, sum, preSum);
    bool right = dfs(root -> right, sum, preSum);
    return left || right;
}

bool hasPathSum(TreeNode* root, int sum) {
    return dfs(root, sum, 0);
}
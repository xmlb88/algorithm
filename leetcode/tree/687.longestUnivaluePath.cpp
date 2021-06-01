#include <iostream>
#include <vector>
#include "treeNode.h"
using namespace std;

int max_path = 0;
int longestUnivaluePath(TreeNode* root) {
    dfs(root);
    return max_path;
}

int dfs(TreeNode* root) {
    if (!root) return 0;
    if (!root -> left && !root -> right) return 0;

    int left = dfs(root -> left);
    int right = dfs(root -> right);

    int left_value, right_value;
    if (root -> left && root -> left -> val == root -> val) {
        left_value = left + 1;
    } else left_value = 0;

    if (root -> right && root -> right -> val == root -> val) {
        right_value = right + 1;
    } else right_value = 0;

    max_path = max(max_path, left_value + right_value);
    return max(left_value, right_value);
}
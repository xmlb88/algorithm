#include <iostream>
#include <vector>
#include "tree/treeNode.h"
using namespace std;

int res = INT_MIN;
int maxPathSum(TreeNode* root) {
    nodeSum(root);
    return res;
}

int nodeSum(TreeNode* root) {
    if (!root) return 0;

    int left = nodeSum(root -> left);
    int right = nodeSum(root -> right);
    res = max(res, left + right + root -> val);
    return max(left, right) + root -> val;
}
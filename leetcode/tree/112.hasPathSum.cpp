#include <iostream>
#include "treeNode.h"
using namespace std;

bool hasPathSum(TreeNode* root, int sum) {
    if (root == NULL) return false;
    if (!root -> left && !root -> right && sum - root -> val == 0) return true;
    return hasPathSum(root -> left, sum - root -> val) || hasPathSum(root -> right, sum - root -> val);
}
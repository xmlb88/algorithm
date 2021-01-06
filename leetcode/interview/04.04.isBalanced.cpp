#include <iostream>
#include "tree/treeNode.h"
using namespace std;

bool res = true;
bool isBalanced(TreeNode* root) {
    height(root);
    return res;
}

int height(TreeNode* root) {
    if (!root) return 0;

    int left = height(root -> left);
    int right = height(root -> right);
    if (abs(left - right) > 1) res = false;
    return max(left, right) + 1;
}
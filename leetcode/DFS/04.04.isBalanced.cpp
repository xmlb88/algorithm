#include <iostream>
#include "tree/treeNode.h"
using namespace std;

bool res = true;
bool isBalanced(TreeNode* root) {
    hight(root);
    return res;
}

int hight(TreeNode* root) {
    if (root == nullptr) return 0;

    int left = hight(root -> left);
    int right = hight(root -> right);
    res = res && abs(left - right) <= 1;
    return max(left, right) + 1;
}
#include <iostream>
#include <vector>
#include "treeNode.h"
using namespace std;

TreeNode* pruneTree(TreeNode* root) {
    return hasOneDFS(root) ? root : nullptr;
}

bool hasOneDFS(TreeNode* root) {
    if (!root) return false;
    
    bool left = hasOneDFS(root -> left);
    bool right = hasOneDFS(root -> right);

    if (!left) root -> left = nullptr;
    if (!right) root -> right = nullptr;

    return root -> val == 1 || left || right;
}
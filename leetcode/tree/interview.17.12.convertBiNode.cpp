#include <iostream>
#include <vector>
#include "treeNode.h"
using namespace std;

TreeNode* dummy = new TreeNode(0);
TreeNode* cur = dummy;
TreeNode* convertBiNode(TreeNode* root) {
    convertB(root);
    return dummy -> right;
}

void convertB(TreeNode* root) {
    if (root == NULL) return;

    convertB(root -> left);
    root -> left = NULL;
    cur -> right = root;
    cur = root;
    convertB(root -> right);
}
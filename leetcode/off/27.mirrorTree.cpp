#include <iostream>
#include "treeNode.h"
using namespace std;

TreeNode* mirrorTree(TreeNode* root) {
    if (root == NULL) return NULL;

    mirrorTree(root -> left);
    mirrorTree(root -> right);
    swap(root -> left, root -> right);
    return root;
}
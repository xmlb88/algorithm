#include <iostream>
#include "treeNode.h"
using namespace std;

void flatten(TreeNode* root) {
    // base case
    if (root == NULL) return;

    flatten(root -> left);
    flatten(root -> right);

    /*****后序遍历位置*****/
    // 1.左右子树已经被拉平成一条链表
    TreeNode* left = root -> left;
    TreeNode* right = root -> right;

    // 2.将左子树作为右子树
    root -> left = NULL;
    root -> right = left;

    // 3.将原先的右子树接到当前右子树末端
    TreeNode* p = root;
    while (p -> right != NULL) {
        p = p -> right;
    }
    p -> right = right;
}
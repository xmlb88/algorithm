#include <iostream>
#include "tree/treeNode.h"
using namespace std;

// BST + ตÝน้
TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    if (root == nullptr || p == nullptr) return nullptr;
    if (p -> val >= root -> val) {
        return inorderSuccessor(root -> right, p);
    } else {
        TreeNode* left = inorderSuccessor(root -> left, p);
        return left ? left : root;
    }
}
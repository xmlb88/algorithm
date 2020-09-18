#include<iostream>

using namespace std;

TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (root == NULL) {
        TreeNode* node = new TreeNode(val);
        return node;
    }

    if (root -> val < val) root -> right = insertIntoBST(root -> right, val);
    if (root -> val > val) root -> left = insertIntoBST(root -> left, val);
    return root;
}

TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (root == NULL) {
        TreeNode* node = new TreeNode(val);
        return node;
    }

    TreeNode* parent;
    TreeNode* cur = root;
    while (cur != NULL) {
        parent = cur;
        if (cur -> val > val) cur = cur -> left;
        else cur = cur -> right;
    }

    TreeNode* node = new TreeNode(val);
    if (parent -> val > val) parent -> left = node;
    else parent -> right = node;

    return root;
}
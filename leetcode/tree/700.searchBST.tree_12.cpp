#include<iostream>
#include<queue>
using namespace std;

TreeNode* searchBST(TreeNode* root, int val) {
    if (root == NULL) return NULL;
    if (root -> val == val) return root;
    else if (root -> val > val) return searchBST(root -> left, val);
    else if (root -> val < val) return searchBST(root -> right, val);

    return NULL;
}

TreeNode* searchBST(TreeNode* root, int val) {
    while (root != NULL) {
        if (root -> val < val) root = root -> right;
        else if (root -> val > val) root = root -> left;
        else if (root -> val == val) return root;
    }

    return NULL;
}
#include<iostream>
#include<vector>
using namespace std;

TreeNode* increasingBST(TreeNode* root) {
    vector<int> result;
    inorder(root, result);
    return makeTree(result);
}

TreeNode* makeTree(vector<int> result) {
    TreeNode* root;
    TreeNode* parent;
    for (int i = 0; i < result.size(); i++) {
        TreeNode* node = new TreeNode(result[i]);
        if (i == 0) {
            root = node;
            parent = node;
        }
        else {
            parent -> right = node;
            parent = node;
        }
    }
    return root;
}

void inorder(TreeNode* root, vector<int>& result) {
    if (root == NULL) return;
    inorder(root -> left, result);
    result.push_back(root -> val);
    inorder(root -> right, result);
}
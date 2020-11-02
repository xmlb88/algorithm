#include <iostream>
#include "treeNode.h"
#include <iostream>
using namespace std;

// ÖÐÐò±éÀú
int kthSmallest(TreeNode* root, int k) {
    vector<int> res;
    inorder(root, res);
    return res[k - 1];
}

void inorder(TreeNode* root, vector<int>& res) {
    if (root == nullptr) return;

    inorder(root -> left, res);
    res.push_back(root -> val);
    inorder(root -> right, res);
}

// another
int res = 0;
int rank = 0;
int kthSmallest(TreeNode* root, int k) {
    traversal(root, k);
    return res;
}

void traversal(TreeNode* root, int k) {
    if (root == nullptr) return;

    traversal(root -> left, k);
    rank++;
    if (rank == k) {
        res = root -> val;
        return;
    }
    traversal(root -> right, k);
}
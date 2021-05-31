#include <iostream>
#include <vector>
#include "treeNode.h"
using namespace std;

int successor(TreeNode* root) {
    root = root -> right;
    while (root -> left) root = root -> left;
    return root -> val;
}

int predecessor(TreeNode* root) {
    root = root -> left;
    while (root -> right) root = root -> right;
    return root -> val;
}

TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) return nullptr;

    if (key > root -> val) root -> right = deleteNode(root -> right, key);
    else if (key < root -> val) root -> left = deleteNode(root -> left, key);
    else {
        if (!root -> left && !root -> right) root = nullptr;
        else if (root -> right) {
            root -> val = successor(root);
            root -> right = deleteNode(root -> right, root -> val);
        } else {
            root -> val = predecessor(root);
            root -> left = deleteNode(root -> left, root -> val);
        }
    }
    return root;
}

// 2次递归，删除节点后合并子树
TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) return nullptr;

    if (root -> val == key) return insert(root -> left, root -> right);

    if (key > root -> val) root -> right = deleteNode(root -> right, key);
    else if (key < root -> val) root -> left = deleteNode(root -> left, key);

    return root;
}

// 左右子树合并 (右子树向左子树合并)
TreeNode* insert(TreeNode* left, TreeNode* right) {
    if (!left) return right;
    if (!right) return left;

    if (right -> val > left -> val) {
        left -> right = insert(left -> right, right);
    } else if (right -> val < left -> val) {
        left -> left = insert(left -> left, right);
    }
    return left;
}


// https://leetcode-cn.com/problems/delete-node-in-a-bst/solution/miao-dong-jiu-wan-shi-liao-by-terry2020-tc0o/
//

TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) return nullptr;
    if (key > root -> val) root -> right = deleteNode(root -> right, key);
    else if (key < root -> val) root -> left = deleteNode(root -> left, key);
    else {
        if (!root -> left) return root -> right;
        if (!root -> right) return root -> left;

        TreeNode* node = root -> right;
        while (node -> left) node = node -> left;
        node -> left = root -> left;
        root = root -> right;
    }
    return root;
}
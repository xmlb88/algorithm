#include<iostream>
using namespace std;

// ���µݹ�
bool isBalanced(TreeNode* root) {
    if (root == NULL) return true;
    return abs(getNode(root -> left) - getNode(root -> right)) <= 1
    && isBalanced(root -> left) && isBalanced(root -> right);
}

int getNode(TreeNode* root) {
    if (root == NULL) return 0;
    return max(getNode(root -> left), getNode(root -> right)) + 1;
}

// ���ϵݹ�

bool isBalanced(TreeNode* root) {
    return height(root) >= 0;
}

int height(TreeNode* root) {
    if (root == NULL) return 0;
    int left = height(root -> left);
    if (left == -1) return -1;
    int right = height(root -> right);
    if (right == -1) return -1;
    if (abs(left - right) > 1) return -1;
    return max(left, right) + 1;
}
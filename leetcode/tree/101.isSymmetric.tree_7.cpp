#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

// µÝ¹é
bool isSymmetric(TreeNode* root) {
    if (root == NULL) return true;
    return compare(root -> left, root -> right);
}

bool compare(TreeNode* left, TreeNode* right) {
    if (left == NULL && right != NULL) return false;
    else if (left != NULL && right == NULL) return false;
    else if (left == NULL && right == NULL) return true;
    else if (left -> val != right -> val) return false;
    else return compare(left -> left, right -> right) && compare(left -> right, right -> left);
}

// µü´ú
bool isSymmetric(TreeNode* root) {
    if (root == NULL) return true;
    queue<TreeNode*> que;
    que.push(root -> left);
    que.push(root -> right);
    while (!que.empty()) {
        TreeNode* leftNode = que.front();
        que.pop();
        TreeNode* rightNode = que.front();
        que.pop();
        if (!leftNode && !rightNode) continue;
        if (!leftNode || !rightNode || leftNode -> val != rightNode -> val) return false;
        que.push(leftNode -> left);
        que.push(rightNode -> right);
        que.push(leftNode -> right);
        que.push(rightNode -> left);
    }
    return true;
}


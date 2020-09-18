#include<iostream>
#include<queue>
using namespace std;

TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    if (t1 == NULL && t2 == NULL) return NULL;
    else if (t1 == NULL && t2 != NULL) return t2;
    else if (t1 != NULL && t2 == NULL) return t1;
    else {
        TreeNode* node = new TreeNode(t1 -> val + t2 -> val);
        node -> left = mergeTrees(t1 -> left, t2 -> left);
        node -> right = mergeTrees(t1 -> right, t2 -> right);
        return node;
    }
}

TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    if (t1 == NULL) return t2;
    if (t2 == NULL) return t1;
    t1 -> val += t2 -> val;
    t1 -> left = mergeTrees(t1 -> left, t2 -> left);
    t1 -> right = mergeTrees(t1 -> right, t2 -> right);
    return t1;
}

TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    if (t1 == NULL) return t2;
    if (t2 == NULL) return t1;
    queue<TreeNode*> que;
    que.push(t1);
    que.push(t2);
    while (!que.empty()) {
        TreeNode* node1 = que.front();
        que.pop();
        TreeNode* node2 = que.front();
        que.pop();
        node1 -> val += node2 -> val;
        if (node1 -> left && node2 -> left) {
            que.push(node1 -> left);
            que.push(node2 -> left);
        }
        if (node1 -> right && node2 -> right) {
            que.push(node1 -> right);
            que.push(node2 -> right);
        }
        if (!node1 -> left && node2 -> left) {
            node1 -> left = node2 -> left;
        }
        if (!node1 -> right && node2 -> right) {
            node1 -> right = node2 -> right;
        }
    }
    return t1;
}
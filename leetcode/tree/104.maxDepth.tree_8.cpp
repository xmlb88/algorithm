#include<iostream>
using namespace std;

// �ݹ� DFS
int maxDepth(TreeNode* root) {
    if (root == NULL) return 0;
    return max(maxDepth(root -> left) + 1, maxDepth(root -> right) + 1);
}

// ���� BFS
int maxDepth(TreeNode* root) {
    int ans = 0;
    queue<TreeNode*> que;
    if (root != NULL) que.push(root);
    while (!que.empty()) {
        int size = que.size();
        for (int i = 0; i < size; i++) {
            TreeNode* node = que.front();
            que.pop();
            if (node -> left) que.push(node -> left);
            if (node -> right) que.push(node -> right);
        }
        ans++;
    }
    return ans;
}

// review
int maxDepth(TreeNode *root) {
    if (!root) return 0;
    return max(maxDepth(root -> left), maxDepth(root -> right)) + 1;
}

int maxDepth(TreeNode* root) {
    int res = 0;
    queue<TreeNode*> q;
    if (root) q.push(root);
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            TreeNode* node = q.front();
            q.pop();
            if (node -> left) q.push(node -> left);
            if (node -> right) q.push(node -> right);
        }
        ++res;
    }
    return res;
}
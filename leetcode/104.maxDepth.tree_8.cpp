#include<iostream>
using namespace std;

// µÝ¹é DFS
int maxDepth(TreeNode* root) {
    if (root == NULL) return 0;
    return max(maxDepth(root -> left) + 1, maxDepth(root -> right) + 1);
}

// µü´ú BFS
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
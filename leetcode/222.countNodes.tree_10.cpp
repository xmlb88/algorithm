#include<iostream>
#include<queue>
using namespace std;

// 递归
int countNodes(TreeNode* root) {
    if (root == NULL) return 0;
    return countNodes(root -> left) + countNodes(root -> right) + 1;
}

// 迭代
int countNodes(TreeNode* root) {
    int ans = 0;
    queue<TreeNode*> que;
    if (root != NULL) que.push(root);
    while (!que.empty()) {
        int size = que.size();
        ans += size;
        for (int i = 0; i < size; i++) {
            TreeNode* node = que.front();
            que.pop();
            if (node -> left) que.push(node -> left);
            if (node -> right) que.push(node -> right);
        }
    }
    return ans;
}

// 二分查找
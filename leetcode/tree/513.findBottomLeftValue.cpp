#include <iostream>
#include <vector>
#include <queue>
#include "treeNode.h"
using namespace std;

int findBottomLeftValue(TreeNode* root) {
    vector<int> res;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        res.clear();
        for (int i = 0; i < size; ++i) {
            TreeNode* node = q.front();
            q.pop();
            res.push_back(node -> val);
            if (node -> left) q.push(node -> left);
            if (node -> right) q.push(node -> right);
        }
    }
    return res[0];
}

// DFS Ç°Ðò±éÀú
int maxDepth = -1, val = 0;
int findBottomLeftValue(TreeNode* root) {
    dfs(root, 0);
    return val;
}

void dfs(TreeNode* root, int depth) {
    if (!root) return;
    if (depth > maxDepth) {
        val = root -> val;
        maxDepth = depth;
    }
    dfs(root -> left, depth + 1);
    dfs(root -> right, depth + 1);
}

// BFS
int findBottomLeftValue(TreeNode* root) {
    int res = 0;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        res = q.front() -> val;
        for (int i = 0; i < size; ++i) {
            TreeNode* node = q.front();
            q.pop();
            if (node -> left) q.push(node -> left);
            if (node -> right) q.push(node -> right);
        }
    }
    return res;
}

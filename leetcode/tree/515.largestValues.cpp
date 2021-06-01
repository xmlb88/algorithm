#include <iostream>
#include <vector>
#include <queue>
#include "treeNode.h"
using namespace std;

vector<int> largestValues(TreeNode* root) {
    vector<int> res;
    queue<TreeNode*> q;
    if (root) q.push(root);
    while (!q.empty()) {
        int size = q.size();
        int max_value = INT_MIN;
        for (int i = 0; i < size; ++i) {
            TreeNode* node = q.front();
            q.pop();
            max_value = max(max_value, node -> val);
            if (node -> left) q.push(node -> left);
            if (node -> right) q.push(node -> right);
        }
        res.push_back(max_value);
    }
    return res;
}


void dfs(TreeNode* root, vector<int>& res, int level) {
    if (!root) return;
    if (res.size() == level) res.push_back(root -> val);
    else res[level] = max(res[level], root -> val);
    dfs(root -> left, res, level + 1);
    dfs(root -> right, res, level + 1);
}

vector<int> largestValues(TreeNode* root) {
    vector<int> res;
    dfs(root, res, 0);
    return res;
}
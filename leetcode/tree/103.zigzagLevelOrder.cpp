#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include "treeNode.h"
using namespace std;

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    if (!root) return {};
    queue<TreeNode*> q;
    q.push(root);
    vector<vector<int>> res;
    int level = 0;
    while (!q.empty()) {
        int size = q.size();
        vector<int> level_vec;
        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();
            level_vec.push_back(node -> val);
            if (node -> left) q.push(node -> left);
            if (node -> right) q.push(node -> right);
        }
        if (level & 1) reverse(level_vec.begin(), level_vec.end());
        res.push_back(level_vec);
        level++;
    }
    return res;
}
#include <iostream>
#include <vector>
#include <queue>
#include "treeNode.h"
using namespace std;

vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> res;
    if (!root) return res;
    queue<TreeNode*> que;
    que.push(root);
    while (!que.empty()) {
        int size = que.size();
        vector<int> vec;
        for (int i = 0; i < size; i++) {
            TreeNode* node = que.front();
            que.pop();
            vec.push_back(node -> val);
            if (node -> left) que.push(node -> left);
            if (node -> right) que.push(node -> right);
        }
        res.push_back(vec);
    }
    reverse(res.begin(), res.end());
    return res;
}
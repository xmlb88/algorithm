#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (!root) return res;
    queue<TreeNode*> q;
    q.push(root);
    int level = 0;
    while (!q.empty()) {
        int sz = q.size();
        vector<int> vec;
        for (int i = 0;  i < sz; i++) {
            TreeNode* node = q.front();
            q.pop();
            vec.push_back(node -> val);
            if (node -> left) q.push(node -> left);
            if (node -> right) q.push(node -> right);
        }
        if (level % 2 == 1) reverse(vec.begin(), vec.end());
        res.push_back(vec);
        level++;
    }
    return res;
}
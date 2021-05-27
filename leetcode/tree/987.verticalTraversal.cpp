#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include "treeNode.h"
using namespace std;

map<int, multiset<pair<int, int>>> mp;
vector<vector<int>> verticalTraversal(TreeNode* root) {
    dfs(root, 0, 0);
    vector<vector<int>> res;
    for (auto& [_, st] : mp) {
        vector<int> colorder;
        for (auto& [_, val] : st) {
            colorder.push_back(val);
        }
        res.push_back(colorder);
    }
    return res;
}

void dfs(TreeNode* root, int row, int col) {
    if (!root) return;
    mp[col].insert(make_pair(row, root -> val));
    dfs(root -> left, row + 1, col - 1);
    dfs(root -> right, row + 1, col + 1);
}


// BFS 
vector<vector<int>> verticalTraversal(TreeNode* root) {
    map<int, multiset<pair<int, int>>> mp;
    queue<pair<TreeNode*, int>> q;
    int row = 0;
    if (root) q.push(make_pair(root, 0));
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            TreeNode* node = q.front().first;
            int col = q.front().second;
            q.pop();
            mp[col].insert(make_pair(row, node -> val));
            if (node -> left) q.push(make_pair(node -> left, col - 1));
            if (node -> right) q.push(make_pair(node -> right, col + 1));
        }
        ++row;
    }

    vector<vector<int>> res;
    for (auto& [_, st] : mp) {
        vector<int> v;
        for (auto& [_, val] : st) {
            v.push_back(val);
        }
        res.push_back(v);
    }
    return res;
}
#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include "tree/treeNode.h"
using namespace std;

vector<int> path;
vector<vector<int>> res;
vector<vector<int>> BSTSequences(TreeNode* root) {
    if (!root) return {{}};
    deque<TreeNode*> dq;
    dq.push_back(root);
    dfs(dq);
    return res;
}

void dfs(deque<TreeNode*>& dq) {
    // base case
    if (dq.empty()) {
        res.push_back(path);
        return;
    }

    int size = dq.size();
    for (int i = 0; i < size; i++) {
        TreeNode* node = dq.front();
        dq.pop_front();
        
        // 将当前值加入path
        path.push_back(node -> val);

        // 将当前节点的子节点加入选择节点
        if (node -> left) dq.push_back(node -> left);
        if (node -> right) dq.push_back(node -> right);

        // 下一轮递归
        dfs(dq);

        // 回溯选择列表
        if (node -> left) dq.pop_back();
        if (node -> right) dq.pop_back();
        // 把加入的子节点pop出后，还要将当前节点重新加入选择列表
        dq.push_back(node);

        // 回溯path
        path.pop_back();
    }
}
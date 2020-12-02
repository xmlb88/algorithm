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
        
        // ����ǰֵ����path
        path.push_back(node -> val);

        // ����ǰ�ڵ���ӽڵ����ѡ��ڵ�
        if (node -> left) dq.push_back(node -> left);
        if (node -> right) dq.push_back(node -> right);

        // ��һ�ֵݹ�
        dfs(dq);

        // ����ѡ���б�
        if (node -> left) dq.pop_back();
        if (node -> right) dq.pop_back();
        // �Ѽ�����ӽڵ�pop���󣬻�Ҫ����ǰ�ڵ����¼���ѡ���б�
        dq.push_back(node);

        // ����path
        path.pop_back();
    }
}
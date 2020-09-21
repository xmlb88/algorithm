#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> rightSideView(TreeNode* root) {
    vector<int> result;
    queue<TreeNode*> que;
    if (root != NULL) que.push(root);
    while (!que.empty()) {
        int size = que.size();
        for (int i = 0; i < size; i++) {
            TreeNode* node = que.front();
            que.pop();
            if (i == size - 1) {
                result.push_back(node -> val);
            }
            if (node -> left) que.push(node -> left);
            if (node -> right) que.push(node -> right);
        }
    }

    return result;
}

vector<int> rightSideView(TreeNode* root) {
    vector<int> res;
    helper(root, 0, res);
    return res;
}

void helper(TreeNode* root, int level, vector<int>& res) {
    if (!root) return;
    if (res.size() == level) res.push_back(root -> val);
    helper(root -> right, level + 1, res);
    helper(root -> left, level + 1, res);
}